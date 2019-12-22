#pragma once


#include <LabyrinthOfLore/Hud/TitleText.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class TitleTextRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::TitleText* title_text;
            allegro_flare::placement3d place;

         public:
            TitleTextRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::TitleText* title_text=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~TitleTextRenderer();


         void render();
         };
      }
   }
}



