
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Physics/EntityZoneCollisionObserver.hpp>

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionObserverTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Physics::EntityZoneCollisionObserver entity_zone_collision_observer;
}

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionObserverTest, get_collided__returns_entities_and_zones_that_are_colliding)
{
   LabyrinthOfLore::Physics::EntityZoneCollisionObserver entity_zone_collision_observer;
   entity_zone_collision_observer.get_collided();
}

