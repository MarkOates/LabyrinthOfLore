

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeTexturer.hpp>
#include <sstream>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMeshCubeTexturer::TileMapMeshCubeTexturer(Tileo::TileAtlas* tile_atlas, std::vector<ALLEGRO_VERTEX> cube_vertexes)
   : tile_atlas(tile_atlas)
   , cube_vertexes(cube_vertexes)
{
}


TileMapMeshCubeTexturer::~TileMapMeshCubeTexturer()
{
}


std::vector<ALLEGRO_VERTEX> TileMapMeshCubeTexturer::texture_cube()
{
if (!tile_atlas) throw std::runtime_error("cannot texture_cube with a nullptr tile_atlas");
if (cube_vertexes.size()!=30)
{
   std::stringstream error_message;
   error_message << "cannot texture_cube with cube_vertexes that does not have the expected 30 vertexes. ";
   error_message << "The passed cube_vertexes has " << cube_vertexes.size() << " vertexes.";
   throw std::runtime_error(error_message.str());
}

//float front_and_back_u1 = 0;
//float front_and_back_v1 = 0;
//float front_and_back_u2 = 0;
//float front_and_back_v2 = 0;

//float right_and_left_u1 = 0;
//float right_and_left_v1 = 0;
//float right_and_left_u2 = 0;
//float right_and_left_v2 = 0;

//float top_u1 = 0;
//float top_v1 = 0;
//float top_u2 = 0;
//float top_v2 = 0;

//tile_atlas->get_tile_uv(tile_index_for_top_texture, &top_u1, &top_v1, &top_u2, &top_v2);

//float front_and_back_u1 = u;
//float front_and_back_v1 = v;
//float front_and_back_u2 = u;
//float front_and_back_v2 = v;

//float right_and_left_u1 = u;
//float right_and_left_v1 = v;
//float right_and_left_u2 = u;
//float right_and_left_v2 = v;

//float top_u1 = 0;
//float top_v1 = 0;
//float top_u2 = 0;
//float top_v2 = 0;

//tile_atlas->get_tile_uv(tile_index_for_front_and_back_texture, &front_and_back_u1, &front_and_back_v1, &front_and_back_u2, &front_and_back_v2);
//tile_atlas->get_tile_uv(tile_index_for_right_and_left_texture, &right_and_left_u_u1, &right_and_left_u_v1, &right_and_left_u_u2, &right_and_left_u_v2);
//tile_atlas->get_tile_uv(tile_index_for_top_texture, &top_u1, &top_v1, &top_u2, &top_v2);


return cube_vertexes;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


