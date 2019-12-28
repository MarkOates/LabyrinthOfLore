
#include <gtest/gtest.h>

#include <LabyrinthOfLore/WorldMap/Zone.hpp>

using AllegroFlare::vec3d;

TEST(LabyrinthOfLore_WorldMap_ZoneTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::Zone zone;
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, collides__returns_true_when_the_point_lies_inside_the_zone)
{
   LabyrinthOfLore::WorldMap::Zone zone;
   vec3d point(0.2, 0.5, 0.7);
   EXPECT_EQ(true, zone.collides(point));
}
