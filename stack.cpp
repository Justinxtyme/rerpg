#include "stacker.h"
#include "item.h"

Consumable::Consumable(ItemID id, const std::string& name, float weight, const std::string& effect)
   : Item(id, name, weight),
     effect(effect)
{

}

KeyItem::KeyItem(ItemID id, const std::string& name, float weight, const std::string& effect)
   : Item(id, name, weight),
     effect(effect)
{

}