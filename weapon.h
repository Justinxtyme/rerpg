//weapon.h
#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
#include <unordered_map>
#include "item.h"


enum class WeaponType {
    Dagger,
    ShortSword,
    MediumSword,
    LongSword,
    BattleAxe,
    WarHammer,
    ShortBow, 
    LongBow,
    CrossBow
};

enum class WeaponSlot {
    MainHand,
    OffHand,
    TwoHand // useful for 2H weapons, can “block out” both slots
};

enum class Handling {
    OneHanded,
    TwoHanded
};

enum class DamageType {
    Slashing,
    Piercing,
    Blunt,
    Ranged
};

enum class Effect {
    None,
    Fire,
    Poison,
    Bleed,
    Magic
};

class Weapon: public Item {
protected:
    WeaponType  type;
    int         damage;
    Handling    handling;             // OneHanded or TwoHanded
    DamageType  dmg_type;            // Slashing, Blunt, etc.
    int         base_damage;
    float       rarity_mod;

    //stores key value pairs, eg "strength": 1.5 "dexterity": 0.7
    std::unordered_map<std::string, float> scaling;
    
    // fire, poison, etc
    std::vector<Effect> effects;   

public:
    // Basic constructor — keep simple now, fill scaling map later
    Weapon(ItemID id,
           const std::string& name,
           float weight,
           WeaponType type,
           Handling handling,
           DamageType dmg_type,
           int base_damage,
           float rarity_mod = 1.0f,
           std::vector<Effect> effects = {})
        : Item(id, name, weight),
          type(type),
          handling(handling),
          dmg_type(dmg_type),
          base_damage(base_damage),
          rarity_mod(rarity_mod),
          effects(std::move(effects)) {}
        // : Item(id, name, weight), type(type),
        //   base_damage(base_damage), rarity_mod(rarity_mod) {}

    virtual ~Weapon() = default; // must be virtual for polymorphic deletion

    // Basic API (subclasses can override)


    virtual int get_damage() const {
        return static_cast<int>(base_damage * rarity_mod);
    }

    virtual bool is_two_handed() const {
        return handling == Handling::TwoHanded;
    }

    virtual void print_weapon_info() const {
        std::cout << name << " (" << base_damage << " dmg, "
                  << (is_two_handed() ? "Two-Handed" : "One-Handed") << ")\n";
    }

};

// auto OldBroadAxe = std::make_unique<Weapon>(
//     ItemID::OldBroadAxe,
//     "Battle Axe",
//     12.0f,
//     WeaponType::BattleAxe,
//     Handling::TwoHanded,
//     DamageType::Slashing,
//     25
// );


    
#endif