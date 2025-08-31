//weapon.h
#include <iostream>
#include <string>
#include <unordered_map>

class Weapon {
protected:
    std::string name;
    //maybe weapon_type
    std::string weapon_type;
    int damage;
    int weight;
    int base_damage;
    float rarity_mod;

    //stores key value pairs, eg "strength": 1.5 "dexterity": 0.7
    std::unordered_map<std::string, float> scaling;


public:
    // Basic constructor — keep simple now, fill scaling map later
    Weapon(const std::string& name,
           const std::string& type,
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
    virtual ~MeleeWeapon() = default;
};

class RangedWeapon : public Weapon {
    virtual ~RangedWeapon() = default;
};

class OneHandedMelee : public MeleeWeapon {
    virtual ~OneHandedMelee() = default;
};

class TwoHandedMelee : public MeleeWeapon {
    virtual ~TwoHandedMelee() = default;

};

//one handed meleee wepaons
class Dagger : public OneHandedMelee {
    
};

class ShortSword : public OneHandedMelee {

};

class MediumSword : public OneHandedMelee {

};

//two handed melee weapons
class LongSword : public TwoHandedMelee {

};

class BattleAxe : public TwoHandedMelee {

};

class WarHammer : public TwoHandedMelee {

};

//ranged weapons
class ShortBow : public RangedWeapon {

};

class LongBow : public RangedWeapon {

};

class CrossBow : public RangedWeapon {

};