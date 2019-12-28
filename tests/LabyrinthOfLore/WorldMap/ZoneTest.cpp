
#include <gtest/gtest.h>

#include <LabyrinthOfLore/WorldMap/Zone.hpp>

using AllegroFlare::vec3d;
static const float FLOAT_THRESHOLD = 0.00001f;

TEST(LabyrinthOfLore_WorldMap_ZoneTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::Zone zone;
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, has_expected_getters_with_expected_default_values)
{
   LabyrinthOfLore::WorldMap::Zone zone;
   EXPECT_EQ(0.0, zone.get_x1());
   EXPECT_EQ(0.0, zone.get_y1());
   EXPECT_EQ(0.0, zone.get_z1());
   EXPECT_EQ(1.0, zone.get_x2());
   EXPECT_EQ(1.0, zone.get_y2());
   EXPECT_EQ(1.0, zone.get_z2());
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, assigns_values_in_the_expected_order_during_construction)
{
   LabyrinthOfLore::WorldMap::Zone zone(1.3, 2.2, 3.1, 4.0, 5.9, 6.8);
   EXPECT_NEAR(1.3, zone.get_x1(), FLOAT_THRESHOLD);
   EXPECT_NEAR(2.2, zone.get_y1(), FLOAT_THRESHOLD);
   EXPECT_NEAR(3.1, zone.get_z1(), FLOAT_THRESHOLD);
   EXPECT_NEAR(4.0, zone.get_x2(), FLOAT_THRESHOLD);
   EXPECT_NEAR(5.9, zone.get_y2(), FLOAT_THRESHOLD);
   EXPECT_NEAR(6.8, zone.get_z2(), FLOAT_THRESHOLD);
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, collides__returns_true_when_the_point_lies_inside_the_zone)
{
   LabyrinthOfLore::WorldMap::Zone zone;
   vec3d point(0.2, 0.5, 0.7);
   EXPECT_EQ(true, zone.collides(point));
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, collides__returns_false_when_the_point_lies_outside_the_zone_to_the_right)
{
   LabyrinthOfLore::WorldMap::Zone zone;
   vec3d point(0.2+1.0, 0.5, 0.7);
   EXPECT_EQ(false, zone.collides(point));
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, collides__returns_false_when_the_point_lies_inside_the_zone_to_the_left)
{
   LabyrinthOfLore::WorldMap::Zone zone;
   vec3d point(0.2-1.0, 0.5, 0.7);
   EXPECT_EQ(false, zone.collides(point));
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, collides__returns_false_when_the_point_lies_outside_the_zone_to_the_back)
{
   LabyrinthOfLore::WorldMap::Zone zone;
   vec3d point(0.2, 0.5+1.0, 0.7);
   EXPECT_EQ(false, zone.collides(point));
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, collides__returns_false_when_the_point_lies_inside_the_zone_to_the_front)
{
   LabyrinthOfLore::WorldMap::Zone zone;
   vec3d point(0.2, 0.5-1.0, 0.7);
   EXPECT_EQ(false, zone.collides(point));
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, collides__returns_false_when_the_point_lies_outside_the_zone_below)
{
   LabyrinthOfLore::WorldMap::Zone zone;
   vec3d point(0.2, 0.5, 0.7+1.0);
   EXPECT_EQ(false, zone.collides(point));
}

TEST(LabyrinthOfLore_WorldMap_ZoneTest, collides__returns_false_when_the_point_lies_inside_the_zone_above)
{
   LabyrinthOfLore::WorldMap::Zone zone;
   vec3d point(0.2, 0.5, 0.7-1.0);
   EXPECT_EQ(false, zone.collides(point));
}

