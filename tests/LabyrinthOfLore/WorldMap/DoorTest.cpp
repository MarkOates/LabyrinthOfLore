
#include <gtest/gtest.h>

#include <LabyrinthOfLore/WorldMap/Door.hpp>

TEST(LabyrinthOfLore_WorldMap_DoorTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::Door door;
}

TEST(LabyrinthOfLore_WorldMap_DoorTest, has_the_expected_getters_and_initializes_with_expected_defaults)
{
   LabyrinthOfLore::WorldMap::Door door;

   EXPECT_EQ("", door.get_level_identifier());
   EXPECT_EQ(0.0f, door.get_spawn_x());
   EXPECT_EQ(0.0f, door.get_spawn_y());
   EXPECT_EQ(0.0f, door.get_spawn_z());
   EXPECT_EQ(0.0f, door.get_spawn_facing_yaw());
}
