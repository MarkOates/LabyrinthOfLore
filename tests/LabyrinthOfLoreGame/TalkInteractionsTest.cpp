
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
   LabyrinthOfLore::Entity::Base entity;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   AllegroFlare::Inventory player_inventory;

   LabyrinthOfLoreGame_TalkInteractionsTest()
      : all_entities()
      , entity()
      , thing_dictionary()
      , message_scroll()
      , character_panel()
      , player_inventory()
   {
   }

   virtual void SetUp() override
   {
       entity.set("thing_id", 1);
   }

   virtual void TearDown() override
   {
   }
};


TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::TalkInteractions talk_interactions;
}

TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, validate_arguments__with_default_values__raises_an_exception_requiring_an_entity_with_a_thing_id)
{
   std::vector<LabyrinthOfLore::Entity::Base*> all_entities;
   LabyrinthOfLore::Entity::Base entity;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   AllegroFlare::Inventory player_inventory;

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(&all_entities, &entity, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   std::string expected_error_message = "Cannot validate_arguments expecting the entity to have a \"thing_id\" but it does not.";
   ASSERT_THROW_WITH_MESSAGE(talk_interactions.validate_arguments(), std::runtime_error, expected_error_message);
}

TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, validate_arguments__works_with_safe_values)
{
   std::vector<LabyrinthOfLore::Entity::Base*> all_entities;
   LabyrinthOfLore::Entity::Base entity;
   entity.set("thing_id", 1);
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   AllegroFlare::Inventory player_inventory;

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(&all_entities, &entity, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   talk_interactions.validate_arguments();
   SUCCEED();
}

TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, works_with_the_fixture)
{
   LabyrinthOfLoreGame::TalkInteractions talk_interactions(&all_entities, &entity, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   talk_interactions.validate_arguments();
   SUCCEED();
}

