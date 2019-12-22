
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Hud/RuneShelf.hpp>

TEST(LabyrinthOfLore_Hud_RuneShelfTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Hud::RuneShelf rune_shelf;
}

TEST(LabyrinthOfLore_Hud_RuneShelfTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Hud::RuneShelf rune_shelf;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, rune_shelf.run());
}
