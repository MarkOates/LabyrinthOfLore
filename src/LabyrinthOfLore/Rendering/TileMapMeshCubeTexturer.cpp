

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeTexturer.hpp>



namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMeshCubeTexturer::TileMapMeshCubeTexturer(Tileo::TileAtlas* tile_atlas, std::vector<ALLEGRO_VERTEX>* cube, int tile_index_for_front_and_back_texture, int tile_index_for_right_and_left_texture, int tile_index_for_top_texture)
   : tile_atlas(tile_atlas)
   , cube(cube)
   , tile_index_for_front_and_back_texture(tile_index_for_front_and_back_texture)
   , tile_index_for_right_and_left_texture(tile_index_for_right_and_left_texture)
   , tile_index_for_top_texture(tile_index_for_top_texture)
{
}


TileMapMeshCubeTexturer::~TileMapMeshCubeTexturer()
{
}


void TileMapMeshCubeTexturer::apply_textures()
{
if (!tile_atlas) throw std::runtime_error("cannot apply_textures with a nullptr tile_atlas");
if (!cube) throw std::runtime_error("cannot apply_textures with a nullptr cube");
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


