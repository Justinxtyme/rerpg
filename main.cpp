#include "char.h"
#include "item.h"
#include "weapon.h"
#include <iostream>



int main() {
    try { 
        auto oldbroadaxe = std::make_unique<Weapon>(
            ItemID::OldBroadAxe,
            "Battle Axe",
            12.0f,
            WeaponType::BattleAxe,
            Handling::TwoHanded,
            DamageType::Slashing,
            25
        );

        Character player("Alice", "Warrior", 5, 10);
        player.equip_weapon(std::move(oldbroadaxe), WeaponSlot::MainHand);
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
    