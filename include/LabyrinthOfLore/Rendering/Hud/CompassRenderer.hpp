#pragma once


#include <LabyrinthOfLore/Hud/Compass.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class CompassRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::Compass* compass;
            allegro_flare::placement3d place;

         protected:


         public:
            CompassRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::Compass* compass=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~CompassRenderer();

            void render();
         };
      }
   }
}



