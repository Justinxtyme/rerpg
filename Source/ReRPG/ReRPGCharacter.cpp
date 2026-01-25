// Copyright Epic Games, Inc. All Rights Reserved.

#include "ReRPGCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "ReRPG.h"
#include <entt/entt.hpp>
#include "component.h"
#include "ResourceBridge.h"
#include "TransformBridge.h"
#include "InventoryData.h"
//#include "itemfactory.h"
#include "Progression.h"
#include "Attributes.h"
#include "EntityManager/Public/EntityManagerSubsystem.h"

AReRPGCharacter::AReRPGCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Create the Inventory component as a default subobject
	InventoryComponent = CreateDefaultSubobject<UInventoryAuthoringComponent>(TEXT("InventoryComponent"));

    // Create the ResourcesComponent as a default subobject
    ResourcesComponent = CreateDefaultSubobject<UResourcesComponent>(TEXT("ResourcesComponent"));

    // Optionally set defaults here
    ResourcesComponent->HP    = 100.0f;
    ResourcesComponent->SP    = 100.0f;
    ResourcesComponent->MP    = 100.0f;
    ResourcesComponent->MaxHP = 100.0f;
    ResourcesComponent->MaxSP = 100.0f;
    ResourcesComponent->MaxMP = 100.0f;

	// Create the ResourcesComponent as a default subobject
	AttributesComponent = CreateDefaultSubobject<UAttributesComponent>(TEXT("AttributesComponent"));

	//Default Set these for now
	AttributesComponent->Strength = 15;
	AttributesComponent->Dexterity = 15;
	AttributesComponent->Endurance = 18;
	AttributesComponent->BaseSpeed = 24;
	AttributesComponent->Intelligence = 30;
	AttributesComponent->Light = 5;
	AttributesComponent->Dark = 22;
	AttributesComponent->Luck = 13;
	AttributesComponent->Focus = 14;
	AttributesComponent->Presence = 15;

	// Create the ResourcesComponent as a default subobject
	CurrentProgress = CreateDefaultSubobject<UProgressionComponent>(TEXT("ProgressionComponent"));
	
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AReRPGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AReRPGCharacter::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AReRPGCharacter::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AReRPGCharacter::Look);

		// Combo Attack
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AReRPGCharacter::AttackPressed);

		// Combo Attack
		EnhancedInputComponent->BindAction(ComboAttackAction, ETriggerEvent::Started, this, &AReRPGCharacter::ComboAttackPressed);

		// Charged Attack
		EnhancedInputComponent->BindAction(ChargedAttackAction, ETriggerEvent::Started, this, &AReRPGCharacter::ChargedAttackPressed);
		EnhancedInputComponent->BindAction(ChargedAttackAction, ETriggerEvent::Completed, this, &AReRPGCharacter::ChargedAttackReleased);
	}
	else
	{
		UE_LOG(LogReRPG, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AReRPGCharacter::DoComboAttackStart()
{
	// are we already playing an attack animation?
	if (bIsAttacking)
	{
		// cache the input time so we can check it later
		CachedAttackInputTime = GetWorld()->GetTimeSeconds();

		return;
	}

	// perform a combo attack
	ComboAttack();
}

void AReRPGCharacter::DoComboAttackEnd()
{
	// stub
}

void AReRPGCharacter::DoChargedAttackStart()
{
	// raise the charging attack flag
	bIsChargingAttack = true;

	if (bIsAttacking)
	{
		// cache the input time so we can check it later
		CachedAttackInputTime = GetWorld()->GetTimeSeconds();

		return;
	}

	ChargedAttack();
}


void AReRPGCharacter::Attack()
{
	
	UE_LOG(LogTemp, Warning, TEXT("Attack() called"));
	
	bIsAttacking = true;

	// play the attack montage
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		
		const float MontageLength = AnimInstance->Montage_Play(AttackMontage, 1.0f, EMontagePlayReturnType::MontageLength, 0.0f, true);

		// subscribe to montage completed and interrupted events
		if (MontageLength > 0.0f)
		{
			// set the end delegate for the montage
			AnimInstance->Montage_SetEndDelegate(OnAttackMontageEnded, AttackMontage);
		}
	}
	
}

void AReRPGCharacter::DoAttack()
{
	// if (bIsAttacking)
	// {
	// 	CachedAttackInputTime = GetWorld()->GetTimeSeconds();
	//
	// 	return;
	// }

	Attack();
}

void AReRPGCharacter::AttackPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("AttackPressed() called"));
	DoAttack();
}


void AReRPGCharacter::DoChargedAttackEnd()
{
	// lower the charging attack flag
	bIsChargingAttack = false;

	// if we've done the charge loop at least once, release the charged attack right away
	if (bHasLoopedChargedAttack)
	{
		CheckChargedAttack();
	}
}


void AReRPGCharacter::ComboAttackPressed()
{
	// route the input
	DoComboAttackStart();
}

void AReRPGCharacter::ChargedAttackPressed()
{
	// route the input
	DoChargedAttackStart();
}

void AReRPGCharacter::ChargedAttackReleased()
{
	// route the input
	DoChargedAttackEnd();
}


void AReRPGCharacter::ComboAttack()
{
	// raise the attacking flag
	bIsAttacking = true;

	// reset the combo count
	ComboCount = 0;

	// play the attack montage
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		const float MontageLength = AnimInstance->Montage_Play(ComboAttackMontage, 1.0f, EMontagePlayReturnType::MontageLength, 0.0f, true);

		// subscribe to montage completed and interrupted events
		if (MontageLength > 0.0f)
		{
			// set the end delegate for the montage
			AnimInstance->Montage_SetEndDelegate(OnAttackMontageEnded, ComboAttackMontage);
		}
	}

}

void AReRPGCharacter::ChargedAttack()
{
	// raise the attacking flag
	bIsAttacking = true;

	// reset the charge loop flag
	bHasLoopedChargedAttack = false;

	// play the charged attack montage
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		const float MontageLength = AnimInstance->Montage_Play(ChargedAttackMontage, 1.0f, EMontagePlayReturnType::MontageLength, 0.0f, true);

		// subscribe to montage completed and interrupted events
		if (MontageLength > 0.0f)
		{
			// set the end delegate for the montage
			AnimInstance->Montage_SetEndDelegate(OnAttackMontageEnded, ChargedAttackMontage);
		}
	}
}

void AReRPGCharacter::CheckChargedAttack()
{
	// raise the looped charged attack flag
	bHasLoopedChargedAttack = true;

	// jump to either the loop or the attack section depending on whether we're still holding the charge button
	if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
	{
		AnimInstance->Montage_JumpToSection(bIsChargingAttack ? ChargeLoopSection : ChargeAttackSection, ChargedAttackMontage);
	}
}


void AReRPGCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	DoMove(MovementVector.X, MovementVector.Y);
}

void AReRPGCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void AReRPGCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void AReRPGCharacter::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AReRPGCharacter::DoJumpStart()
{
	// signal the character to jump
	UE_LOG(LogTemp, Warning, TEXT("DoJumpStart() called"));
	Jump();
}

void AReRPGCharacter::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}

void AReRPGCharacter::BeginPlay()
{
	Super::BeginPlay();

	UEntityManagerSubsystem* EntitySubsystem =
	GetWorld()->GetSubsystem<UEntityManagerSubsystem>();

	
	// Convert editor-exposed transform into ECS data
	// LTransform = UnrealTransToECS(InitialTransform);
	LResources = UnrealResToEcs(InitialResources);

	//EcsToUnrealRes2(InitialResources, ResourcesComponent);
	
	entt::entity e = EntitySubsystem->CreateEntity();

	if (UInventoryAuthoringComponent* Inv = FindComponentByClass<UInventoryAuthoringComponent>())
	{
		BuildInventoryFromDefaults(EntitySubsystem->Registry, e, Inv->Defaults, EntitySubsystem->IFactory);
	}
	EntitySubsystem->Registry.emplace<TransformComponent>(e, LTransform);
	EntitySubsystem->Registry.emplace<ResourceComponent>(e, LResources);

	// // Example: register with ECS registry
	// static entt::registry Registry;
	// auto entity = Registry.create();
	// Registry.emplace<TransformComponent>(entity, LTransform);
	// Registry.emplace<ResourceComponent>(entity, LResources);
	// Your startup logic here
	UE_LOG(LogTemp, Warning, TEXT("ReRPGCharacter BeginPlay called"));
}
