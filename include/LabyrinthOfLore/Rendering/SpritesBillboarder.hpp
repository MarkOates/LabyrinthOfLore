#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class SpritesBillboarder
      {
      private:
         LabyrinthOfLore::Rendering::Camera camera;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;

      public:
         SpritesBillboarder(LabyrinthOfLore::Rendering::Camera camera={}, std::vector<LabyrinthOfLore::Entity::Base*> entities={});
         ~SpritesBillboarder();

         void process();
      };
   }
}



