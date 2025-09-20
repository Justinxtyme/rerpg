#pragma once

#include <string>
#include <unordered_map>
#include "item.h"
//#include "char.h"
#include "power.h"


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
    
    std::vector<Ability> abilities;



public:
    // // constructor
    // Armor(ItemID id, const std::string& name, float weight, ArmorClass armor_class,
    //      ArmorType armor_type, int base_defense, float rarity_mod, std::unordered_map<Attribute, int> attr_bonuses);
    Armor(ItemID id, const std::string& name, float weight,
          ArmorClass armor_class, ArmorType armor_type, int base_defense, float rarity_mod, std::vector<Ability> abilities = {})
        : Item(id, name, weight), armor_class(armor_class),
          armor_type(armor_type), base_defense(base_defense),
          rarity_mod(rarity_mod), abilities(std::move(abilities)) {}
    
    virtual ~Armor() = default;

};

