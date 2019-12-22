#pragma once


#include <LabyrinthOfLore/Hud/CommandPanel.hpp>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class CommandPanelRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::CommandPanel* command_panel;
            allegro_flare::placement3d place;

         public:
            CommandPanelRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::CommandPanel* command_panel=nullptr, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~CommandPanelRenderer();


         void render();
         };
      }
   }
}



