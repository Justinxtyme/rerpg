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
    HealingHerb,
    StrongHealingHerb,
    ManaHerb,
    StrongManaHerb,
    StaminaHerb,

    FirePotion,
    FrostPotion,
    ShockPotion,
    Antidote,
    GreaterAntidote,
    
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
    
    ClothHood,
    ClothRobe,
    ClothSandals,
    ClothTrousers,
    ClothGloves,
    ClothSash,

    BlessedClothHood,
    BlessedClothRobe,
    BlessedClothSandals,
    BlessedClothTrousers,
    BlessedClothGloves,
    BlessedClothSash,

    SilkHood,
    SilkRobe,
    SilkSandals,
    SilkTrousers,
    SilkGloves,
    SilkSash,

    ArcaneSilkHood,
    ArcaneSilkRobe,
    ArcaneSilkSandals,
    ArcaneSilkTrousers,
    ArcaneSilkGloves,
    ArcaneSilkSash,

    MysticHood,
    MysticRobe,
    MysticSandals,
    MysticTrousers,
    MysticGloves,
    MysticSash,

    EldritchMysticHood,
    EldritchMysticRobe,
    EldritchMysticSandals,
    EldritchMysticTrousers,
    EldritchMysticGloves,
    EldritchMysticSash
    
    RustedDagger,
    RustedStraightSword,
    RustedGreatSword,
    OldBroadAxe,
    RustedFellingAxe,
    IronDagger,
    IronStraightSword,
    IronGreatsword,
    BloodStone
    
    SteelVisor,
    SteelChestplate,
    SteelBoots,
    SteelGreaves,
    SteelArmplates,
    SteelGirdle,
    
    SteelDagger,
    SteelStraightSword,
    SteelGreatsword,
    SteelBroadAxe,
    SteelFellingAxe,

    MithrilVisor,
    MithrilChestplate,
    MithrilBoots,
    MithrilGreaves,
    MithrilArmplates,
    MithrilGirdle,
    
    MithrilDagger,
    MithrilStraightSword,
    MithrilGreatsword,
    MithrilBroadAxe,
    MithrilFellingAxe,

    BoneHelm,
    BoneCuirass,
    BoneBoots,
    BoneLeggings,
    BoneVambraces,
    BoneBelt,

    AncientRelic,
    CursedAmulet,
    BlessedCharm,
    BloodAmulet,
    StoneOfFortune,
    StoneOfCurses
    
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
