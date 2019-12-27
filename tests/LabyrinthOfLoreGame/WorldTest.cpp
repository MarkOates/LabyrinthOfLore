
#include <gtest/gtest.h>

#include <LabyrinthOfLoreGame/World.hpp>

TEST(LabyrinthOfLoreGame_WorldTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::World world;
}

TEST(LabyrinthOfLoreGame_WorldTest, run__returns_the_expected_response)
{
   LabyrinthOfLoreGame::World world;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, world.run());
}
