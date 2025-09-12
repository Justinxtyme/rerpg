#pragma once
#include <string>


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


class Armor {
protected:
    std::string name;
    float       weight;
    ArmorClass  armor_class;
    ArmorType   armor_type;
    int         base_defense;
    float       rarity_mod;
    int         attribute_bonuses; //may need to be a dictionary-like structure


public:
    // constructor
    Armor(const std::string& name, float weight, 
         ArmorClass armor_class, ArmorType armor_type,
         int base_defense, float rarity_mod = 1.0f, int attribute_bonuses);
      
    virtual ~Armor() = default;

};