#include "char.h"
#include <iostream>



int main() {
    try {
        Character player("Alice", "Warrior", 5, 10);
        player.print_info();
        player.print_equipment();
        player.print_inventory();
        player.print_spell_list();
        player.move(3, -2);
        std::cout << "printing info" << std::endl;
        player.print_info();
        printf("Info Printed\n");
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
    