

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

return cube_vertexes;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


