
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <LabyrinthOfLoreGame/Interactions.hpp>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>



class LabyrinthOfLoreGame_InteractionsTest : public ::testing::Test
{
protected:
   LabyrinthOfLoreGame::ThingDefinitionFactory thing_definition_factory;
   std::vector<LabyrinthOfLore::Entity::Base*> all_entities;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   AllegroFlare::Inventory player_inventory;
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   LabyrinthOfLoreGame::Interactions interactions;

   LabyrinthOfLoreGame_InteractionsTest()
      : thing_definition_factory()
      , all_entities()
      , thing_dictionary()
      , message_scroll()
      , player_inventory()
      , character_panel(&player_inventory, &thing_dictionary)
      , interactions(&thing_definition_factory, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory)
   {
   }

   virtual void SetUp() override
   {
   }

   virtual void TearDown() override
   {
   }

   //LabyrinthOfLoreGame::Interactions create_simple_talk_interaction_with(int thing_talking_to)
   //{
      //return LabyrinthOfLoreGame::Interactions(thing_talking_to, &thing_definition_factory, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   //}

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




//TEST_F(LabyrinthOfLoreGame_InteractionsTest, can_be_created_without_blowing_up)
//{
   //LabyrinthOfLoreGame::Interactions interactions;
//}



TEST_F(LabyrinthOfLoreGame_InteractionsTest, validate_arguments__will_raise_an_exception_if_it_cannot_find_the_thing_id)
{
   LabyrinthOfLoreGame::ThingDefinitionFactory thing_definition_factory;
   std::vector<LabyrinthOfLore::Entity::Base*> all_entities;
   LabyrinthOfLore::Entity::ThingDictionary thing_dictionary;
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   LabyrinthOfLore::Hud::CharacterPanel character_panel;
   AllegroFlare::Inventory player_inventory;

   LabyrinthOfLoreGame::Interactions interactions(nullptr, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);

   std::string expected_error_message = "Cannot process_thing_talk_click with a nullptr thing_definition_factory";
   ASSERT_THROW_WITH_MESSAGE(interactions.validate_arguments(), std::runtime_error, expected_error_message);
}



TEST_F(LabyrinthOfLoreGame_InteractionsTest, validate_arguments__works_with_the_fixture)
{
   interactions.validate_arguments();
   SUCCEED();
}



/// gameplay event tests

TEST_F(LabyrinthOfLoreGame_InteractionsTest, process_talk__if_you_talk_to_the_man_at_the_entrance_of_the_cave__he_will_say_the_expected_thing)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   //LabyrinthOfLoreGame::Interactions interactions(MAN_AT_THE_ENTRANCE_TO_THE_CAVE, &thing_definition_factory, &all_entities, &thing_dictionary, &message_scroll, &character_panel, &player_inventory);
   std::string expected_thing_to_say = "Hey traveler! Down this cavern is a runestone of immaginable power. If you dare to go, you'll need to keep a lit torch or the darkness will attack you.";

   interactions.process_talk(MAN_AT_THE_ENTRANCE_TO_THE_CAVE);

   ASSERT_SAID(expected_thing_to_say);
}



TEST_F(LabyrinthOfLoreGame_InteractionsTest, process_talk__with_the_torch_of_truth__talking_to__the_man_at_the_entrance_of_the_cave__he_will_say_something_cool)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   player_inventory.add_item(ITEM_TORCH_OF_TRUTH);
   std::string expected_thing_to_say = "Wowza! I thought the infinity torch you got was cool, but this is... this is... unbelievable!!";

   interactions.process_talk(MAN_AT_THE_ENTRANCE_TO_THE_CAVE);

   ASSERT_SAID(expected_thing_to_say);
}



TEST_F(LabyrinthOfLoreGame_InteractionsTest, process_talk__with_the_infinity_torch__talking_to__the_man_at_the_entrance_of_the_cave__he_will_say_the_expected_message)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   player_inventory.add_item(ITEM_INFINITY_TORCH_ID);
   std::string expected_thing_to_say = "You found the Infinity Torch! Amazing! You are surely a seeker of truth! You have a long quest ahead of you, take this.";

   interactions.process_talk(MAN_AT_THE_ENTRANCE_TO_THE_CAVE);

   ASSERT_SAID(expected_thing_to_say);
}



TEST_F(LabyrinthOfLoreGame_InteractionsTest, process_talk__if_you_talk_to_catalina_in_the_village__she_gives_you_the_expected_message)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { CATALINA_IN_THE_VILLAGE_ID, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   std::string expected_thing_to_say = "Hello there young one. Look at you. You have so much life. I've been here for far to long, and miss so deeply my loved ones. I wonder if they still think of me...";

   interactions.process_talk(CATALINA_IN_THE_VILLAGE_ID);
   ASSERT_SAID(expected_thing_to_say);
}


TEST_F(LabyrinthOfLoreGame_InteractionsTest, process_talk__if_you_talk_to_harcourt__when_you_have_at_least_3_torch_fuels__he_will_give_you_a_prophecy)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { HARCOURT_IN_THE_VILLAGE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   player_inventory.add_item(thing_dictionary.create_new_definition({THING_TYPE_TORCH_FUEL, "some", "torch fuel"}));
   player_inventory.add_item(thing_dictionary.create_new_definition({THING_TYPE_TORCH_FUEL, "some", "torch fuel"}));
   player_inventory.add_item(thing_dictionary.create_new_definition({THING_TYPE_TORCH_FUEL, "some", "torch fuel"}));

   std::string expected_thing_to_say = "You look like an avatar I once knew. So strong and powerful, they once saved us all. Maybe you can do the same.";

   interactions.process_talk(HARCOURT_IN_THE_VILLAGE);

   // assert he said the thing
   ASSERT_SAID(expected_thing_to_say);
}



TEST_F(LabyrinthOfLoreGame_InteractionsTest, process_talk__if_you_talk_to_harcourt__when_you_have_less_than_3_torch_fuels__he_will_tell_you_a_message_and_give_you_up_to_3_torch_fuels)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { HARCOURT_IN_THE_VILLAGE, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   std::string expected_thing_to_say = "It's not so great down here. We all do our best to help each other out. You look like you're low on torch fuel. Have some of mine.";

   interactions.process_talk(HARCOURT_IN_THE_VILLAGE);

   // assert he said the thing
   ASSERT_SAID(expected_thing_to_say);
   ASSERT_EQ(3, character_panel.calculate_count_of_type(THING_TYPE_TORCH_FUEL));
}



TEST_F(LabyrinthOfLoreGame_InteractionsTest, process_use__if_you_use_the_letter_to_catalina__on__catalina__then_she_will_give_a_heartwarming_response_give_you_the_amulet_of_magic_and_take_the_letter_to_catalina)
{
   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({
      { CATALINA_IN_THE_VILLAGE_ID, LabyrinthOfLore::Entity::ThingDefinition() },
      { LETTER_TO_CATALINA_ID, LabyrinthOfLore::Entity::ThingDefinition() },
   });

   interactions.process_use(LETTER_TO_CATALINA_ID, CATALINA_IN_THE_VILLAGE_ID);

   std::string expected_thing_said = "What is this!? Oh my! A letter from my loved ones! They haven't forgotten me! I feel young again! I shall repay you with the only thing I have.";
   ASSERT_SAID(expected_thing_said);
   ASSERT_EQ(false, player_inventory.has_item(LETTER_TO_CATALINA_ID));
   ASSERT_EQ(true, player_inventory.has_item(AMULET_OF_MAGIC_ID));
}



