
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>

TEST(LabyrinthOfLore_Hud_CharacterPanelTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
}

TEST(LabyrinthOfLore_Hud_CharacterPanelTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, character_panel.run());
}

TEST(LabyrinthOfLore_Hud_CharacterPanelTest, calculate_current_carry_weight__returns_the_total_weight_of_the_players_inventory__test_1)
{
   AllegroFlare::Inventory player_inventory;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { 1, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_DOES_NOT_MATTER, "a", "rock", nullptr, -1, 6) },
   });

   player_inventory.add_item(1);

   LabyrinthOfLore::Hud::CharacterPanel character_panel(&player_inventory, &thing_dictionary);
   EXPECT_EQ(6, character_panel.calculate_current_carry_weight());
}

TEST(LabyrinthOfLore_Hud_CharacterPanelTest, calculate_current_carry_weight__returns_the_total_weight_of_the_players_inventory__test_2)
{
   AllegroFlare::Inventory player_inventory;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { 1, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_DOES_NOT_MATTER, "a", "rock",    nullptr, -1, 6) },
      { 2, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_DOES_NOT_MATTER, "a", "feather", nullptr, -1, 1) },
      { 3, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_DOES_NOT_MATTER, "a", "shoe",    nullptr, -1, 4) },
      { 4, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_DOES_NOT_MATTER, "a", "duck",    nullptr, -1, -1) },
   });

   player_inventory.add_item(1);
   player_inventory.add_item(2);
   player_inventory.add_item(3);
   player_inventory.add_item(4);

   LabyrinthOfLore::Hud::CharacterPanel character_panel(&player_inventory, &thing_dictionary);
   EXPECT_EQ(10, character_panel.calculate_current_carry_weight());
}


TEST(LabyrinthOfLore_Hud_CharacterPanelTest, count_of_type__returns_a_count_of_things_of_a_certain_type)
{
   AllegroFlare::Inventory player_inventory;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { 1, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH_FUEL, "some",   "torch fuel",    nullptr, -1, 6) },
      { 2, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH_FUEL, "some",   "torch fuel", nullptr, -1, 1) },
      { 3, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH,      "a",      "torch",    nullptr, -1, 4) },
      { 4, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_DOES_NOT_MATTER, "a", "duck",    nullptr, -1, -1) },
   });

   player_inventory.add_item(1);
   player_inventory.add_item(2);
   player_inventory.add_item(3);
   player_inventory.add_item(4);

   LabyrinthOfLore::Hud::CharacterPanel character_panel(&player_inventory, &thing_dictionary);
   EXPECT_EQ(2, character_panel.calculate_count_of_type(THING_TYPE_TORCH_FUEL));
   EXPECT_EQ(1, character_panel.calculate_count_of_type(THING_TYPE_TORCH));
}

