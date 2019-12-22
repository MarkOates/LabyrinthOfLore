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
         class RotateCharacterPanelButtonRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::CharacterPanel* rotate_character_panel_button;
            allegro_flare::placement3d place;

         public:
            RotateCharacterPanelButtonRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::CharacterPanel* rotate_character_panel_button=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~RotateCharacterPanelButtonRenderer();


         void render();
         };
      }
   }
}



