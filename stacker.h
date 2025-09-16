#include "item.h"

// ITEM SUBCLASS LAYERS
class Consumable : public Item {
protected:
    std::string effect;

public:
    Consumable(ItemID id, const std::string& name, float weight, const std::string& effect);
    
    virtual ~Consumable() = default;
};


class KeyItem : public Item {
protected:
    std::string effect;

public:
    KeyItem(ItemID id, const std::string& name, float weight, const std::string& effect);
    virtual ~KeyItem() = default;
};