#pragma once


#include <AllegroFlare/Vec3D.hpp>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class Camera
      {
      private:
         AllegroFlare::vec3d position;

      public:
         Camera(AllegroFlare::vec3d position={});
         ~Camera();


      void start_transform();
      };
   }
}



