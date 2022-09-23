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

      protected:


      public:
         BitmapFilenameToWorldBuilder(std::string bitmap_source_filename="data/bitmaps/the_underworld.png", float top_height=2.0f, float ground_height=1.0f);
         ~BitmapFilenameToWorldBuilder();

         std::string get_bitmap_source_filename() const;
         float get_top_height() const;
         float get_ground_height() const;
         LabyrinthOfLore::WorldMap::TileMap build();
      };
   }
}



