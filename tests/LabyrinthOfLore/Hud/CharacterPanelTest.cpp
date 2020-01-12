
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>

TEST(LabyrinthOfLore_Hud_CharacterPanelTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
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


TEST(LabyrinthOfLore_Hud_CharacterPanelTest, get_inventory_rollup__without_a_player_inventory__raises_an_exception)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLore::Hud::CharacterPanel character_panel(nullptr, &thing_dictionary);

   std::string expected_error_message = "cannot calculate_count_of_type on a nullptr player_inventory";

   ASSERT_THROW_WITH_MESSAGE(character_panel.get_inventory_rollup(), std::runtime_error, expected_error_message);
}


TEST(LabyrinthOfLore_Hud_CharacterPanelTest, get_inventory_rollup__without_a_thing_dictionary__raises_an_exception)
{
   AllegroFlare::Inventory player_inventory;
   LabyrinthOfLore::Hud::CharacterPanel character_panel(&player_inventory, nullptr);

   std::string expected_error_message = "cannot calculate_count_of_type on a nullptr thing_dictionary";

   ASSERT_THROW_WITH_MESSAGE(character_panel.get_inventory_rollup(), std::runtime_error, expected_error_message);
}


TEST(LabyrinthOfLore_Hud_CharacterPanelTest, get_inventory_rollup__will_return_a_list_of_inventory_items_rolled_up)
{
   AllegroFlare::Inventory player_inventory;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { 1, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH_FUEL, "some",   "torch fuel",    nullptr, -1, 6) },
      { 2, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH_FUEL, "some",   "torch fuel", nullptr, -1, 1) },
      { 3, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH,      "a",      "torch",    nullptr, -1, 4) },
      { 4, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_DOES_NOT_MATTER, "a", "duck",    nullptr, -1, -1) },
      { 5, LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH_FUEL, "some",   "torch fuel", nullptr, -1, 1) },
   });

   player_inventory.add_item(1);
   player_inventory.add_item(2);
   player_inventory.add_item(3);
   player_inventory.add_item(4);
   player_inventory.add_item(5);

   LabyrinthOfLore::Hud::CharacterPanel character_panel(&player_inventory, &thing_dictionary);

   std::map<thing_type_t, int> expected_rolled_up_inventory{
      { THING_TYPE_TORCH,           1 },
      { THING_TYPE_DOES_NOT_MATTER, 1 },
      { THING_TYPE_TORCH_FUEL,      3 },
   };

   std::map<thing_type_t, int> actual_rolled_up_inventory = character_panel.get_inventory_rollup();

   EXPECT_EQ(expected_rolled_up_inventory, actual_rolled_up_inventory);
}


