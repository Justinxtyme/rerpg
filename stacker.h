#include "item.h"
#include "effects.h"

// ITEM SUBCLASS LAYERS
class Consumable : public Item {
protected:
    std::vector<Effects> effects;

public:
    Consumable(ItemID id, const std::string& name, float weight, std::vector<Effects> effects = {})
    : Item(id, name, weight),
     effects(std::move(effects)) {}
    
    virtual ~Consumable() = default;
};


class KeyItem : public Item {
protected:
    std::vector<Effects> effects;

public:
    KeyItem(ItemID id, const std::string& name, float weight,std::vector<Effects> effects = {})
    : Item(id, name, weight),
     effects(std::move(effects)) {}
    
    virtual ~KeyItem() = default;
};