#pragma once


#include <LabyrinthOfLore/Hud/ViewFrame.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class ViewFrameRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::ViewFrame* view_frame;
            allegro_flare::placement3d place;

         protected:


         public:
            ViewFrameRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::ViewFrame* view_frame=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~ViewFrameRenderer();

            void render();
         };
      }
   }
}



