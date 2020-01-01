

#include <LabyrinthOfLoreGame/Interactions.hpp>
#include <sstream>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>


namespace LabyrinthOfLoreGame
{


Interactions::Interactions(LabyrinthOfLoreGame::ThingDefinitionFactory* thing_definition_factory, std::vector<LabyrinthOfLore::Entity::Base*>* all_entities, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary, LabyrinthOfLore::Hud::MessageScroll* message_scroll, LabyrinthOfLore::Hud::CharacterPanel* character_panel, AllegroFlare::Inventory* player_inventory, float time_now)
   : thing_definition_factory(thing_definition_factory)
   , all_entities(all_entities)
   , thing_dictionary(thing_dictionary)
   , message_scroll(message_scroll)
   , character_panel(character_panel)
   , player_inventory(player_inventory)
   , time_now(time_now)
{
}


Interactions::~Interactions()
{
}


void Interactions::validate_arguments()
{
if (!thing_definition_factory) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr thing_definition_factory");
if (!all_entities) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr all_entities");
if (!thing_dictionary) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr thing_dictionary");
if (!message_scroll) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr message_scroll");
if (!character_panel) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr character_panel");
if (!player_inventory) throw std::runtime_error("Cannot process_thing_talk_click with a nullptr player_inventory");

return;

}

std::string Interactions::you_have_received_the_(int thing_id)
{
LabyrinthOfLore::Entity::ThingDefinition &this_thing_definition = thing_dictionary->find_definition_ref(thing_id);
std::stringstream message;
message << "You have received " << this_thing_definition.infer_decorated_name() << ".";
return message.str();

}

void Interactions::character_speaks(std::string message)
{
message_scroll->append_character_dialog(time_now, message);

}

void Interactions::append_message(std::string message)
{
message_scroll->append_message(time_now, message);

}

bool Interactions::player_has_item(int item_id)
{
return player_inventory->has_item(item_id);

}

int Interactions::get_player_inventory_count_of_type(thing_type_t thing_type)
{
if (!character_panel) throw std::runtime_error("cannot player_has_thing_of_type on a nullptr character_panel");
return character_panel->calculate_count_of_type(thing_type);

}

bool Interactions::player_has_thing_of_type(thing_type_t thing_type)
{
return get_player_inventory_count_of_type() >= 1;

}

void Interactions::process_use(float time_now)
{
return;

}

void Interactions::process_use(int thing_being_used_by_player_from_inventory, int thing_being_used_on, float time_now)
{
if (thing_being_used_by_player_from_inventory == LETTER_TO_CATALINA_ID && thing_being_used_on == CATALINA_IN_THE_VILLAGE_ID)
{
   character_speaks("What is this!? Oh my! A letter from my loved ones! They haven't forgotten me! I feel young again! I shall repay you with the only thing I have.");
   player_inventory->remove_item(LETTER_TO_CATALINA_ID);
   player_inventory->add_item(AMULET_OF_MAGIC_ID);
   append_message(you_have_received_the_(AMULET_OF_MAGIC_ID));
}
return;

}

void Interactions::process_talk(int thing_id)
{
//this->thing_id = thing_id;
LabyrinthOfLore::Entity::ThingDefinition &this_thing_definition = thing_dictionary->find_definition_ref(thing_id);

int new_id = -1;

if (thing_id == MAN_AT_THE_ENTRANCE_TO_THE_CAVE)
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

if (thing_id == CATALINA_IN_THE_VILLAGE_ID)
{
   character_speaks("Hello there young one. Look at you. You have so much life. I've been here for far to long, and " \
                    "miss so deeply my loved ones. I wonder if they still think of me...");
}

if (thing_id == HARCOURT_IN_THE_VILLAGE)
{
   if (get_player_inventory_count_of_type(THING_TYPE_TORCH_FUEL) < 3)
   {
      character_speaks("It's not so great down here. We all do our best to help each other out. " \
                       "You look like you're low on torch fuel. Have some of mine.");

      while(character_panel->calculate_count_of_type(THING_TYPE_TORCH_FUEL) < 3)
      {
          player_inventory->add_item(thing_dictionary->create_new_definition({THING_TYPE_TORCH_FUEL, "some", "torch fuel"}));
      }
   }
   else
   {
      character_speaks("You look like an avatar I once knew. So strong and powerful, they once saved us all. Maybe you can do the same.");
   }
}

return;

}
} // namespace LabyrinthOfLoreGame


