#pragma once


#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <vector>


namespace LabyrinthOfLoreGame
{
   namespace Maps
   {
      class TheUnderworld
      {
      private:

      public:
         TheUnderworld();
         ~TheUnderworld();


      LabyrinthOfLore::WorldMap::TileMap build_the_underworld();
      std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> build_the_underworld_data();
      };
   }
}



