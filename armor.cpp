#include "armor.h"
#include "item.h"

Armor::Armor(ItemID id, const std::string& name, float weight,
          ArmorClass armor_class, ArmorType armor_type, int base_defense, float rarity_mod, int attr_bonuses)
        : Item(id, name, weight), armor_class(armor_class),
          armor_type(armor_type), base_defense(base_defense),
          rarity_mod(rarity_mod), attr_bonuses(attr_bonuses)
{
    // 
}