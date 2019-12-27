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


      ALLEGRO_COLOR pick_color(int x=0, int y=0);
      LabyrinthOfLore::WorldMap::TileMap load();
      };
   }
}



