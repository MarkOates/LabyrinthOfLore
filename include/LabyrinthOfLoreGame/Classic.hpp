#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/Rendering/TileMapWaterMesh.hpp>
#include <LabyrinthOfLore/Shader/ClampedColor.hpp>
#include <LabyrinthOfLore/Shader/DepthDarken.hpp>
#include <LabyrinthOfLore/WorldMap/Level.hpp>
#include <Tileo/TileAtlas.hpp>
#include <map>
#include <string>


namespace LabyrinthOfLoreGame
{
   class Classic
   {
   private:
      AllegroFlare::BitmapBin* bitmap_bin;
      bool initialized;
      LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
      LabyrinthOfLore::Shader::DepthDarken depth_darken_shader;
      Tileo::TileAtlas item_tile_atlas;
      Tileo::TileAtlas character_tile_atlas;
      Tileo::TileAtlas world_texture_tile_atlas;
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> levels;
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> meshes;
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapWaterMesh> water_meshes;

   public:
      Classic(AllegroFlare::BitmapBin* bitmap_bin=nullptr);
      ~Classic();


      LabyrinthOfLore::Shader::ClampedColor &get_clamped_color_shader_ref();
      LabyrinthOfLore::Shader::DepthDarken &get_depth_darken_shader_ref();
      Tileo::TileAtlas &get_item_tile_atlas_ref();
      Tileo::TileAtlas &get_character_tile_atlas_ref();
      Tileo::TileAtlas &get_world_texture_tile_atlas_ref();
      std::map<std::string, LabyrinthOfLore::WorldMap::Level> &get_levels_ref();
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &get_meshes_ref();
      std::map<std::string, LabyrinthOfLore::Rendering::TileMapWaterMesh> &get_water_meshes_ref();
   void initialize();
   };
}



