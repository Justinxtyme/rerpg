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
    
    // Equipped armor structure
    std::unordered_map<std::string, Item*> equipped_armor;
    
    // Equipped weapons structure
    std::unordered_map<std::string, Item*> equipped_weapons;

    // Static slot lists: shared among all Characters, avoids stack bloat
    static const std::vector<std::string> armor_slots;
    static const std::vector<std::string> weapon_slots;

    // Inventory structure
    std::unordered_map<std::string, std::unordered_map<std::string,int>> inventory {
        {"Consumables", {}},
        {"Weapons", {}},
        {"Armor", {}}
    };
    // Key item structure
    std::vector<std::string> key_items;

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
