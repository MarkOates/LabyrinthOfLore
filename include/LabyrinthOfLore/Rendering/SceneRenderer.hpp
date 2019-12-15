#pragma once


#include <AllegroFlare/Vec3D.hpp>
#include <LabyrinthOfLore/Entity/Base.hpp>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class SceneRenderer
      {
      private:
         AllegroFlare::vec3d camera_rotation;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;

      public:
         SceneRenderer(AllegroFlare::vec3d camera_rotation={}, std::vector<LabyrinthOfLore::Entity::Base*> entities={});
         ~SceneRenderer();


      void render();
      };
   }
}



