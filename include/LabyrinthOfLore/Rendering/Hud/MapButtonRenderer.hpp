#pragma once


#include <LabyrinthOfLore/Hud/MapButton.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class MapButtonRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::MapButton* map_button;
            allegro_flare::placement3d place;

         public:
            MapButtonRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::MapButton* map_button=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~MapButtonRenderer();


         void render();
         };
      }
   }
}



