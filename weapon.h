//weapon.h
#include <iostream>
#include <string>
#include <unordered_map>



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

class Weapon {
protected:
    std::string name;
    WeaponType type;
    int damage;
    int weight;
    int base_damage;
    float rarity_mod;

    //stores key value pairs, eg "strength": 1.5 "dexterity": 0.7
    std::unordered_map<std::string, float> scaling;


public:
    // Basic constructor — keep simple now, fill scaling map later
    Weapon(const std::string& name,
           WeaponType type,
           int base_damage,
           int weight,
           float rarity_mod = 1.0f);

    virtual ~Weapon() = default; // must be virtual for polymorphic deletion

    // Basic API (subclasses can override)
    virtual int get_damage() const;          // compute final damage (simple for now)
    virtual void print_info() const;



};

// Weapon Subclass layers
class MeleeWeapon : public Weapon {
public:
    using Weapon::Weapon;
    virtual ~MeleeWeapon() = default;
};

class RangedWeapon : public Weapon {
public:
    using Weapon::Weapon;
    virtual ~RangedWeapon() = default;
};

class OneHandedMelee : public MeleeWeapon {
public:
    using Weapon::Weapon;
    virtual ~OneHandedMelee() = default;
};

class TwoHandedMelee : public MeleeWeapon {
public:
    using Weapon::Weapon;
    virtual ~TwoHandedMelee() = default;

};

//one handed meleee wepaons
class Dagger : public OneHandedMelee {
public:
    using OneHandedMelee::OneHandedMelee;    
};

class ShortSword : public OneHandedMelee {
public:
    using OneHandedMelee::OneHandedMelee;
};

class MediumSword : public OneHandedMelee {
public:
    using OneHandedMelee::OneHandedMelee;
};

//two handed melee weapons
class LongSword : public TwoHandedMelee {
public:
    using TwoHandedMelee::TwoHandedMelee;
};

class BattleAxe : public TwoHandedMelee {
public:
    using TwoHandedMelee::TwoHandedMelee;
};

class WarHammer : public TwoHandedMelee {
public:
    using TwoHandedMelee::TwoHandedMelee;
};

//ranged weapons
class ShortBow : public RangedWeapon {
public:
    using RangedWeapon::RangedWeapon;
};

class LongBow : public RangedWeapon {
public:
    using RangedWeapon::RangedWeapon;
};

class CrossBow : public RangedWeapon {
public:
    using RangedWeapon::RangedWeapon;
};