#pragma once
#include <string>


// Unified enum for ALL items
enum class ItemID {
    IronSword,
    LeatherArmor,
    WeakPotion,
    Potion,
    PotentPotion,
    ElixirOfStrength,
    SuperElixir,
    ElixirOfDefense,
    PoisonFlask
    // ...
};

class Item {
protected:
    ItemID id;
    std::string name;
    float weight;

public:
    Item(ItemID id, const std::string& name, float weight)
        : id(id), name(name), weight(weight) {}

    virtual ~Item() = default;

    ItemID get_id() const { return id; }
    const std::string& get_name() const { return name; }
    float get_weight() const { return weight; }

    // Every item should at least be able to print info
    virtual void print_info() const;
}

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


enum class ItemCategory { 
    Consumable, 
    Weapon, 
    Armor, 
    KeyItem 
};



struct Item_t {
    ItemID id;
    std::string name;  // still keep human-readable
    float weight;
};
