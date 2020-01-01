#pragma once


#include <AllegroFlare/Inventory.hpp>
#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>
#include <LabyrinthOfLoreGame/ThingDefinitionFactory.hpp>
#include <string>
#include <vector>


namespace LabyrinthOfLoreGame
{
   class Interactions
   {
   private:
      LabyrinthOfLoreGame::ThingDefinitionFactory* thing_definition_factory;
      std::vector<LabyrinthOfLore::Entity::Base*>* all_entities;
      LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary;
      LabyrinthOfLore::Hud::MessageScroll* message_scroll;
      LabyrinthOfLore::Hud::CharacterPanel* character_panel;
      AllegroFlare::Inventory* player_inventory;
      float time_now;

   public:
      Interactions(LabyrinthOfLoreGame::ThingDefinitionFactory* thing_definition_factory=nullptr, std::vector<LabyrinthOfLore::Entity::Base*>* all_entities=nullptr, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary=nullptr, LabyrinthOfLore::Hud::MessageScroll* message_scroll=nullptr, LabyrinthOfLore::Hud::CharacterPanel* character_panel=nullptr, AllegroFlare::Inventory* player_inventory=nullptr, float time_now=0.0f);
      ~Interactions();


   void validate_arguments();
   void character_speaks(std::string message="");
   void append_message(std::string message="");
   bool player_has_item(int item_id=-1);
   int get_player_inventory_count_of_type(thing_type_t thing_type=THING_TYPE_UNDEFINED);
   bool player_has_thing_of_type(thing_type_t thing_type=THING_TYPE_UNDEFINED);
   void process_use(float time_now=0.0f);
   void process_talk(int thing_id=0, float time_now=0.0f);
   };
}



