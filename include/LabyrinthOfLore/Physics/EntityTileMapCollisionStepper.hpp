#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Physics
   {
      class EntityTileMapCollisionStepper
      {
      private:
         static LabyrinthOfLore::WorldMap::TileMap dummy_tile_map;
         LabyrinthOfLore::WorldMap::TileMap& tile_map;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;
         static float ceiling_height;
         static float floor_height;
         static float auto_ascend_threshold;

      public:
         EntityTileMapCollisionStepper(LabyrinthOfLore::WorldMap::TileMap& tile_map=get_dummy_tile_map(), std::vector<LabyrinthOfLore::Entity::Base*> entities={});
         ~EntityTileMapCollisionStepper();


         static float get_ceiling_height();
         static float get_floor_height();
         static float get_auto_ascend_threshold();
      static LabyrinthOfLore::WorldMap::TileMap& get_dummy_tile_map();
      void process_step();
      };
   }
}



