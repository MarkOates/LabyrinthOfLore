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

      public:
         EntityTileMapCollisionStepper(LabyrinthOfLore::WorldMap::TileMap& tile_map=get_dummy_tile_map(), std::vector<LabyrinthOfLore::Entity::Base*> entities={});
         ~EntityTileMapCollisionStepper();


      static LabyrinthOfLore::WorldMap::TileMap& get_dummy_tile_map();
      void process_step();
      };
   }
}



