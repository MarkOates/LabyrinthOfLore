

#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <vector>


namespace LabyrinthOfLore
{
namespace Hud
{


CharacterPanel::CharacterPanel(AllegroFlare::Inventory* player_inventory, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary)
   : player_inventory(player_inventory)
   , thing_dictionary(thing_dictionary)
   , cursor_x(0)
   , cursor_y(0)
{
}


CharacterPanel::~CharacterPanel()
{
}


int CharacterPanel::get_cursor_x()
{
   return cursor_x;
}


int CharacterPanel::get_cursor_y()
{
   return cursor_y;
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

std::map<thing_type_t, int> CharacterPanel::get_inventory_rollup()
{
if (!player_inventory) throw std::runtime_error("cannot calculate_count_of_type on a nullptr player_inventory");
if (!thing_dictionary) throw std::runtime_error("cannot calculate_count_of_type on a nullptr thing_dictionary");

      //item //count
std::map<thing_type_t, int> result = {};

for (auto &inventory_item_id : player_inventory->get_items_ref())
{
   thing_type_t inventory_item_type = thing_dictionary->find_definition_ref(inventory_item_id).get_type();
   result[inventory_item_type] = calculate_count_of_type(inventory_item_type);
}

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
} // namespace Hud
} // namespace LabyrinthOfLore


