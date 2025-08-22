#include "char.h"
#include <iostream>

// ----------------------
// Constructor
// ----------------------
// This function is automatically called when a Character object is created.
// It sets up the character's name, class, position, and loads their attributes.
Character::Character(const std::string& name, const std::string& char_class, float x, float y) {
    // 1. Load all available character classes
    // This returns a nested unordered_map: class name -> attributes map
    auto character_classes = load_character_classes();

    // 2. Validate that the chosen class exists in the database
    // If not, throw an exception (similar to Python's ValueError)
    if (character_classes.find(char_class) == character_classes.end()) {
        throw std::invalid_argument("Unknown character class: " + char_class);
    }

    // 3. Load the attribute map for this specific class
    // e.g., Warrior -> {"strength": 15, "dexterity": 10, ...}
    attributes = character_classes[char_class];

    // 4. Initialize basic fields
    // "this->" clarifies that we are assigning to the object's members
    this->name = name;                  // Set character's name
    this->char_class = char_class;      // Set character class
    this->position = Vector2(x, y);     // Set initial 2D position
}

// ----------------------
// Print info
// ----------------------
// Prints character's name, class, and position to console
void Character::print_info() const {
    std::cout << name << " the " << char_class 
              << " is at (" << position.x << ", " << position.y << ")\n";
}

// ----------------------
// Move character
// ----------------------
// Updates the character's position by adding dx and dy to current coordinates
void Character::move(float dx, float dy) {
    position.x += dx;  // Move along X-axis
    position.y += dy;  // Move along Y-axis
}
