#pragma once


#include <LabyrinthOfLore/Hud/RotateCharacterPanelButton.hpp>
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
            LabyrinthOfLore::Hud::RotateCharacterPanelButton* rotate_character_panel_button;
            allegro_flare::placement3d place;

         protected:


         public:
            RotateCharacterPanelButtonRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::RotateCharacterPanelButton* rotate_character_panel_button=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~RotateCharacterPanelButtonRenderer();

            void render();
         };
      }
   }
}



