#pragma once


#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <vector>


namespace LabyrinthOfLoreGame
{
   namespace Maps
   {
      class Construct
      {
      private:

      public:
         Construct();
         ~Construct();


      std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> build_construct_tile_map_data();
      std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> build_the_underworld_data();
      };
   }
}



