#pragma once


#include <LabyrinthOfLore/Hud/RuneShelf.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class RuneShelfRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::RuneShelf* rune_shelf;
            allegro_flare::placement3d place;

         protected:


         public:
            RuneShelfRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::RuneShelf* rune_shelf=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~RuneShelfRenderer();

            void render();
         };
      }
   }
}



