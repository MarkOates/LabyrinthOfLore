#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <string>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class BitmapFilenameToWorldBuilder
      {
      private:
         std::string bitmap_source_filename;

      public:
         BitmapFilenameToWorldBuilder(std::string bitmap_source_filename="data/bitmaps/the_underworld.png");
         ~BitmapFilenameToWorldBuilder();


         std::string get_bitmap_source_filename();
      LabyrinthOfLore::WorldMap::TileMap build();
      };
   }
}



