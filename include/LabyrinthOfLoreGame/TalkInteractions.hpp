#pragma once


#include <AllegroFlare/Inventory.hpp>
#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <LabyrinthOfLoreGame/ThingDefinitionFactory.hpp>
#include <string>
#include <vector>


namespace LabyrinthOfLoreGame
{
   class TalkInteractions
   {
   private:
      int thing_id;
      LabyrinthOfLoreGame::ThingDefinitionFactory* thing_definition_factory;
      std::vector<LabyrinthOfLore::Entity::Base*>* all_entities;
      LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary;
      LabyrinthOfLore::Hud::MessageScroll* message_scroll;
      LabyrinthOfLore::Hud::CharacterPanel* character_panel;
      AllegroFlare::Inventory* player_inventory;
      float time_now;
      static std::string THING_ID_ATTRIBUTE;

   public:
      TalkInteractions(int thing_id=0, LabyrinthOfLoreGame::ThingDefinitionFactory* thing_definition_factory=nullptr, std::vector<LabyrinthOfLore::Entity::Base*>* all_entities=nullptr, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary=nullptr, LabyrinthOfLore::Hud::MessageScroll* message_scroll=nullptr, LabyrinthOfLore::Hud::CharacterPanel* character_panel=nullptr, AllegroFlare::Inventory* player_inventory=nullptr, float time_now=0.0f);
      ~TalkInteractions();


   void validate_arguments();
   void character_speaks(std::string message="");
   void append_message(std::string message="");
   bool you_talk_to(int possible_thing_id_talking_to=-1);
   bool player_has_item(int item_id=-1);
   void process(float time_now=0.0f);
   };
}



