#pragma once


#include <AllegroFlare/PickingBuffer.hpp>
#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <LabyrinthOfLore/Shader/ClampedColor.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement3d.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class PickingBufferRenderer
      {
      private:
         AllegroFlare::PickingBuffer* picking_buffer;
         allegro_flare::placement3d camera_view;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;
         LabyrinthOfLore::Shader::ClampedColor* clamped_color_shader;
         LabyrinthOfLore::Rendering::Camera* camera;

      public:
         PickingBufferRenderer(AllegroFlare::PickingBuffer* picking_buffer=nullptr, allegro_flare::placement3d camera_view={}, std::vector<LabyrinthOfLore::Entity::Base*> entities={}, LabyrinthOfLore::Shader::ClampedColor* clamped_color_shader=nullptr, LabyrinthOfLore::Rendering::Camera* camera=nullptr);
         ~PickingBufferRenderer();


      void set_projection(ALLEGRO_BITMAP* bitmap=nullptr, ALLEGRO_TRANSFORM* t=nullptr);
      void prep_render();
      void render();
      };
   }
}



