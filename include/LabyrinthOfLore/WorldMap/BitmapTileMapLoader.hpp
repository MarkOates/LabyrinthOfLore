#pragma once


#include <allegro5/allegro.h>


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


      void load();
      };
   }
}



