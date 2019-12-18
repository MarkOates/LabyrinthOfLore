#pragma once


#include <AllegroFlare/Vec3D.hpp>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class Camera
      {
      private:
         AllegroFlare::vec3d position;
         float yaw;
         float pitch;

      public:
         Camera(AllegroFlare::vec3d position={}, float yaw=0.0f, float pitch=0.0f);
         ~Camera();


      void start_projection(ALLEGRO_BITMAP* surface=nullptr);
      };
   }
}



