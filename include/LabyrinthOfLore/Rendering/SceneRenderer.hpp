#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <allegro_flare/placement3d.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class SceneRenderer
      {
      private:
         allegro_flare::placement3d camera;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;

      public:
         SceneRenderer(allegro_flare::placement3d camera={}, std::vector<LabyrinthOfLore::Entity::Base*> entities={});
         ~SceneRenderer();


      void prep_render();
      void render();
      };
   }
}



