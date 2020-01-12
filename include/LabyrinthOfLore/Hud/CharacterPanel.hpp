#pragma once


#include <AllegroFlare/Inventory.hpp>
#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>
#include <string>
#include <tuple>
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


      int calculate_count_of_type(thing_type_t thing_type=THING_TYPE_UNDEFINED);
      std::vector<std::tuple<int, int>> get_rollup_inventory();
      int calculate_attack_strength();
      int calculate_total_carry_strength();
      int calculate_current_carry_weight();
      int calculate_available_remaining_carry_weight();
      bool has_item(int item_id=0);
      std::string run();
      };
   }
}



