#pragma once
#include <unordered_map>
#include <string>

// Returns a nested map of class -> attributes
std::unordered_map<std::string, std::unordered_map<std::string,int>> load_character_classes();