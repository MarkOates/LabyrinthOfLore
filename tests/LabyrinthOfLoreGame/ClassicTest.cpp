
#include <gtest/gtest.h>

#include <LabyrinthOfLoreGame/Classic.hpp>

TEST(LabyrinthOfLoreGame_ClassicTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::Classic classic;
}

TEST(LabyrinthOfLoreGame_ClassicTest, run__returns_the_expected_response)
{
   LabyrinthOfLoreGame::Classic classic;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, classic.run());
}
