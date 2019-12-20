#pragma once


#include <LabyrinthOfLore/Rendering/MousePointer.hpp>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class HudRenderer
      {
      private:
         ALLEGRO_BITMAP* render_surface;
         LabyrinthOfLore::Rendering::MousePointer* mouse_pointer;

      public:
         HudRenderer(ALLEGRO_BITMAP* render_surface=nullptr, LabyrinthOfLore::Rendering::MousePointer* mouse_pointer=nullptr);
         ~HudRenderer();


      void render();
      };
   }
}



