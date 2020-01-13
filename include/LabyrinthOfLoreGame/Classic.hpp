#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <LabyrinthOfLore/Shader/ClampedColor.hpp>
#include <LabyrinthOfLore/Shader/DepthDarken.hpp>
#include <Tileo/TileAtlas.hpp>


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

   public:
      Classic(AllegroFlare::BitmapBin* bitmap_bin=nullptr);
      ~Classic();


      LabyrinthOfLore::Shader::ClampedColor &get_clamped_color_shader_ref();
      LabyrinthOfLore::Shader::DepthDarken &get_depth_darken_shader_ref();
      Tileo::TileAtlas &get_item_tile_atlas_ref();
      Tileo::TileAtlas &get_character_tile_atlas_ref();
      Tileo::TileAtlas &get_world_texture_tile_atlas_ref();
   void initialize();
   };
}



