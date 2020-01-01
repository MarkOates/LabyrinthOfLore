#pragma once


#include <AllegroFlare/Inventory.hpp>
#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <string>
#include <vector>


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


      std::vector<int> get_unique_sorted_list_of_inventory_items();
      int calculate_total_carry_strength();
      int calculate_current_carry_weight();
      int calculate_available_remaining_carry_weight();
      bool has_item(int item_id=0);
      std::string run();
      };
   }
}



