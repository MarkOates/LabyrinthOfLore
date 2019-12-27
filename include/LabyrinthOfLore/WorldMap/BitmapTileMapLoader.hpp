#pragma once


#include <LabyrinthOfLore/WorldMap/TileMap.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>


namespace LabyrinthOfLore
{
   namespace WorldMap
   {
      class BitmapTileMapLoader
      {
      private:
         ALLEGRO_BITMAP* source_bitmap;

      public:
         BitmapTileMapLoader(ALLEGRO_BITMAP* source_bitmap=nullptr);
         ~BitmapTileMapLoader();


      int get_index_column_x();
      ALLEGRO_COLOR pick_color(int x=0, int y=0);
      bool validate();
      ALLEGRO_COLOR pick_index_null_color();
      LabyrinthOfLore::WorldMap::TileMap load();
      };
   }
}



