// weapon.cpp
#include "weapon.h"

Weapon::Weapon(const std::string& name,
               WeaponType type,
               int base_damage,
               int weight,
               float rarity_mod)
{
    this->name = name;
    this->type = type;
    this->damage = base_damage;
    this->weight = weight;
    this->base_damage = base_damage;
    this->rarity_mod = rarity_mod;
    // scaling is default-initialized
}


int Weapon::get_damage() const {
    // simple example: base_damage * rarity_mod rounded to int
    return static_cast<int>(base_damage * rarity_mod);
}

void Weapon::print_info() const {
    std::cout << "Weapon: " << name
              << " | Type: " << type
              << " | Base DMG: " << base_damage
              << " | Weight: " << weight
              << " | Rarity: " << rarity_mod
              << "\n";
}

void Weapon::print_info() const {
    std::cout << "Weapon: " << name
              << " | Type: ";

    switch (type) {
        case WeaponType::Sword:   std::cout << "Sword"; break;
        case WeaponType::Dagger:  std::cout << "Dagger"; break;
        case WeaponType::Axe:     std::cout << "Axe"; break;
        case WeaponType::Bow:     std::cout << "Bow"; break;
        case WeaponType::Staff:   std::cout << "Staff"; break;
        case WeaponType::Polearm: std::cout << "Polearm"; break;
        default:                  std::cout << "Unknown"; break;
    }

    std::cout << " | Base DMG: " << base_damage
              << " | Weight: " << weight
              << " | Rarity: " << rarity_mod
              << "\n";