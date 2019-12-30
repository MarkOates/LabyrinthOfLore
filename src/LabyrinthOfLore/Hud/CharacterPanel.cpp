

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


std::string CharacterPanel::run()
{
return "Hello World!";
}
} // namespace Hud
} // namespace LabyrinthOfLore


