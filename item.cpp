//

#include <unordered_map>

std::unordered_map<ItemID, Item> item_db = {
    {ItemID::Potion,  {ItemID::Potion,  "Potion",  0.5f}},
    {ItemID::HiPotion,{ItemID::HiPotion,"Hi-Potion", 0.7f}},
    {ItemID::Elixir,  {ItemID::Elixir,  "Elixir", 1.0f}}
};