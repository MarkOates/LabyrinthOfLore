

#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMeshCubeBuilder.hpp>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMesh::TileMapMesh(LabyrinthOfLore::WorldMap::TileMap tile_map, ALLEGRO_BITMAP* texture)
   : tile_map(tile_map)
   , texture(texture)
   , vertexes({})
{
}


TileMapMesh::~TileMapMesh()
{
}


bool TileMapMesh::build()
{
vertexes.clear();

for (unsigned y=0; y<tile_map.get_height(); y++)
{
   for (unsigned x=0; x<tile_map.get_width(); x++)
   {
      LabyrinthOfLore::WorldMap::Tile tile = tile_map.get_tile(x, y);
      std::vector<ALLEGRO_VERTEX> cube = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder().build_cube(x, y, tile.get_height());

      vertexes.insert(vertexes.end(), cube.begin(), cube.end());
   }
}

return true;

}

void TileMapMesh::draw()
{
ALLEGRO_STATE previous_transform_state;
al_store_state(&previous_transform_state, ALLEGRO_STATE_TRANSFORM);

ALLEGRO_TRANSFORM transform;
al_identity_transform(&transform);
al_rotate_transform_3d(&transform, 1, 0, 0, -ALLEGRO_PI/2);
al_rotate_transform_3d(&transform, 0, 1, 0, -ALLEGRO_PI/2);
al_rotate_transform_3d(&transform, 0, 1, 0, -ALLEGRO_PI/2);
//al_rotate_transform_3d(&transform, 0, 0, 1, -ALLEGRO_PI/2);
//al_scale_transform_3d(&transform, 1.0, 1.0, 1.0);
al_translate_transform_3d(&transform, 1.0, 0, 0);

al_use_transform(&transform);

al_draw_prim(&vertexes[0], nullptr, texture, 0, vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

al_restore_state(&previous_transform_state);

}
} // namespace Rendering
} // namespace LabyrinthOfLore


