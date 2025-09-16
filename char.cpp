#include "char.h"
#include "item.h"
#include <iostream>
#include "enum_str.h"

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

    this->base_attack  = 1;
    this->attack  = base_attack + (strength * 2) + (dexterity * 1);
    this->base_defense = 1;
    this->defense = base_defense + strength + dexterity; // + total_armor_defense

    

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
    std::cout << "Equipped Armor:\n";
    for (const auto& [slot, item] : inventory.armor) {
        std::cout << "  " << to_string(slot) << ": ";
        if (item) {
            std::cout << item->get_name() << "\n";
        } else {
            std::cout << "(empty)\n";
        }
    }

    std::cout << "\nEquipped Weapons:\n";
    for (const auto& [slot, item] : inventory.weapons) {
        std::cout << "  " << to_string(slot) << ": ";
        if (item) {
            std::cout << item->get_name() << "\n";
        } else {
            std::cout << "(empty)\n";
        }
    }
}

//print inventory. 
void Character::print_inventory() const {
    std::cout << "Inventory:\n";
    if (inventory.stackables.empty()) {
        std::cout << "  (empty)\n";
    } else {
        for (const auto& [id, count] : inventory.stackables) {
            std::cout << "  " << to_string(id) << " x" << count << "\n";
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

// Move character
void Character::tele(float dx, float dy) {
    position.x = dx;
    position.y = dy;
}
