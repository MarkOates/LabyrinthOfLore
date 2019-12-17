
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Physics/EntityTileMapCollisionStepper.hpp>

TEST(LabyrinthOfLore_Physics_EntityTileMapCollisionStepperTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper;
}

TEST(LabyrinthOfLore_Physics_EntityTileMapCollisionStepperTest, accepts_reasonable_arguments_without_crashing)
{
   LabyrinthOfLore::WorldMap::TileMap tile_map;
    std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

   LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper(tile_map, entities);
   SUCCEED();
}

TEST(LabyrinthOfLore_Physics_EntityTileMapCollisionStepperTest, process_step__works_with_reasonable_arguments)
{
   LabyrinthOfLore::WorldMap::TileMap tile_map;
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

   LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper(tile_map, entities);

   entity_tile_map_collision_stepper.process_step();
   SUCCEED();
}

TEST(LabyrinthOfLore_Physics_EntityTileMapCollisionStepperTest,
      with_an_entity__process_step__steps_the_entity_forward_by_its_velocity)
{
   LabyrinthOfLore::WorldMap::TileMap tile_map;
   tile_map.resize(10, 10, LabyrinthOfLore::WorldMap::Tile(0, 10.0));
   LabyrinthOfLore::Entity::Base entity = LabyrinthOfLore::Entity::Base();
   std::vector<LabyrinthOfLore::Entity::Base*> entities = { &entity };

   entity.get_placement_ref().position = AllegroFlare::vec3d(0.0, 0.0, 10.01);
   entity.get_velocity_ref().position = AllegroFlare::vec3d(0.3, 0.4, 0.2);

   LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper(tile_map, entities);
   entity_tile_map_collision_stepper.process_step();

   allegro_flare::placement3d actual_placement = entity.get_placement_ref();
   EXPECT_EQ(0.3f, actual_placement.position.x);
   EXPECT_EQ(0.4f, actual_placement.position.y);
   EXPECT_EQ(10.21f, actual_placement.position.z);
}

TEST(LabyrinthOfLore_Physics_EntityTileMapCollisionStepperTest,
      with_an_entity__process_step__does_not_advance_the_player_if_the_colliding_block_is_higher_by_more_than_half_a_unit_of_height)
{
   LabyrinthOfLore::WorldMap::TileMap tile_map;
   tile_map.resize(2, 1, LabyrinthOfLore::WorldMap::Tile(0, 10.0));
   LabyrinthOfLore::Entity::Base entity = LabyrinthOfLore::Entity::Base();
   std::vector<LabyrinthOfLore::Entity::Base*> entities = { &entity };

   entity.get_placement_ref().position = AllegroFlare::vec3d(0.5, 0.5, 10.01);
   entity.get_velocity_ref().position = AllegroFlare::vec3d(1.0, 0.0, 0.0);
   tile_map.set_tile(1, 0, LabyrinthOfLore::WorldMap::Tile(0, 10.0 + 0.6));

   LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper(tile_map, entities);
   entity_tile_map_collision_stepper.process_step();

   allegro_flare::placement3d actual_placement = entity.get_placement_ref();
   EXPECT_EQ(0.5f, actual_placement.position.x);
   EXPECT_EQ(0.5f, actual_placement.position.y);
   EXPECT_EQ(10.01f, actual_placement.position.z);

   entity_tile_map_collision_stepper.process_step();
}

