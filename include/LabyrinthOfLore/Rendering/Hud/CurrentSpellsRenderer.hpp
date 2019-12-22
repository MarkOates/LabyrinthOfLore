#pragma once


#include <LabyrinthOfLore/Hud/CurrentSpells.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class CurrentSpellsRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::CurrentSpells* current_spells;
            allegro_flare::placement3d place;

         public:
            CurrentSpellsRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::CurrentSpells* current_spells=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~CurrentSpellsRenderer();


         void render();
         };
      }
   }
}



