#pragma once
#include <string>
#include <unordered_map>
#include "char_classes.h" // Provides access to load_character_classes()
// #include "vector2.h"   // Optional: if you want Vector2 in its own file

// Minimal 2D vector struct, equivalent to pygame.Vector2
struct Vector2 {
    float x; // X coordinate
    float y; // Y coordinate

    // Constructor with default parameters (like Python's x=0, y=0)
    // Uses initializer list to directly construct members efficiently
    Vector2(float x_val = 0, float y_val = 0) : x(x_val), y(y_val) {}
};

// Character class definition
class Character {
private:
    std::string name; // Character's name
    std::string char_class; // Character type (e.g., "Warrior")
    Vector2 position; // Character's position in 2D space
    std::unordered_map<std::string, int> attributes; 
    // Map storing attribute name -> value (e.g., "strength" -> 15)
    // Loaded from load_character_classes()

public:
    // Constructor: called automatically when a Character object is created
    // Parameters: name, character class, optional x/y position
    // Loads class attributes and initializes basic character info
    Character(const std::string& name, const std::string& char_class, float x = 0, float y = 0);

    // Prints the character's name, class, and current position
    void print_info() const;

    // Moves the character by dx and dy in the 2D space
    void move(float dx, float dy);
};