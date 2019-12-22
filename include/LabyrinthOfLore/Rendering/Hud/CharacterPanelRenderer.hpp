#pragma once


#include <LabyrinthOfLore/Hud/CharacterPanel.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class CharacterPanelRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::CharacterPanel* character_panel;
            allegro_flare::placement3d place;

         public:
            CharacterPanelRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::CharacterPanel* character_panel=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~CharacterPanelRenderer();


         void render();
         };
      }
   }
}



