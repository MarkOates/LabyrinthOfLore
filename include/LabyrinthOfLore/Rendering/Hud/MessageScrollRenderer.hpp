#pragma once


#include <LabyrinthOfLore/Hud/MessageScroll.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      namespace Hud
      {
         class MessageScrollRenderer
         {
         private:
            ALLEGRO_FONT* font;
            LabyrinthOfLore::Hud::MessageScroll* message_scroll;
            allegro_flare::placement3d place;
            static float message_display_length_sec;
            static int __dirty_total_line_count;
            static ALLEGRO_COLOR __dirty_this_text_color;

         public:
            MessageScrollRenderer(ALLEGRO_FONT* font=nullptr, LabyrinthOfLore::Hud::MessageScroll* message_scroll={}, allegro_flare::placement3d place=allegro_flare::placement3d{});
            ~MessageScrollRenderer();

            float smoothstep(float edge0=0.0f, float edge1=0.0f, float x=0.0f);
            static bool multiline_draw_callback(int line_num=0, const char* line=nullptr, int size=0, void* extra=nullptr);
            void render();
         };
      }
   }
}



