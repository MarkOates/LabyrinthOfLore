

#include <LabyrinthOfLoreGame/Classic.hpp>



namespace LabyrinthOfLoreGame
{


Classic::Classic(AllegroFlare::BitmapBin* bitmap_bin)
   : bitmap_bin(bitmap_bin)
   , initialized(false)
   , clamped_color_shader({})
   , depth_darken_shader({})
   , item_tile_atlas({})
{
}


Classic::~Classic()
{
}


LabyrinthOfLore::Shader::ClampedColor &Classic::get_clamped_color_shader_ref()
{
   return clamped_color_shader;
}


LabyrinthOfLore::Shader::DepthDarken &Classic::get_depth_darken_shader_ref()
{
   return depth_darken_shader;
}


Tileo::TileAtlas &Classic::get_item_tile_atlas_ref()
{
   return item_tile_atlas;
}


void Classic::initialize()
{
if (initialized) return;
depth_darken_shader.initialize();
clamped_color_shader.initialize();
item_tile_atlas.load(bitmap_bin->operator[]("item_spritesheet_full.png"), 16, 16, 0);

}
} // namespace LabyrinthOfLoreGame


