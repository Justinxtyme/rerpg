#include "char.h"
#include "item.h"
#include <iostream>

// Static vectors definition
const std::vector<std::string> Character::armor_slots = {"head", "chest", "waist", "legs", "feet", "arms", "right hand", "left hand"};
const std::vector<std::string> Character::weapon_slots = {"right hand", "left hand"};

// Constructor
Character::Character(const std::string& name, const std::string& char_class, float x, float y) {
    auto character_classes = load_character_classes();

    if (character_classes.find(char_class) == character_classes.end()) {
        throw std::invalid_argument("Unknown character class: " + char_class);
    }

    // load "attributes" with class defaults
    attributes = character_classes[char_class];
    
    this->name = name;
    this->char_class = char_class;
    this->position = Vector2(x, y);

    this->base_hp = 100;
    this->base_mp = 100;
    this->base_sp = 100;

    this->strength     = attributes["strength"];
    this->dexterity    = attributes["dexterity"];
    this->endurance    = attributes["endurance"];
    this->base_speed   = attributes["base_speed"];
    this->luck         = attributes["luck"];
    this->intelligence = attributes["intelligence"];
    this->light        = attributes["light"];
    this->dark         = attributes["dark"];
    this->focus        = attributes["focus"];
    this->presence     = attributes["presence"];

    this->max_hp = base_hp + static_cast<int>(strength * 0.20f);
    this->hp = max_hp;
    this->max_sp = base_sp + static_cast<int>(endurance * 0.25f);
    this->sp = max_sp;
    this->max_mp = base_mp + static_cast<int>(intelligence * 0.20f);
    this->mp = max_mp;

    this->base_attack = 1;
    this->attack = base_attack + (strength * 2) + (dexterity * 1);
    this->base_defense = 1;
    this->defense = base_defense + strength + dexterity; // + total_armor_defense


    // Initialize equipment maps with nullptr
    for (const auto& slot : armor_slots) {
        equipped_armor[slot] = nullptr;
    }
    for (const auto& slot : weapon_slots) {
        equipped_weapons[slot] = nullptr;
    }
    
}

// Print character info
void Character::print_info() const {
    std::cout << name << " the " << char_class
              << " is at (" << position.x << ", " << position.y << ") and has "
              << base_hp << " base health, " << base_mp << " base magic points, and "
              << base_sp << " base stamina\nHer endurance is " << endurance
              << " and her max hp is " << max_hp << "\n"
              << "Her attack and defense are:\nAttack: " << attack << "\nDefense: " << defense 
              << "\n";
}

// Print equipment
void Character::print_equipment() const {
    for (const auto& slot : armor_slots) {
        auto it = equipped_armor.find(slot);
        if (it != equipped_armor.end() && it->second) {
            std::cout << slot << " armor: " << it->second->get_name() << "\n";
        } else {
            std::cout << "No " << slot << " armor equipped.\n";
        }
    }
    for (const auto& slot : weapon_slots) {
        auto it = equipped_weapons.find(slot);
        if (it != equipped_weapons.end() && it->second) {
            std::cout << slot << " weapon: " << it->second->get_name() << "\n";
        } else {
            std::cout << "No " << slot << " weapon equipped.\n";
        }
    }
}
//print inventory. loop over categories/item key value pairs, then item/count key value pairs within 
void Character::print_inventory() const {
    for (const auto& category_pair : inventory) {
        const auto& category = category_pair.first;
        const auto& items = category_pair.second;

        std::cout << category << ":\n";

        if (items.empty()) {
            std::cout << "  (empty)\n";
        } else {
            for (const auto& item_pair : items) {
                std::cout << "  " << item_pair.first << " x" << item_pair.second << "\n";
            }
        }
    }
    // Print key items separately
    std::cout << "Key Items:\n";
    if (key_items.empty()) {
        std::cout << "  (none)\n";
    } else {
        for (const auto& key_item : key_items) {
            std::cout << "  " << key_item << "\n";
        }
    }
}

void Character::print_spell_list() const {
    std::cout << "Spell List:\n";

    if (spell_list.empty()) {
        std::cout << name << " knows no spells.\n";
    } else {
        for (const auto& spell : spell_list) {
            std::cout << "  " << spell << " \n";
        }
    }
} 

// Move character
void Character::move(float dx, float dy) {
    position.x += dx;
    position.y += dy;
}
