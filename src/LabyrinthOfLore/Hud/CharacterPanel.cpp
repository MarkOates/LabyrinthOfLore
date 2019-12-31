

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


int CharacterPanel::calculate_total_carry_strength()
{
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


