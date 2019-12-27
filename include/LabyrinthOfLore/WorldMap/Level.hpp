#pragma once


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
         LabyrinthOfLore::WorldMap::TileMap tile_map;

      public:
         Level(std::string name="Unmade World", LabyrinthOfLore::WorldMap::TileMap tile_map={});
         ~Level();


         std::string get_name();
         LabyrinthOfLore::WorldMap::TileMap get_tile_map();
      };
   }
}



