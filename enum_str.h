#pragma once
#include "item.h"      // defines ItemID
#include "weapon.h"    // defines WeaponType, WeaponSlot (or put those in a common header)
#include "armor.h"     // defines ArmorType
#include <string>

// Keep these inline in a header to avoid multiple-definition linker errors.

// ItemID -> human readable name
inline std::string to_string(ItemID id) {
    switch (id) {
        case ItemID::Potion: return "Health Potion";
        case ItemID::PotentPotion:   return "Mana Potion";
        case ItemID::IronSword:    return "Iron Sword";
        case ItemID::LeatherArmor: return "Leather Armor";
        // add the rest of your ItemID cases here...
        default: return "Unknown Item";
    }
}

// ArmorType -> slot name
inline std::string to_string(ArmorType type) {
    switch (type) {
        case ArmorType::Head:  return "Head";
        case ArmorType::Chest: return "Chest";
        case ArmorType::Arms:  return "Arms";
        case ArmorType::Waist: return "Waist";
        case ArmorType::Legs:  return "Legs";
        case ArmorType::Feet:  return "Feet";
        default: return "Unknown Armor Slot";
    }
}

// WeaponSlot -> slot name
inline std::string to_string(WeaponSlot slot) {
    switch (slot) {
        case WeaponSlot::MainHand:  return "Main Hand";
        case WeaponSlot::OffHand:   return "Off Hand";
        case WeaponSlot::TwoHand:   return "Two-Handed";
        default: return "Unknown Weapon Slot";
    }
}

// WeaponType -> readable weapon type
inline std::string to_string(WeaponType weapontype) {
    switch (weapontype) {
        case WeaponType::Dagger:      return "Dagger";
        case WeaponType::ShortSword:  return "Short Sword";
        case WeaponType::LongSword:   return "Long Sword";
        case WeaponType::BattleAxe:   return "Battle Axe";
        case WeaponType::ShortBow:    return "Short Bow";
        case WeaponType::LongBow:     return "Long Bow";
        // add the rest...
        default: return "Unknown Weapon";
    }
}
