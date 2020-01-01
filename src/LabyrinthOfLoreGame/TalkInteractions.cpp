

#include <LabyrinthOfLoreGame/TalkInteractions.hpp>



namespace LabyrinthOfLoreGame
{


std::string TalkInteractions::THING_ID_ATTRIBUTE = "thing_id";


TalkInteractions::TalkInteractions(std::vector<LabyrinthOfLore::Entity::Base*>* all_entities, LabyrinthOfLore::Entity::Base* entity, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary, LabyrinthOfLore::Hud::MessageScroll* message_scroll, LabyrinthOfLore::Hud::CharacterPanel* character_panel, AllegroFlare::Inventory* player_inventory)
   : all_entities(all_entities)
   , entity(entity)
   , thing_dictionary(thing_dictionary)
   , message_scroll(message_scroll)
   , character_panel(character_panel)
   , player_inventory(player_inventory)
{
}


TalkInteractions::~TalkInteractions()
{
}


void TalkInteractions::process()
{
if (!all_entities) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr all_entities");
if (!entity) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr entity");
if (!thing_dictionary) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr thing_dictionary");
if (!message_scroll) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr message_scroll");
if (!character_panel) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr character_panel");
if (!player_inventory) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr player_inventory");

if (!entity->exists(THING_ID_ATTRIBUTE)) throw std::runtime_error("Cannot process_thing_talk_click expecting the entity to have a \"thing_id\" but it does not.");


return;

}
} // namespace LabyrinthOfLoreGame


