#include "armor.h"

Armor::Armor(const std::string& name, float weight, 
         ArmorClass armor_class, ArmorType armor_type,
         int base_defense, float rarity_mod = 1.0f, int attribute_bonuses)
{
    this->name         = name;
    this->armor_type   = armor_type;
    this->armor_class  = armor_class;
    this->weight       = weight;
    this->base_defense = base_defense;
    this->rarity_mod   = rarity_mod;
    // scaling is default-initialized
};