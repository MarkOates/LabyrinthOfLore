

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


int CharacterPanel::calculate_count_of_type(thing_type_t thing_type)
{
if (!player_inventory) throw std::runtime_error("cannot calculate_count_of_type on a nullptr player_inventory");
int count = 0;
std::vector<int> &player_inventory_items = player_inventory->get_items_ref();

for (unsigned i=0; i<player_inventory_items.size(); i++)
{
   if (thing_dictionary->find_definition(player_inventory_items[i]).get_type() == thing_type) count++;
}
return count;

}

std::vector<std::tuple<int, int>> CharacterPanel::get_rollup_inventory()
{
std::vector<std::tuple<int, int>> result = {};
return result;

}

int CharacterPanel::calculate_attack_strength()
{
// 1 for now
return 1;

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


