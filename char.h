#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "char_classes.h"

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
        std::unordered_map<ItemID, int> stackables;          // consumables, etc.
        std::unordered_map<ArmorType, std::unique_ptr<Item>> armor;
        std::unordered_map<WeaponType, std::unique_ptr<Item>> weapons;
        std::vector<ItemID> key_items;
    };



    // Static slot lists: shared among all Characters, avoids stack bloat
    static const std::vector<ArmorType> armor_slots;
    static const std::vector<WeaponType> weapon_slots;

    // EQUIPPED ITEMS
    std::vector<std::unique_ptr<Item>> equipment; 

    // FOR QUICK EQUIPPED CHECKS
    std::unordered_map<EquipSlot, size_t> slot_map; // maps slot → vector index

    
    //list for known spells
    std::vector<std::string> spell_list;

    // action log for tracking 
    std::vector<std::string> action_log;



public:
    Character(const std::string& name, const std::string& char_class, float x = 0, float y = 0);

    void print_equipment() const;

    void print_inventory() const;
    
    void print_info() const;
    
    void move(float dx, float dy);
    
    void tele(float dx, float dy); 

    void print_spell_list() const;

};
