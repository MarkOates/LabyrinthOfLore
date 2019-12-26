#pragma once


#include <LabyrinthOfLore/WorldMap/Tile.hpp>
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


      std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> build_the_underworld_data();
      };
   }
}



