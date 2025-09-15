#pragma once
#include <string>
#include "item.h"

enum class ArmorClass {
    LightArmor,
    MediumArmor,
    HeavyArmor
};

enum class ArmorType {
    Head,
    Chest,
    Arms,
    Waist,
    Legs,
    Feet
};


class Armor: public Item {
protected:
    ArmorClass  armor_class;
    ArmorType   armor_type;
    int         base_defense;
    float       rarity_mod;
    int         attr_bonuses; //may need to be a dictionary-like structure


public:
    // constructor
    Armor(ItemID id, const std::string& name, float weight, ArmorClass armor_class,
         ArmorType armor_type, int base_defense, float rarity_mod, int attr_bonuses);
      
    virtual ~Armor() = default;

};

