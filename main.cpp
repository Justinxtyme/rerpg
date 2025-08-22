#include "char.h"
#include <iostream>

int main() {
    try {
        Character player("Alice", "Warrior", 5, 10);
        player.print_info();
        player.move(3, -2);
        player.print_info();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}