

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeTexturer.hpp>
#include <sstream>
#include <allegro5/allegro_color.h>


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


std::vector<ALLEGRO_VERTEX> TileMapMeshCubeTexturer::build_textured_cube()
{
if (!tile_atlas) throw std::runtime_error("cannot build_textured_cube with a nullptr tile_atlas");
if (cube_vertexes.size()!=30)
{
   std::stringstream error_message;
   error_message << "cannot build_textured_cube with cube_vertexes that does not have the expected 30 vertexes. ";
   error_message << "The passed cube_vertexes has " << cube_vertexes.size() << " vertexes.";
   throw std::runtime_error(error_message.str());
}

// top face
cube_vertexes[0].u = 0;
cube_vertexes[0].v = 1.0 * 128;
cube_vertexes[1].u = 1.0 * 128;
cube_vertexes[1].v = 0;
cube_vertexes[2].u = 0;
cube_vertexes[2].v = 0;
cube_vertexes[3].u = 1.0 * 128;
cube_vertexes[3].v = 0;
cube_vertexes[4].u = 0;
cube_vertexes[4].v = 1.0 * 128;
cube_vertexes[5].u = 1.0 * 128;
cube_vertexes[5].v = 1.0 * 128;

return cube_vertexes;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


