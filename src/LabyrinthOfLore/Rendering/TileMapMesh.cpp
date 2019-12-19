

#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <AllegroFlare/Random.hpp>
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


ALLEGRO_COLOR TileMapMesh::random_color()
{
static AllegroFlare::Random random;
static std::vector<ALLEGRO_COLOR> colors = {
   al_color_name("orange"),
   al_color_name("dimgray"),
   al_color_name("darkslategray"),
   al_color_name("firebrick"),
   al_color_name("darkolivegreen"),
};
return colors[random.get_random_int(0, colors.size()-1)];

}

std::vector<ALLEGRO_VERTEX> TileMapMesh::build_cube(float x, float y, float height)
{
ALLEGRO_COLOR cube_color = random_color();
return {
  // facing from the top down:

  // top
  AllegroFlare::build_vertex(-x, y, height, cube_color, 0, 0), // top left triangle
  AllegroFlare::build_vertex(-x+1, y, height, cube_color, 1, 0),
  AllegroFlare::build_vertex(-x, y+1, height, cube_color, 0, 1),

  AllegroFlare::build_vertex(-x+1, y, height, cube_color, 1, 0), // bottom right triangle
  AllegroFlare::build_vertex(-x, y+1, height, cube_color, 0, 1),
  AllegroFlare::build_vertex(-x+1, y+1, height, cube_color, 1, 1),

  // right
  //AllegroFlare::build_vertex(-x, y, height, cube_color, 0, 0), // top left triangle
  //AllegroFlare::build_vertex(-x, y+1, height, cube_color, 1, 0),
  //AllegroFlare::build_vertex(-x, y, 0, cube_color, 0, 1),

  //AllegroFlare::build_vertex(-x, y+1, height, cube_color, 1, 0), // bottom right triangle
  //AllegroFlare::build_vertex(-x, y, 0, cube_color, 0, 1),
  //AllegroFlare::build_vertex(-x, y+1, 0, cube_color, 1, 1),

  // bottom
  //AllegroFlare::build_vertex(-x, y+1, height, cube_color, 0, 0), // top left triangle
  //AllegroFlare::build_vertex(-x+1, y+1, height, cube_color, 1, 0),
  //AllegroFlare::build_vertex(-x, y+1, 0, cube_color, 0, 1),

  //AllegroFlare::build_vertex(-x+1, y+1, height, cube_color, 1, 0), // bottom right triangle
  //AllegroFlare::build_vertex(-x, y+1, 0, cube_color, 0, 1),
  //AllegroFlare::build_vertex(-x+1, y+1, 0, cube_color, 1, 1),

  //
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

al_draw_prim(&vertexes[0], nullptr, nullptr, 0, vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

al_restore_state(&previous_transform_state);

}
} // namespace Rendering
} // namespace LabyrinthOfLore


