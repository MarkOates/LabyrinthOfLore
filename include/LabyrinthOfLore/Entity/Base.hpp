#pragma once


#include <allegro_flare/placement3d.h>
#include <string>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class Base
      {
      private:
         allegro_flare::placement3d placement;
         allegro_flare::placement3d velocity;

      public:
         Base(allegro_flare::placement3d placement={}, allegro_flare::placement3d velocity={});
         ~Base();


         allegro_flare::placement3d &get_placement_ref();
      std::string run();
      };
   }
}



