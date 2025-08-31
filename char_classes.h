
#include <unordered_map>
#include <string>

// Returns a nested map of class -> attributes
std::unordered_map<std::string, std::unordered_map<std::string,int>> load_character_classes();
/*struct ClassTemplate {
    int endurance;
    int strength;
    int dexterity;
    int intelligence;
    int base_speed;
    int luck;
    int base_mp;
    int light;
    int dark;
    int focus;
    int presence;
};

// Factory function
ClassTemplate get_class_template(const std::string& class_name);
*/