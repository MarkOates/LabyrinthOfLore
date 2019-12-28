#pragma once


#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <string>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class Level
      {
      private:
         std::string name;
         float ground_height;
         LabyrinthOfLore::WorldMap::TileMap tile_map;
         LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh;

      public:
         Level(std::string name="Unmade World", float ground_height=1, LabyrinthOfLore::WorldMap::TileMap tile_map={}, LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh={});
         ~Level();


         std::string get_name();
         float get_ground_height();
         LabyrinthOfLore::WorldMap::TileMap get_tile_map();
         LabyrinthOfLore::Rendering::TileMapMesh get_tile_map_mesh();
      };
   }
}



