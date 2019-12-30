#pragma once


#include <AllegroFlare/Inventory.hpp>
#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <string>


namespace LabyrinthOfLore
{
   namespace Hud
   {
      class CharacterPanel
      {
      private:
         AllegroFlare::Inventory* player_inventory;
         LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary;

      public:
         CharacterPanel(AllegroFlare::Inventory* player_inventory=nullptr, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary=nullptr);
         ~CharacterPanel();


      std::string run();
      };
   }
}



