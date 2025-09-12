#pragma once
#include <string>


class Item {
protected:
    std::string name;
    float weight;

public:
    // Constructor
    Item(const std::string& name, float weight) : name(name), weight(weight) {}

    // Accessors
    const std::string& get_name() const { return name; }
    float get_weight() const { return weight; }

    virtual ~Item() = default;

    //basic API
};

// ITEM SUBCLASS LAYERS
class Consumable : public Item {
protected:
    std::string effect;

public:
    Consumable(const std::string& name, float weight, const std::string& effect)
        : Item(name, weight), effect(effect) {}
    
    virtual ~Consumable() = default;
};


class KeyItem : public Item {
protected:
    std::string effect;

public:
    KeyItem(const std::string& name, float weight, const std::string& effect)
        : Item(name, weight), effect(effect) {}
    virtual ~KeyItem() = default;
};



enum class ItemID {
    Potion,
    HiPotion,
    Elixir,
    // add more here
};

struct Item {
    ItemID id;
    std::string name;  // still keep human-readable
    float weight;
};
