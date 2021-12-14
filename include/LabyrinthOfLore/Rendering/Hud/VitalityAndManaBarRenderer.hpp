#pragma once


#include <LabyrinthOfLore/Hud/VitalityAndManaBar.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class VitalityAndManaBarRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::VitalityAndManaBar* vitality_and_mana_bar;
            allegro_flare::placement3d place;

         public:
            VitalityAndManaBarRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::VitalityAndManaBar* vitality_and_mana_bar={}, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~VitalityAndManaBarRenderer();

            void render();
         };
      }
   }
}



