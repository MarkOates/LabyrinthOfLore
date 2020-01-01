

#include <LabyrinthOfLoreGame/TalkInteractions.hpp>
#include <sstream>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>


namespace LabyrinthOfLoreGame
{


std::string TalkInteractions::THING_ID_ATTRIBUTE = "thing_id";


TalkInteractions::TalkInteractions(int thing_id, std::vector<LabyrinthOfLore::Entity::Base*>* all_entities, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary, LabyrinthOfLore::Hud::MessageScroll* message_scroll, LabyrinthOfLore::Hud::CharacterPanel* character_panel, AllegroFlare::Inventory* player_inventory, float time_now)
   : thing_id(thing_id)
   , all_entities(all_entities)
   , thing_dictionary(thing_dictionary)
   , message_scroll(message_scroll)
   , character_panel(character_panel)
   , player_inventory(player_inventory)
   , time_now(time_now)
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

void TalkInteractions::character_speaks(std::string message)
{
message_scroll->append_character_dialog(time_now, message);

}

void TalkInteractions::append_message(std::string message)
{
message_scroll->append_message(time_now, message);

}

bool TalkInteractions::talking_to(int possibl_thing_id_talking_to)
{
return thing_id == possibl_thing_id_talking_to;

}

bool TalkInteractions::player_has_item(int item_id)
{
return player_inventory->has_item(item_id);

}

void TalkInteractions::process(float time_now)
{
LabyrinthOfLore::Entity::ThingDefinition &this_thing_definition = thing_dictionary->find_definition_ref(thing_id);

if (talking_to(MAN_AT_THE_ENTRANCE_TO_THE_CAVE))
{
   if (player_has_item(ITEM_INFINITY_TORCH_ID)) {
      character_speaks("You found the Infinity Torch! Amazing! You are surely a " \
                       "seeker of truth! You have a long quest ahead of you, take this.");
   }
   else if (player_has_item(ITEM_TORCH_OF_TRUTH)) {
      character_speaks("Wowza! I thought the infinity torch you got was cool, but this is... this is... unbelievable!!");
   }
   else {
      character_speaks("Hey traveler! Down this cavern is a runestone of immaginable power. " \
                        "If you dare to go, you'll need to keep a lit torch or the darkness will attack you.");
   }
}

return;

}
} // namespace LabyrinthOfLoreGame


