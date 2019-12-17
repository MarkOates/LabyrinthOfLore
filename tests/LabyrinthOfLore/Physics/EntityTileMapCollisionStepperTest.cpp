
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Physics/EntityTileMapCollisionStepper.hpp>

TEST(LabyrinthOfLore_Physics_EntityTileMapCollisionStepperTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper;
}

TEST(LabyrinthOfLore_Physics_EntityTileMapCollisionStepperTest, run__accepts_reasonable_parameters_without_crashing)
{
   LabyrinthOfLore::WorldMap::TileMap tile_map;
    std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

   LabyrinthOfLore::Physics::EntityTileMapCollisionStepper entity_tile_map_collision_stepper(tile_map, entities);
}

