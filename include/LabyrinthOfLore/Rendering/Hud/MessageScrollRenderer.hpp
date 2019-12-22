#pragma once


#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class MessageScrollRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::MessageScroll* message_scroll;
            allegro_flare::placement3d place;

         public:
            MessageScrollRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::MessageScroll* message_scroll={}, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~MessageScrollRenderer();


         void render();
         };
      }
   }
}



