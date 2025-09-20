#include "char.h"
#include "item.h"
#include "weapon.h"
#include "armor.h"
#include <iostream>

int init_items(void) {
    auto cloth_hood = std::make_unique<Armor>(
            ItemID::ClothHood,
            "Cloth Hood",
            2.0f,
            ArmorClass::LightArmor,
            ArmorType::Head,
            1,
            1.0f,
            std::vector<Ability>{} 
        ); 
    auto cloth_robe = std::make_unique<Armor>(
            ItemID::ClothRobe,
            "Cloth Robe",
            2.0f,
            ArmorClass::LightArmor,
            ArmorType::Chest,
            2,
            1.0f,
            std::vector<Ability>{ Ability::IronSkin } 
        ); 
    auto cloth_sash = std::make_unique<Armor>(
            ItemID::ClothSash,
            "Cloth Sash",
            2.0f,
            ArmorClass::LightArmor,
            ArmorType::Waist,
            1,
            1.0f,
            std::vector<Ability>{} 
        ); 
    auto cloth_trousers = std::make_unique<Armor>(
            ItemID::ClothTrousers,
            "Cloth Trousers",
            2.0f,
            ArmorClass::LightArmor,
            ArmorType::Legs,
            2,
            1.0f,
            std::vector<Ability>{} 
        ); 
    
    auto cloth_sandals = std::make_unique<Armor>(
            ItemID::ClothSandals,
            "Cloth Sandals",
            2.0f,
            ArmorClass::LightArmor,
            ArmorType::Feet,
            1,
            1.0f,
            std::vector<Ability>{} 
        );

    auto oldbroadaxe = std::make_unique<Weapon>(
            ItemID::OldBroadAxe,
            "Battle Axe",
            12.0f,
            WeaponType::BattleAxe,
            Handling::TwoHanded,
            DamageType::Slashing,
            25
        );

    auto oldbroadaxe = std::make_unique<Weapon>(
            ItemID::OldBroadAxe,
            "Battle Axe",
            12.0f,
            WeaponType::BattleAxe,
            Handling::TwoHanded,
            DamageType::Slashing,
            25
        );    
    return 0;  
}

int main() {
    try { 
        auto oldbroadaxe = std::make_unique<Weapon>(
            ItemID::OldBroadAxe,
            "Battle Axe",
            12.0f,
            WeaponType::BattleAxe,
            Handling::TwoHanded,
            DamageType::Slashing,
            25
        );
        
        auto cloth_robe = std::make_unique<Armor>(
            ItemID::ClothRobe,
            "Cloth Robe",
            2.0f,
            ArmorClass::LightArmor,
            ArmorType::Chest,
            2,
            1.0f,
            std::vector<Ability>{ Ability::IronSkin } 
        ); 
        init_items();
        Character player("Alice", "Warrior", 5, 10);
        player.equip_weapon(std::move(oldbroadaxe), WeaponSlot::MainHand);
        player.equip_armor(std::move(cloth_robe), ArmorType::Chest);
        player.print_info();
        player.print_equipment();
        player.print_inventory();
        player.print_spell_list();
        player.move(3, -2);
        std::cout << "printing info" << std::endl;
        player.print_info();
        printf("Info Printed\n");
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
    