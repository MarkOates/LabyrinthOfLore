
#include <gtest/gtest.h>

#include <LabyrinthOfLoreGame/EntityTileMapCollisionEventProcessor.hpp>

TEST(LabyrinthOfLoreGame_EntityTileMapCollisionEventProcessorTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLoreGame::EntityTileMapCollisionEventProcessor entity_tile_map_collision_event_processor;
}

TEST(LabyrinthOfLoreGame_EntityTileMapCollisionEventProcessorTest, process__can_be_called_with_minimal_arguments_without_blowing_up)
{
   LabyrinthOfLoreGame::EntityTileMapCollisionEventProcessor entity_tile_map_collision_event_processor;
   entity_tile_map_collision_event_processor.process();
   SUCCEED();
}
