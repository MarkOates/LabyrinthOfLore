#pragma once


#include <AllegroFlare/Vec3D.hpp>
#include <LabyrinthOfLore/Entity/Base.hpp>
#include <allegro_flare/placement3d.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class SpritesBillboarder
      {
      private:
         allegro_flare::placement3d camera_placement;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;

      public:
         SpritesBillboarder(allegro_flare::placement3d camera_placement={}, std::vector<LabyrinthOfLore::Entity::Base*> entities={});
         ~SpritesBillboarder();


      void reverse_rotation(AllegroFlare::vec3d* entity_rotation=nullptr);
      void process();
      };
   }
}



