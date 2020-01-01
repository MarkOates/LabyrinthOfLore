#pragma once


#include <AllegroFlare/Inventory.hpp>
#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <string>
#include <vector>


namespace LabyrinthOfLoreGame
{
   class TalkInteractions
   {
   private:
      std::vector<LabyrinthOfLore::Entity::Base*>* all_entities;
      LabyrinthOfLore::Entity::Base* entity;
      LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary;
      LabyrinthOfLore::Hud::MessageScroll* message_scroll;
      LabyrinthOfLore::Hud::CharacterPanel* character_panel;
      AllegroFlare::Inventory* player_inventory;

   public:
      TalkInteractions();
      ~TalkInteractions();


   std::string run();
   };
}



