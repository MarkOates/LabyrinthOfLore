
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Physics/EntityZoneCollisionObserver.hpp>

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionObserverTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Physics::EntityZoneCollisionObserver entity_zone_collision_observer;
}

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionObserverTest, get_collided__can_be_called_with_defaults_and_does_not_blow_up)
{
   LabyrinthOfLore::Physics::EntityZoneCollisionObserver entity_zone_collision_observer;
   entity_zone_collision_observer.get_collided();
   SUCCEED();
}

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionObserverTest, get_collided__returns_entities_and_zones_that_are_colliding)
{
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {
      new LabyrinthOfLore::Entity::Base(nullptr, nullptr, { 0.5, 0.5, 0.5 })
   };
   std::vector<LabyrinthOfLore::WorldMap::Zone*> zones = {
      new LabyrinthOfLore::WorldMap::Zone(0, 0, 0, 1, 1, 1)
   };

   LabyrinthOfLore::Physics::EntityZoneCollisionObserver entity_zone_collision_observer;

   std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> expected_collided = {
      { entities[0], zones[0] },
   };
   std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> actual_collided = entity_zone_collision_observer.get_collided(entities, zones);

   ASSERT_EQ(expected_collided, actual_collided);

   for (auto &entity : entities) delete entity;
   for (auto &zone : zones) delete zone;
}

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionObserverTest, get_collided__does_not_return_entities_and_zones_that_are_not_colliding)
{
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {
      new LabyrinthOfLore::Entity::Base(nullptr, nullptr, { 1.5, -1.5, 0.5 })
   };
   std::vector<LabyrinthOfLore::WorldMap::Zone*> zones = {
      new LabyrinthOfLore::WorldMap::Zone(0, 0, 0, 1, 1, 1)
   };

   LabyrinthOfLore::Physics::EntityZoneCollisionObserver entity_zone_collision_observer;

   std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> expected_collided = {};
   std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> actual_collided = entity_zone_collision_observer.get_collided(entities, zones);

   ASSERT_EQ(expected_collided, actual_collided);

   for (auto &entity : entities) delete entity;
   for (auto &zone : zones) delete zone;
}

TEST(LabyrinthOfLore_Physics_EntityZoneCollisionObserverTest, observe_start_state__will_store_collisions_for_the_passed_entities_and_zones__as_the_starting_state)
{
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {
      new LabyrinthOfLore::Entity::Base(nullptr, nullptr, { 0.5, 0.5, 0.5 })
   };
   std::vector<LabyrinthOfLore::WorldMap::Zone*> zones = {
      new LabyrinthOfLore::WorldMap::Zone(0, 0, 0, 1, 1, 1)
   };

   LabyrinthOfLore::Physics::EntityZoneCollisionObserver entity_zone_collision_observer;
   entity_zone_collision_observer.observe_start_state(entities, zones);

   std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> expected_collided = {
      { entities[0], zones[0] },
   };
   std::vector<std::pair<LabyrinthOfLore::Entity::Base*, LabyrinthOfLore::WorldMap::Zone*>> actual_collided = entity_zone_collision_observer.get_collisions_at_start();

   ASSERT_EQ(expected_collided, actual_collided);

   for (auto &entity : entities) delete entity;
   for (auto &zone : zones) delete zone;
}

