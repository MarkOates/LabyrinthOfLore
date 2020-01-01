

#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <vector>


namespace LabyrinthOfLore
{
namespace Hud
{


CharacterPanel::CharacterPanel(AllegroFlare::Inventory* player_inventory, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary)
   : player_inventory(player_inventory)
   , thing_dictionary(thing_dictionary)
{
}


CharacterPanel::~CharacterPanel()
{
}


std::vector<int> CharacterPanel::get_unique_sorted_list_of_inventory_items()
{
if (!player_inventory) throw std::runtime_error("Cannot get_unique_list_of_inventory_items with a nullptr player_inventory");
std::vector<int> local_copy = player_inventory->get_items_ref();
sort(local_copy.begin(), local_copy.end());
local_copy.erase(unique(local_copy.begin(), local_copy.end()), local_copy.end());
return local_copy;

}

int CharacterPanel::calculate_total_carry_strength()
{
// 10 for now
return 10;

}

int CharacterPanel::calculate_current_carry_weight()
{
if (!thing_dictionary) throw std::runtime_error("Cannot calculate_total_carry_strength with a nullptr thing_dictionary");
if (!player_inventory) throw std::runtime_error("Cannot calculate_total_carry_strength with a nullptr player_inventory");

int result = 0;

std::vector<int> &inventory_items = player_inventory->get_items_ref();
for (unsigned i=0; i<inventory_items.size(); i++)
{
   int item_weight = thing_dictionary->find_definition(inventory_items[i]).get_weight();
   result += item_weight;
}

return result;

}

int CharacterPanel::calculate_available_remaining_carry_weight()
{
return calculate_total_carry_strength() - calculate_current_carry_weight();

}

bool CharacterPanel::has_item(int item_id)
{
if (player_inventory && player_inventory->has_item(item_id)) return true;
return false;

}

std::string CharacterPanel::run()
{
return "Hello World!";
}
} // namespace Hud
} // namespace LabyrinthOfLore


