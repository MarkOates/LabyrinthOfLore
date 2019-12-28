
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Physics/EntityZoneCollisionEvent.hpp>

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionEventTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Physics::EntityZoneCollisionEvent entity_zone_collision_event;
}

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionEventTest, has_expected_getters_with_expected_defaults)
{
   LabyrinthOfLore::Physics::EntityZoneCollisionEvent entity_zone_collision_event;
   EXPECT_EQ(-1, entity_zone_collision_event.get_zone_id());
   EXPECT_EQ(nullptr, entity_zone_collision_event.get_entity());
   EXPECT_EQ(LabyrinthOfLore::Physics::COLLISION_EVENT_NONE, entity_zone_collision_event.get_event_type());
}

