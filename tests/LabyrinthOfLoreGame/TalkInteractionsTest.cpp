
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
   LabyrinthOfLoreGame::ThingDefinitionFactory thing_definition_factory;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   AllegroFlare::Inventory player_inventory;
   LabyrinthOfLore::Hud::CharacterPanel character_panel;

   LabyrinthOfLoreGame_TalkInteractionsTest()
      : all_entities()
      , thing_definition_factory()
      , thing_dictionary()
      , message_scroll()
      , player_inventory()
      , character_panel(&player_inventory, &thing_dictionary)
   {
   }

   virtual void SetUp() override
   {
   }

   virtual void TearDown() override
   {
   }

   LabyrinthOfLoreGame::TalkInteractions create_simple_talk_interaction_with(int thing_talking_to)
   {
      return LabyrinthOfLoreGame::TalkInteractions(thing_talking_to, &thing_definition_factory, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   }

   void ASSERT_SAID(std::string expected_message)
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
};




TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::TalkInteractions talk_interactions;
}



TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, validate_arguments__will_raise_an_exception_if_it_cannot_find_the_thing_id)
{
   std::vector<LabyrinthOfLore::Entity::Base*> all_entities;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLoreGame::ThingDefinitionFactory thing_definition_factory;
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   AllegroFlare::Inventory player_inventory;

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(0, &thing_definition_factory, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);

   std::string expected_error_message = "cannot find_definition_ref in the ThingDictionary. It doesn't exist.";
   ASSERT_THROW_WITH_MESSAGE(talk_interactions.validate_arguments(), std::runtime_error, expected_error_message);
}



TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, works_with_the_fixture)
{
   LabyrinthOfLoreGame::TalkInteractions talk_interactions(0, &thing_definition_factory, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);

   std::string expected_error_message = "cannot find_definition_ref in the ThingDictionary. It doesn't exist.";
   ASSERT_THROW_WITH_MESSAGE(talk_interactions.validate_arguments(), std::runtime_error, expected_error_message);
}



/// gameplay event tests

TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, if_you_talk_to_the_man_at_the_entrance_of_the_cave__he_will_say_the_expected_thing)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(MAN_AT_THE_ENTRANCE_TO_THE_CAVE, &thing_definition_factory, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   std::string expected_thing_to_say = "Hey traveler! Down this cavern is a runestone of immaginable power. If you dare to go, you'll need to keep a lit torch or the darkness will attack you.";

   talk_interactions.process();

   ASSERT_SAID(expected_thing_to_say);
}



TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, with_the_torch_of_truth__talking_to__the_man_at_the_entrance_of_the_cave__he_will_say_something_cool)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   player_inventory.add_item(ITEM_TORCH_OF_TRUTH);

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(MAN_AT_THE_ENTRANCE_TO_THE_CAVE, &thing_definition_factory, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   std::string expected_thing_to_say = "Wowza! I thought the infinity torch you got was cool, but this is... this is... unbelievable!!";

   talk_interactions.process();

   ASSERT_SAID(expected_thing_to_say);
}



TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, with_the_infinity_torch__talking_to__the_man_at_the_entrance_of_the_cave__he_will_say_the_expected_message)
{
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary({
      { MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   player_inventory.add_item(ITEM_INFINITY_TORCH_ID);

   LabyrinthOfLoreGame::TalkInteractions talk_interactions(MAN_AT_THE_ENTRANCE_TO_THE_CAVE, &thing_definition_factory, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   std::string expected_thing_to_say = "You found the Infinity Torch! Amazing! You are surely a seeker of truth! You have a long quest ahead of you, take this.";

   talk_interactions.process();

   ASSERT_SAID(expected_thing_to_say);
}



TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, if_you_talk_to_catalina_in_the_village__she_gives_you_the_expected_message)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { CATALINA_IN_THE_VILLAGE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   LabyrinthOfLoreGame::TalkInteractions talk_interaction = create_simple_talk_interaction_with(CATALINA_IN_THE_VILLAGE);
   std::string expected_thing_to_say = "Hello there young one. Look at you. You have so much life. I've been here for far to long, and miss so deeply my loved ones. I wonder if they still think of me...";

   talk_interaction.process();
   ASSERT_SAID(expected_thing_to_say);
}


TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, if_you_talk_to_harcourt__when_you_have_at_least_3_torch_fuels__he_will_give_you_a_prophecy)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { HARCOURT_IN_THE_VILLAGE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   player_inventory.add_item(thing_dictionary.create_new_definition({THING_TYPE_TORCH_FUEL, "some", "torch fuel"}));
   player_inventory.add_item(thing_dictionary.create_new_definition({THING_TYPE_TORCH_FUEL, "some", "torch fuel"}));
   player_inventory.add_item(thing_dictionary.create_new_definition({THING_TYPE_TORCH_FUEL, "some", "torch fuel"}));

   LabyrinthOfLoreGame::TalkInteractions talk_interaction = create_simple_talk_interaction_with(HARCOURT_IN_THE_VILLAGE);
   std::string expected_thing_to_say = "You look like an avatar I once knew. So strong and powerful, they once saved us all. Maybe you can do the same.";

   talk_interaction.process();

   // assert he said the thing
   ASSERT_SAID(expected_thing_to_say);
}



TEST_F(LabyrinthOfLoreGame_TalkInteractionsTest, if_you_talk_to_harcourt__when_you_have_less_than_3_torch_fuels__he_will_tell_you_a_message_and_give_you_up_to_3_torch_fuels)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { HARCOURT_IN_THE_VILLAGE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   LabyrinthOfLoreGame::TalkInteractions talk_interaction = create_simple_talk_interaction_with(HARCOURT_IN_THE_VILLAGE);
   std::string expected_thing_to_say = "It's not so great down here. We all do our best to help each other out. You look like you're low on torch fuel. Have some of mine.";

   talk_interaction.process();

   // assert he said the thing
   ASSERT_SAID(expected_thing_to_say);
   ASSERT_EQ(3, character_panel.calculate_count_of_type(THING_TYPE_TORCH_FUEL));
}



