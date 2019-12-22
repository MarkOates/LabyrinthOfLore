#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <LabyrinthOfLore/Hud/CommandPanel.hpp>
#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <LabyrinthOfLore/Hud/VitalityAndManaBar.hpp>
#include <LabyrinthOfLore/Rendering/MousePointer.hpp>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class Renderer
         {
         private:
            ALLEGRO_BITMAP* render_surface;
            AllegroFlare::FontBin* font_bin;
            LabyrinthOfLore::Hud::MessageScroll* message_scroll;
            LabyrinthOfLore::Hud::CommandPanel* command_panel;
            LabyrinthOfLore::Hud::VitalityAndManaBar* vitality_and_mana_bar;
            LabyrinthOfLore::Rendering::MousePointer* mouse_pointer;

         public:
            Renderer(ALLEGRO_BITMAP* render_surface=nullptr, AllegroFlare::FontBin* font_bin=nullptr, LabyrinthOfLore::Hud::MessageScroll* message_scroll=nullptr, LabyrinthOfLore::Hud::CommandPanel* command_panel=nullptr, LabyrinthOfLore::Hud::VitalityAndManaBar* vitality_and_mana_bar=nullptr, LabyrinthOfLore::Rendering::MousePointer* mouse_pointer=nullptr);
            ~Renderer();


         void render_message_scroll();
         void render_command_panel();
         void render_vitality_and_mana_bar();
         void render();
         };
      }
   }
}



