#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <string>


namespace LabyrinthOfLoreGame
{
   namespace Maps
   {
      class TheUnderworld
      {
      private:
         std::string bitmap_source_filename;

      public:
         TheUnderworld(std::string bitmap_source_filename="data/bitmaps/the_underworld.png");
         ~TheUnderworld();


         std::string get_bitmap_source_filename();
      LabyrinthOfLore::WorldMap::TileMap build_the_underworld();
      };
   }
}



