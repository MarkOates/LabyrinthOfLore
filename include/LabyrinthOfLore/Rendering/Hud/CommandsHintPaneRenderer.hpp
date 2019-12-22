#pragma once


#include <LabyrinthOfLore/Hud/CommandsHintPane.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class CommandsHintPaneRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::CommandsHintPane* commands_hint_pane;
            allegro_flare::placement3d place;

         public:
            CommandsHintPaneRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::CommandsHintPane* commands_hint_pane=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~CommandsHintPaneRenderer();


         void render();
         };
      }
   }
}



