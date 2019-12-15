#pragma once


#include <AllegroFlare/Model3D.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement3d.h>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class Base
      {
      private:
         ALLEGRO_BITMAP* bitmap;
         AllegroFlare::Model3D* model;
         allegro_flare::placement3d placement;
         allegro_flare::placement3d velocity;
         bool billboard_at_camera;

      public:
         Base(ALLEGRO_BITMAP* bitmap=nullptr, AllegroFlare::Model3D* model=nullptr, allegro_flare::placement3d placement={}, allegro_flare::placement3d velocity={}, bool billboard_at_camera=false);
         ~Base();

         void set_bitmap(ALLEGRO_BITMAP* bitmap);
         void set_model(AllegroFlare::Model3D* model);
         void set_billboard_at_camera(bool billboard_at_camera);

         ALLEGRO_BITMAP* get_bitmap();
         AllegroFlare::Model3D* get_model();
         bool get_billboard_at_camera();
         allegro_flare::placement3d &get_placement_ref();
      };
   }
}


