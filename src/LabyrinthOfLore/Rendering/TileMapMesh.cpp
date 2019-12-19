

#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <AllegroFlare/Useful.hpp>
#include <allegro5/allegro_color.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMesh::TileMapMesh(LabyrinthOfLore::WorldMap::TileMap tile_map)
   : tile_map(tile_map)
   , vertexes({})
{
}


TileMapMesh::~TileMapMesh()
{
}


std::vector<ALLEGRO_VERTEX> TileMapMesh::build_cube(float x, float y, float height)
{
return {
  // top
  AllegroFlare::build_vertex(x, y, height, al_color_name("orange"), 0, 0), // top left triangle
  AllegroFlare::build_vertex(x+1, y, height, al_color_name("orange"), 1, 0),
  AllegroFlare::build_vertex(x, y+1, height, al_color_name("orange"), 0, 1),

  AllegroFlare::build_vertex(x+1, y, height, al_color_name("orange"), 1, 0), // bottom right triangle
  AllegroFlare::build_vertex(x, y+1, height, al_color_name("orange"), 0, 1),
  AllegroFlare::build_vertex(x+1, y+1, height, al_color_name("orange"), 1, 1),
  //k
};

}

bool TileMapMesh::build()
{
vertexes.clear();

for (unsigned y=0; y<tile_map.get_height(); y++)
{
   for (unsigned x=0; x<tile_map.get_height(); x++)
   {
      LabyrinthOfLore::WorldMap::Tile tile = tile_map.get_tile(x, y);
      std::vector<ALLEGRO_VERTEX> cube = build_cube(x, y, tile.get_height());

      vertexes.insert(vertexes.end(), cube.begin(), cube.end());
   }
}

return true;

}

void TileMapMesh::draw()
{
al_draw_prim(&vertexes[0], nullptr, nullptr, 0, vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

}
} // namespace Rendering
} // namespace LabyrinthOfLore


