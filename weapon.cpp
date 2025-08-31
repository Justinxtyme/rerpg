// weapon.cpp
#include "weapon.h"

Weapon::Weapon(const std::string& name,
               const std::string& type,
               int base_damage,
               int weight,
               float rarity_mod)
{
    this->name = name;
    this->weapon_type = type;
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
              << " | Type: " << weapon_type
              << " | Base DMG: " << base_damage
              << " | Weight: " << weight
              << " | Rarity: " << rarity_mod
              << "\n";
}