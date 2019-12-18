#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement3d.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class SceneRenderer
      {
      private:
         allegro_flare::placement3d camera_view;
         ALLEGRO_BITMAP* rendering_surface;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;
         LabyrinthOfLore::Rendering::Camera* camera;

      public:
         SceneRenderer(allegro_flare::placement3d camera_view={}, ALLEGRO_BITMAP* rendering_surface=nullptr, std::vector<LabyrinthOfLore::Entity::Base*> entities={}, LabyrinthOfLore::Rendering::Camera* camera=nullptr);
         ~SceneRenderer();


      void set_projection(ALLEGRO_BITMAP* bitmap=nullptr, ALLEGRO_TRANSFORM* t=nullptr);
      void prep_render();
      void render();
      };
   }
}



