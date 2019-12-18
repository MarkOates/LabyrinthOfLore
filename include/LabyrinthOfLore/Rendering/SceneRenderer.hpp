#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <allegro5/allegro.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class SceneRenderer
      {
      private:
         ALLEGRO_BITMAP* rendering_surface;
         LabyrinthOfLore::Rendering::Camera* camera;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;

      public:
         SceneRenderer(ALLEGRO_BITMAP* rendering_surface=nullptr, LabyrinthOfLore::Rendering::Camera* camera=nullptr, std::vector<LabyrinthOfLore::Entity::Base*> entities={});
         ~SceneRenderer();


      void render();
      };
   }
}



