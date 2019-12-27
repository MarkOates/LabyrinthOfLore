#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <string>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class Map
      {
      private:
         std::string name;
         LabyrinthOfLore::WorldMap::TileMap tile_map;

      public:
         Map(std::string name="Unmade World", LabyrinthOfLore::WorldMap::TileMap tile_map={});
         ~Map();


         std::string get_name();
         LabyrinthOfLore::WorldMap::TileMap get_tile_map();
      };
   }
}



