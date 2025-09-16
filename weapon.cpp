// weapon.cpp
#include "weapon.h"
#include "char.h"


// void Weapon::print_weapon_info() const {
//     std::cout << "Weapon: " << name
//               << " | Type: ";

//     switch (type) {
//         case WeaponType::Dagger:       std::cout << "Dagger";      break;
//         case WeaponType::ShortSword:   std::cout << "ShortSword";  break;
//         case WeaponType::MediumSword:  std::cout << "MediumSword"; break;
//         case WeaponType::LongSword:    std::cout << "LongSword";   break;
//         case WeaponType::BattleAxe:    std::cout << "BattleAxe";   break;
//         case WeaponType::WarHammer:    std::cout << "WarHammer";   break;
//         case WeaponType::ShortBow:     std::cout << "ShortBow";    break;
//         case WeaponType::LongBow:      std::cout << "LongBow";     break;
//         case WeaponType::CrossBow:     std::cout << "CrossBow";    break;
//         default:                       std::cout << "Unknown";     break;
//     }

//     std::cout << " | Base DMG: " << base_damage
//               << " | Weight: "   << weight
//               << " | Rarity: "   << rarity_mod
//               << "\n";
// }

// auto oldbroadaxe = std::make_unique<Weapon>(
//     ItemID::OldBroadAxe,
//     "Battle Axe",
//     12.0f,
//     WeaponType::BattleAxe,
//     Handling::TwoHanded,
//     DamageType::Slashing,
//     25
// );
