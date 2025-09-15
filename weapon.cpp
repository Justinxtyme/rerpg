// weapon.cpp
#include "weapon.h"




Weapon::Weapon(ItemID id, const std::string& name, float weight,
              WeaponType type, int base_damage, float rarity_mod = 1.0f)
    : Item(id, name, weight), type(type),
      base_damage(base_damage), rarity_mod(rarity_mod) 
{
    //init scaling map
}


int Weapon::get_damage() const {
    // simple example: base_damage * rarity_mod rounded to int
    return static_cast<int>(base_damage * rarity_mod);
}



void Weapon::print_info() const {
    std::cout << "Weapon: " << name
              << " | Type: ";

    switch (type) {
        case WeaponType::Dagger:       std::cout << "Dagger";      break;
        case WeaponType::ShortSword:   std::cout << "ShortSword";  break;
        case WeaponType::MediumSword:  std::cout << "MediumSword"; break;
        case WeaponType::LongSword:    std::cout << "LongSword";   break;
        case WeaponType::BattleAxe:    std::cout << "BattleAxe";   break;
        case WeaponType::WarHammer:    std::cout << "WarHammer";   break;
        case WeaponType::ShortBow:     std::cout << "ShortBow";    break;
        case WeaponType::LongBow:      std::cout << "LongBow";     break;
        case WeaponType::CrossBow:     std::cout << "CrossBow";    break;
        default:                       std::cout << "Unknown";     break;
    }

    std::cout << " | Base DMG: " << base_damage
              << " | Weight: "   << weight
              << " | Rarity: "   << rarity_mod
              << "\n";
}