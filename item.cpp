//
#include "item.h"
#include <unordered_map>
#include <iostream>

std::unordered_map<ItemID, Item> item_db = {
    {ItemID::Potion,  {ItemID::Potion,  "Potion",  0.5f}},
    {ItemID::PotentPotion,{ItemID::PotentPotion,"Potent Potion", 0.7f}},
    {ItemID::ElixirOfStrength,  {ItemID::ElixirOfStrength,  "Elixir Of Strength", 1.0f}},
    {ItemID::SuperElixir,  {ItemID::SuperElixir,  "Elixir Of Strength", 1.0f}},
    {ItemID::ElixirOfDefense,  {ItemID::ElixirOfDefense,  "Elixir Of Defense", 1.0f}},
    {ItemID::PoisonFlask,  {ItemID::PoisonFlask,  "Poison Flask", 1.0f}},
};

void Item::print_info() const {
    std::cout << "Item: " << name << ", weight: " << weight << "\n";
}