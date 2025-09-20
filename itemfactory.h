// ItemFactory.h
#pragma once
#include <memory>
#include <unordered_map>
#include <fstream>
#include <nlohmann/json.hpp>
#include "weapon.h"
#include "armor.h"
#include "stacker.h"


class ItemFactory {
    inline static nlohmann::json itemData; // static shared data

public:
    static void load(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open " + filename);
        }
        file >> itemData;
    }

    static std::unique_ptr<Item> create(ItemID id) {
        // use the enum name as string key
        std::string key = itemIDToString(id);

        if (!itemData.contains(key)) {
            throw std::runtime_error("Item not found: " + key);
        }

        auto& data = itemData[key];
        std::string type = data["type"];

        if (type == "weapon") {
            return std::make_unique<Weapon>(
                id,
                data["name"],
                data["weight"],
                data["base_damage"],
                data["rarity_mod"]
            );
        }
        else if (type == "armor") {
            std::vector<Ability> abilities;
            for (const auto& abilityName : data["abilities"]) {
                abilities.push_back(parseAbility(abilityName));
            }
            return std::make_unique<Armor>(
                id,
                data["name"],
                data["weight"],
                parseArmorClass(data["armor_class"]),
                parseArmorType(data["armor_type"]),
                data["base_defense"],
                data["rarity_mod"],
                abilities   
            );
        }
        else if (type == "consumable") {
            return std::make_unique<Consumable>(
                id,
                data["name"],
                data["weight"],
                data["effect"]
            );
        }
        else if (type == "keyitem") {
            return std::make_unique<KeyItem>(
                id,
                data["name"],
                data["weight"],
                data["effect"]
            );
        }
        throw std::runtime_error("Unknown type: " + type);
    }

private:
    // helper to convert enum -> string
    static std::string itemIDToString(ItemID id) {
        switch (id) {
            case ItemID::OldBroadAxe: return "BattleAxe";
            case ItemID::ClothRobe: return "ClothRobe";
            // … add mappings …
            default: return "Unknown";
        }
    }

    static ArmorClass parseArmorClass(const std::string& s) {
        if (s == "LightArmor") return ArmorClass::LightArmor;
        if (s == "MediumArmor") return ArmorClass::MediumArmor;
        if (s == "HeavyArmor") return ArmorClass::HeavyArmor;
        throw std::runtime_error("Bad ArmorClass: " + s);
    }

    static ArmorType parseArmorType(const std::string& s) {
        if (s == "Head")  return ArmorType::Head;
        if (s == "Chest") return ArmorType::Chest;
        if (s == "Waist") return ArmorType::Waist;
        if (s == "Legs")  return ArmorType::Legs;
        if (s == "Arms")  return ArmorType::Arms;
        if (s == "Feet")  return ArmorType::Feet;
        throw std::runtime_error("Bad ArmorType: " + s);
    }

    static Ability parseAbility(const std::string& s) {
        if (s == "IronSkin") return Ability::IronSkin;
        if (s == "ArcaneFocus") return Ability::ArcaneFocus;
        if (s == "QuickStep") return Ability::QuickStep;
        // ...add all abilities
        throw std::runtime_error("Unknown ability: " + s);
    }
};
