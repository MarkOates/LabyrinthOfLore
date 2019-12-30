
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/MessageScroll.hpp>

TEST(LabyrinthOfLore_Hud_MessageScrollTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
}

TEST(LabyrinthOfLore_Hud_MessageScrollTest, initializes_text_with_the_expected_value)
{
   LabyrinthOfLore::Hud::MessageScroll message_scroll;
   std::string expected_string = "Hello, brave soul. Adventure awaits you.";
   EXPECT_EQ(expected_string, message_scroll.get_text());
}

TEST(LabyrinthOfLore_Hud_MessageScrollTest, append_text__will_append_text__starting_on_a_new_line)
{
   LabyrinthOfLore::Hud::MessageScroll message_scroll("Welcome.");
   message_scroll.append_text("Your quest has only just begun...");

   std::string expected_string = "Welcome.\nYour quest has only just begun...";
   EXPECT_EQ(expected_string, message_scroll.get_text());
}

TEST(LabyrinthOfLore_Hud_MessageScrollTest, get_last_3_messages__returns_the_last_3_messages_and_their_timestamps)
{
   LabyrinthOfLore::Hud::MessageScroll message_scroll("Welcome.");
   message_scroll.append_text("Your quest has only just begun...");

   std::string expected_string = "Welcome.\nYour quest has only just begun...";
   EXPECT_EQ(expected_string, message_scroll.get_text());
}
