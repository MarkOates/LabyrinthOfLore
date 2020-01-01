
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <LabyrinthOfLoreGame/TalkInteractions.hpp>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>



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


static void ASSERT_SAID(LabyrinthOfLore::Hud::MessageScroll message_scroll, std::string expected_message)
{
   std::vector<std::tuple<float, std::string, int>> message_scroll_messages = message_scroll.get_messages_ref();

   if (message_scroll_messages.empty()) FAIL() << "\033[33mThe message scroll is empty.";

   std::stringstream things_said;
   things_said << "\033[33mExpecting the following message is the message scroll: [" << std::endl;
   things_said << "  • " << expected_message << std::endl;
   things_said << "]" << std::endl;
   things_said << "\033[33mThe following things were said in the message scroll: [" << std::endl;

   for (unsigned i=0; i<message_scroll_messages.size(); i++)
   {
      float time = std::get<0>(message_scroll_messages[i]);
      std::string message = std::get<1>(message_scroll_messages[i]);
      int style = std::get<2>(message_scroll_messages[i]);

      std::string actual_thing_said = message;

      if (expected_message == actual_thing_said)
      {
         SUCCEED();
         return;
      }

      things_said << "  • \"" << actual_thing_said << "\"" << std::endl;
   }

   things_said << "]" << std::endl;
   FAIL() << things_said.str();
}



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

/// gameplay event tests

TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, if_you_talk_to_the_man_at_the_entrance_of_the_cave__he_will_say_the_expected_thing)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(MAN_AT_THE_ENTRANCE_TO_THE_CAVE, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   std::string expected_thing_to_say = "Hey traveler! Down this cavern is a runestone of immaginable power. If you dare to go, you'll need to keep a lit torch or the darkness will attack you.";

   talk_interactions.process();

   ASSERT_SAID(message_scroll, expected_thing_to_say);
}

TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, with_the_torch_of_truth__talking_to__the_man_at_the_entrance_of_the_cave__he_will_say_something_cool)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   player_inventory.add_item(ITEM_TORCH_OF_TRUTH);

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(MAN_AT_THE_ENTRANCE_TO_THE_CAVE, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   std::string expected_thing_to_say = "Wowza! I thought the infinity torch you got was cool, but this is... this is... unbelievable!!";

   talk_interactions.process();

   ASSERT_SAID(message_scroll, expected_thing_to_say);
}

TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, with_the_infinity_torch__talking_to__the_man_at_the_entrance_of_the_cave__he_will_say_the_expected_message)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   player_inventory.add_item(ITEM_INFINITY_TORCH_ID);

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(MAN_AT_THE_ENTRANCE_TO_THE_CAVE, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   std::string expected_thing_to_say = "You found the Infinity Torch! Amazing! You are surely a seeker of truth! You have a long quest ahead of you, take this.";

   talk_interactions.process();

   ASSERT_SAID(message_scroll, expected_thing_to_say);
}

