#pragma once


#include <allegro5/allegro.h>
#include <allegro_flare/placement3d.h>
#include <string>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class Base
      {
      private:
         ALLEGRO_BITMAP* bitmap;
         allegro_flare::placement3d placement;
         allegro_flare::placement3d velocity;

      public:
         Base(ALLEGRO_BITMAP* bitmap=nullptr, allegro_flare::placement3d placement={}, allegro_flare::placement3d velocity={});
         ~Base();

         void set_bitmap(ALLEGRO_BITMAP* bitmap);

         ALLEGRO_BITMAP* get_bitmap();
         allegro_flare::placement3d &get_placement_ref();
      std::string run();
      };
   }
}



