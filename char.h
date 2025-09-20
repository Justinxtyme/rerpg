#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "char_classes.h"
#include "armor.h"
#include "item.h"
#include "stacker.h"
#include "weapon.h"
#include "power.h"

struct Vector2 {
    float x, y;
    Vector2(float x_val = 0, float y_val = 0) : x(x_val), y(y_val) {}
};

class Item; // forward declaration

class Character {
private:
    // Character name, class, and postion on map
    std::string name;
    std::string char_class;
    Vector2 position;
 
    //declare Health Points, Stamina points, and Magic Points
    int base_hp, max_hp, hp;
    int base_sp, max_sp, sp;
    int base_mp, max_mp, mp;

    //declare attributes
    int strength;
    int dexterity;
    int endurance;
    int base_speed;
    int luck;
    int intelligence;
    int light;
    int dark;
    int focus;
    int presence;

    //inventory and weight
    int base_carry_limit, carry_limit, equipped_weight, inventory_weight;


    //attack and defense
    int base_attack, attack, base_defense, defense;

    //Class base attribute structure
    std::unordered_map<std::string, int> attributes;
    
   
    struct Inventory {
        std::unordered_map<ItemID, int> stackables;

        // Equipped armor keyed by ArmorType
        std::unordered_map<ArmorType, std::unique_ptr<Item>> armor;

        // Equipped weapons keyed by WeaponSlot
        std::unordered_map<WeaponSlot, std::unique_ptr<Item>> weapons;

        Inventory() {
            // Armor
            armor.emplace(ArmorType::Head, nullptr);
            armor.emplace(ArmorType::Chest, nullptr);
            armor.emplace(ArmorType::Arms, nullptr);
            armor.emplace(ArmorType::Waist, nullptr);
            armor.emplace(ArmorType::Legs, nullptr);
            armor.emplace(ArmorType::Feet, nullptr);

            // Weapons
            weapons.emplace(WeaponSlot::MainHand, nullptr);
            weapons.emplace(WeaponSlot::OffHand, nullptr);
        }

        // void clear_equipment() {
        //     for (auto& [slot, item] : armor)   item.reset();
        //     for (auto& [slot, item] : weapons) item.reset();
        // }
    };

    Inventory inventory;
    
    //list for known spells
    std::vector<std::string> spell_list;

    // action log for tracking 
    std::vector<std::string> action_log;


    // // Static slot lists: shared among all Characters, avoids stack bloat
    // static const std::vector<ArmorType> armor_slots;
    // static const std::vector<WeaponType> weapon_slots;

    // EQUIPPED ITEMS
    //std::vector<std::unique_ptr<Item>> equipment; 

    // FOR QUICK EQUIPPED CHECKS
    //std::unordered_map<EquipSlot, size_t> slot_map; // maps slot → vector index

    



public:
    Character(const std::string& name, const std::string& char_class, float x = 0, float y = 0);

    void equip_weapon(std::unique_ptr<Weapon> weapon, WeaponSlot slot) {
        inventory.weapons[slot] = std::move(weapon);
    }

    void equip_armor(std::unique_ptr<Armor> armor, ArmorType armortype) {
        inventory.armor[armortype] = std::move(armor);
    }

    void print_equipment() const;

    void print_inventory() const;
    
    void print_info() const;
    
    void move(float dx, float dy);
    
    void tele(float dx, float dy); 

    void print_spell_list() const;

};

enum class Attribute {
    Strength,
    Dexterity,
    Endurance,
    Base_speed,
    Luck,
    Intelligence,
    Light,
    Dark,
    Focus,
    Presence
};