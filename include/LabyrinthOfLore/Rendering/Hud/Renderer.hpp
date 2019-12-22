#pragma once


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
            LabyrinthOfLore::Rendering::MousePointer* mouse_pointer;

         public:
            Renderer(ALLEGRO_BITMAP* render_surface=nullptr, LabyrinthOfLore::Rendering::MousePointer* mouse_pointer=nullptr);
            ~Renderer();


         void render();
         };
      }
   }
}



