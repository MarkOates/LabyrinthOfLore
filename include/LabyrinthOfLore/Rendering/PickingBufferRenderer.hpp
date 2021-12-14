#pragma once


#include <AllegroFlare/PickingBuffer.hpp>
#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/Shader/ClampedColor.hpp>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class PickingBufferRenderer
      {
      private:
         AllegroFlare::PickingBuffer* picking_buffer;
         LabyrinthOfLore::Rendering::Camera* camera;
         LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;
         LabyrinthOfLore::Shader::ClampedColor* clamped_color_shader;

      public:
         PickingBufferRenderer(AllegroFlare::PickingBuffer* picking_buffer=nullptr, LabyrinthOfLore::Rendering::Camera* camera=nullptr, LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh={}, std::vector<LabyrinthOfLore::Entity::Base*> entities={}, LabyrinthOfLore::Shader::ClampedColor* clamped_color_shader=nullptr);
         ~PickingBufferRenderer();

         void render();
      };
   }
}



