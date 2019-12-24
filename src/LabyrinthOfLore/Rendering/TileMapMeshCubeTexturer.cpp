

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

//float front_and_back_u1 = 0;
//float front_and_back_v1 = 0;
//float front_and_back_u2 = 0;
//float front_and_back_v2 = 0;

//float right_and_left_u1 = 0;
//float right_and_left_v1 = 0;
//float right_and_left_u2 = 0;
//float right_and_left_v2 = 0;

float top_u1 = 0;
float top_v1 = 0;
float top_u2 = 0;
float top_v2 = 0;

tile_atlas->get_tile_uv(tile_index_for_top_texture, &top_u1, &top_v1, &top_u2, &top_v2);

return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


