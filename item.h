#pragma once
#include <string>
#include <vector>
#include <memory>


// Unified enum for ALL items
enum class ItemID {
    WeakPotion,
    Potion,
    PotentPotion,
    ElixirOfStrength,
    SuperElixir,
    ElixirOfDefense,
    PoisonFlask,
    LeatherHelm,
    LeatherCuirass,
    LeatherBoots,
    LeatherLeggings,
    LeatherVambraces,
    LeatherBelt,
    ReinforcedLeatherHelm,
    ReinforcedLeatherCuirass,
    ReinforcedLeatherBoots,
    ReinforcedLeatherLeggings,
    ReinforcedLeatherVambraces,
    ReinforcedLeatherBelt,
    HardenedLeatherHelm,
    HardenedLeatherCuirass,
    HardenedLeatherBoots,
    HardenedLeatherLeggings,
    HardenedLeatherVambraces,
    HardenedLeatherBelt,
    IronVisor,
    IronChestplate,
    IronBoots,
    IronGreaves,
    IronArmplates,
    IronGirdle,
    RustedDagger,
    RustedStraightSword,
    RustedGreatSword,
    OldBroadAxe,
    RustedFellingAxe,
    IronDagger,
    IronStraigtSword,
    IronGreatsword,
    BloodStone
    
    
    // ..
};

enum class EquipSlot { 
    Head, 
    Chest, 
    Legs,
    Waist, 
    Feet, 
    RightHand, 
    LeftHand 
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
