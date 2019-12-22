
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
