#pragma once


#include <LabyrinthOfLore/Entity/Base.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/Rendering/TileMapWaterMesh.hpp>
#include <LabyrinthOfLore/Shader/DepthDarken.hpp>
#include <allegro5/allegro.h>
#include <vector>


namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class SceneRenderer
      {
      private:
         ALLEGRO_BITMAP* rendering_surface;
         LabyrinthOfLore::Rendering::Camera* camera;
         LabyrinthOfLore::Rendering::TileMapMesh* tile_map_mesh;
         LabyrinthOfLore::Rendering::TileMapWaterMesh* tile_map_water_mesh;
         std::vector<LabyrinthOfLore::Entity::Base*> entities;
         LabyrinthOfLore::Shader::DepthDarken* depth_darken_shader;

      protected:


      public:
         SceneRenderer(ALLEGRO_BITMAP* rendering_surface=nullptr, LabyrinthOfLore::Rendering::Camera* camera=nullptr, LabyrinthOfLore::Rendering::TileMapMesh* tile_map_mesh={}, LabyrinthOfLore::Rendering::TileMapWaterMesh* tile_map_water_mesh={}, std::vector<LabyrinthOfLore::Entity::Base*> entities={}, LabyrinthOfLore::Shader::DepthDarken* depth_darken_shader=nullptr);
         ~SceneRenderer();

         void render();
      };
   }
}



