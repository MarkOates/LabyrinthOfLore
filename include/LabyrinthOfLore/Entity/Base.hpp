#pragma once


#include <AllegroFlare/ElementID.hpp>
#include <AllegroFlare/Model3D.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement3d.h>
#include <string>


namespace LabyrinthOfLore
{
   namespace Entity
   {
      class Base : public AllegroFlare::ElementID
      {
      private:
         ALLEGRO_BITMAP* bitmap;
         AllegroFlare::Model3D* model;
         std::string identifier_for_level_within;
         allegro_flare::placement3d placement;
         allegro_flare::placement3d velocity;
         bool billboard_at_camera;

      protected:


      public:
         Base(ALLEGRO_BITMAP* bitmap=nullptr, AllegroFlare::Model3D* model=nullptr, std::string identifier_for_level_within="", allegro_flare::placement3d placement={}, allegro_flare::placement3d velocity={}, bool billboard_at_camera=false);
         ~Base();

         void set_bitmap(ALLEGRO_BITMAP* bitmap);
         void set_model(AllegroFlare::Model3D* model);
         void set_identifier_for_level_within(std::string identifier_for_level_within);
         void set_billboard_at_camera(bool billboard_at_camera);
         ALLEGRO_BITMAP* get_bitmap() const;
         AllegroFlare::Model3D* get_model() const;
         std::string get_identifier_for_level_within() const;
         bool get_billboard_at_camera() const;
         allegro_flare::placement3d &get_placement_ref();
         allegro_flare::placement3d &get_velocity_ref();
      };
   }
}



