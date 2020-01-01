

#include <LabyrinthOfLoreGame/TalkInteractions.hpp>
#include <sstream>


namespace LabyrinthOfLoreGame
{


std::string TalkInteractions::THING_ID_ATTRIBUTE = "thing_id";


TalkInteractions::TalkInteractions(int thing_id, std::vector<LabyrinthOfLore::Entity::Base*>* all_entities, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary, LabyrinthOfLore::Hud::MessageScroll* message_scroll, LabyrinthOfLore::Hud::CharacterPanel* character_panel, AllegroFlare::Inventory* player_inventory)
   : thing_id(thing_id)
   , all_entities(all_entities)
   , thing_dictionary(thing_dictionary)
   , message_scroll(message_scroll)
   , character_panel(character_panel)
   , player_inventory(player_inventory)
{
}


TalkInteractions::~TalkInteractions()
{
}


void TalkInteractions::validate_arguments()
{
if (!all_entities) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr all_entities");
if (!thing_dictionary) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr thing_dictionary");
if (!message_scroll) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr message_scroll");
if (!character_panel) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr character_panel");
if (!player_inventory) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr player_inventory");
thing_dictionary->find_definition_ref(thing_id); // <- will raise an exception if can't be found

return;

}

void TalkInteractions::process(float time_now)
{
LabyrinthOfLore::Entity::ThingDefinition &this_thing_definition = thing_dictionary->find_definition_ref(thing_id);

if (thing_id == 5)
{
   std::stringstream character_dialog;
   message_scroll->append_character_dialog(time_now, "Hey traveler! Down this cavern is a runestone of immaginable power. If you dare to go, you'll need to keep a lit torch or the darkness will attack you.");
}

return;

}
} // namespace LabyrinthOfLoreGame


