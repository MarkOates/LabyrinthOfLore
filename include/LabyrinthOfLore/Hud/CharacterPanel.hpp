#pragma once


#include <AllegroFlare/Inventory.hpp>
#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>
#include <map>


namespace LabyrinthOfLore
{
   namespace Hud
   {
      class CharacterPanel
      {
      private:
         AllegroFlare::Inventory* player_inventory;
         LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary;
         int cursor_x;
         int cursor_y;

      protected:


      public:
         CharacterPanel(AllegroFlare::Inventory* player_inventory=nullptr, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary=nullptr);
         ~CharacterPanel();

         void set_player_inventory(AllegroFlare::Inventory* player_inventory);
         void set_thing_dictionary(LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary);
         int get_cursor_x() const;
         int get_cursor_y() const;
         bool move_cursor_up();
         bool move_cursor_down();
         int calculate_count_of_type(thing_type_t thing_type=THING_TYPE_UNDEFINED);
         std::map<thing_type_t, int> get_inventory_rollup();
         int calculate_attack_strength();
         int calculate_total_carry_strength();
         int calculate_current_carry_weight();
         int calculate_available_remaining_carry_weight();
         bool has_item(int item_id=0);
      };
   }
}



