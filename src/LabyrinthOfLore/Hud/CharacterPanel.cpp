

#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>



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


