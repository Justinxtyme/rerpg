#pragma once
#include <string>

class Item {
private:
    std::string name;
    float weight;

public:
    // Constructor
    Item(const std::string& name, float weight) : name(name), weight(weight) {}

    // Accessors
    const std::string& get_name() const { return name; }
    float get_weight() const { return weight; }
};