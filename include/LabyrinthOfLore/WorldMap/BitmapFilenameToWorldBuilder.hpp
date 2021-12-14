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
         float top_height;
         float ground_height;

      public:
         BitmapFilenameToWorldBuilder(std::string bitmap_source_filename="data/bitmaps/the_underworld.png", float top_height=2.0f, float ground_height=1.0f);
         ~BitmapFilenameToWorldBuilder();

         std::string get_bitmap_source_filename();
         float get_top_height();
         float get_ground_height();
         LabyrinthOfLore::WorldMap::TileMap build();
      };
   }
}



