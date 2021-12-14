#pragma once


#include <AllegroFlare/Vec3D.hpp>
#include <LabyrinthOfLore/Entity/Base.hpp>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Physics
   {
      class GravityStepper
      {
      private:
         std::vector<LabyrinthOfLore::Entity::Base*> entities;
         AllegroFlare::vec3d gravity;

      public:
         GravityStepper(std::vector<LabyrinthOfLore::Entity::Base*> entities={});
         ~GravityStepper();

         void process_step();
      };
   }
}



