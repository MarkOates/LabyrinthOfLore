
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <LabyrinthOfLoreGame/TalkInteractions.hpp>


enum item_id_t
{
   ITEM_NO_ID = 0,
   ITEM_TORCH_ID,
   ITEM_RING_OF_LOFT_ID,
   ITEM_INFINITY_TORCH_ID,
   ITEM_TORCH_FUEL_ID,

   // characters
   MAN_AT_THE_ENTRANCE_TO_THE_CAVE,

   RAT = 100,
};

class LabyrinthOfLoreGame_TalkInteractionsTest : public ::testing::Test
{
protected:
   std::vector<LabyrinthOfLore::Entity::Base*> all_entities;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   AllegroFlare::Inventory player_inventory;

   LabyrinthOfLoreGame_TalkInteractionsTest()
      : all_entities()
      , thing_dictionary()
      , message_scroll()
      , character_panel()
      , player_inventory()
   {
   }

   virtual void SetUp() override
   {
   }

   virtual void TearDown() override
   {
   }
};


TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::TalkInteractions talk_interactions;
}

TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, validate_arguments__will_raise_an_exception_if_it_cannot_find_the_thing_id)
{
   std::vector<LabyrinthOfLore::Entity::Base*> all_entities;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   AllegroFlare::Inventory player_inventory;

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(0, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);

   std::string expected_error_message = "cannot find_definition_ref in the ThingDictionary. It doesn't exist.";
   ASSERT_THROW_WITH_MESSAGE(talk_interactions.validate_arguments(), std::runtime_error, expected_error_message);
}

TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, works_with_the_fixture)
{
   LabyrinthOfLoreGame::TalkInteractions talk_interactions(0, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);

   std::string expected_error_message = "cannot find_definition_ref in the ThingDictionary. It doesn't exist.";
   ASSERT_THROW_WITH_MESSAGE(talk_interactions.validate_arguments(), std::runtime_error, expected_error_message);
}

