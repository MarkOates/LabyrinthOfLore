#pragma once


#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <vector>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class TileMapLoader
      {
      private:
         std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data;

      public:
         TileMapLoader(std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data={});
         ~TileMapLoader();

         void validate_size_and_integrity();
         LabyrinthOfLore::WorldMap::TileMap build_tile_map();
      };
   }
}



