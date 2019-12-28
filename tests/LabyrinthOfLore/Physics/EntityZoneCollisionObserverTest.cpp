
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Physics/EntityZoneCollisionObserver.hpp>

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionObserverTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Physics::EntityZoneCollisionObserver entity_zone_collision_observer;
}

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionObserverTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Physics::EntityZoneCollisionObserver entity_zone_collision_observer;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, entity_zone_collision_observer.run());
}
