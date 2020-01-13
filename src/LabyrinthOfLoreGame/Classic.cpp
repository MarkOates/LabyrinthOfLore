

#include <LabyrinthOfLoreGame/Classic.hpp>
#include <LabyrinthOfLore/WorldMap/MultiBitmapFilenameToWorldBuilder.hpp>


namespace LabyrinthOfLoreGame
{


Classic::Classic(AllegroFlare::BitmapBin* bitmap_bin)
   : bitmap_bin(bitmap_bin)
   , initialized(false)
   , clamped_color_shader({})
   , depth_darken_shader({})
   , item_tile_atlas({})
   , character_tile_atlas({})
   , world_texture_tile_atlas({})
   , levels({})
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


Tileo::TileAtlas &Classic::get_character_tile_atlas_ref()
{
   return character_tile_atlas;
}


Tileo::TileAtlas &Classic::get_world_texture_tile_atlas_ref()
{
   return world_texture_tile_atlas;
}


std::map<std::string, LabyrinthOfLore::WorldMap::Level> &Classic::get_levels_ref()
{
   return levels;
}


void Classic::initialize()
{
if (initialized) return;
depth_darken_shader.initialize();
clamped_color_shader.initialize();
item_tile_atlas.load(bitmap_bin->operator[]("item_spritesheet_full.png"), 16, 16, 0);
character_tile_atlas.load(bitmap_bin->operator[]("item_spritesheet_full.png"), 32, 32, 0);
world_texture_tile_atlas.load(bitmap_bin->operator[]("world_texture_tile_atlas-02.png"), 48, 48, 0);

}
} // namespace LabyrinthOfLoreGame


