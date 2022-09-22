#pragma once


#include <AllegroFlare/Vec3D.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement3d.h>


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
         void set_perspective_transform(ALLEGRO_BITMAP* surface=nullptr, ALLEGRO_TRANSFORM* transform=nullptr);

      protected:


      public:
         Camera(AllegroFlare::vec3d position={}, float yaw=0.0f, float pitch=0.0f);
         ~Camera();

         AllegroFlare::vec3d &get_position_ref();
         float &get_yaw_ref();
         float &get_pitch_ref();
         void build_custom_reverse_transform(allegro_flare::placement3d* placement=nullptr, ALLEGRO_TRANSFORM* transform=nullptr);
         void start_projection(ALLEGRO_BITMAP* surface=nullptr);
      };
   }
}



