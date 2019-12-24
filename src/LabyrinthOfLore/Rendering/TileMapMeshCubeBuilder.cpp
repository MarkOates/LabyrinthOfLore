

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeBuilder.hpp>
#include <AllegroFlare/Random.hpp>
#include <AllegroFlare/Useful.hpp>
#include <allegro5/allegro_color.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMeshCubeBuilder::TileMapMeshCubeBuilder(int x, int y, float height, float mul)
   : x(x)
   , y(y)
   , height(height)
   , mul(mul)
{
}


TileMapMeshCubeBuilder::~TileMapMeshCubeBuilder()
{
}


ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildA(float u, float v)
{
return AllegroFlare::build_vertex(mul*x, y, height, al_color_name("white"), u, v);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildB(float u, float v)
{
return AllegroFlare::build_vertex(mul*x+1, y, height, al_color_name("white"), u, v);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildC(float u, float v)
{
return AllegroFlare::build_vertex(mul*x, (y+1), height, al_color_name("white"), u, v);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildD(float u, float v)
{
return AllegroFlare::build_vertex(mul*x+1, (y+1), height, al_color_name("white"), u, v);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildE(float u, float v)
{
return AllegroFlare::build_vertex(mul*x, (y+1), 0, al_color_name("white"), u, v);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildF(float u, float v)
{
return AllegroFlare::build_vertex(mul*x+1, (y+1), 0, al_color_name("white"), u, v);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildG(float u, float v)
{
return AllegroFlare::build_vertex(mul*x, y, 0, al_color_name("white"), u, v);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildH(float u, float v)
{
return AllegroFlare::build_vertex(mul*x+1, y, 0, al_color_name("white"), u, v);
}

ALLEGRO_COLOR TileMapMeshCubeBuilder::random_color()
{
static AllegroFlare::Random random;
static std::vector<ALLEGRO_COLOR> colors = {
   al_color_name("white"),
   //al_color_name("orange"),
   //al_color_name("dimgray"),
   //al_color_name("darkslategray"),
   //al_color_name("firebrick"),
   //al_color_name("darkolivegreen"),
};
return colors[random.get_random_int(0, colors.size()-1)];

}

std::vector<ALLEGRO_VERTEX> TileMapMeshCubeBuilder::build_cube(float front_and_back_u1, float front_and_back_v1, float front_and_back_u2, float front_and_back_v2, float right_and_left_u1, float right_and_left_v1, float right_and_left_u2, float right_and_left_v2, float top_u1, float top_v1, float top_u2, float top_v2)
{
ALLEGRO_COLOR cube_color = random_color();
float u = 0;
float v = 0; //texture ? al_get_bitmap_width(texture) : 1;
int tile_width = 48;

//float mul = -1;

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

// this is the official ordering:
// top
// front
// right
// left
// back

std::vector<ALLEGRO_VERTEX> result = {
  // top:
  buildA(top_u1, top_v1),
  buildB(top_u2, top_v1),
  buildC(top_u1, top_v2),
  buildB(top_u2, top_v1),
  buildC(top_u1, top_v2),
  buildD(top_u2, top_v2),

  // front:
  buildC(front_and_back_u1, front_and_back_v1),
  buildD(front_and_back_u2, front_and_back_v1),
  buildE(front_and_back_u1, front_and_back_v2),
  buildD(front_and_back_u2, front_and_back_v1),
  buildE(front_and_back_u1, front_and_back_v2),
  buildF(front_and_back_u2, front_and_back_v2),

  // right:
  buildD(right_and_left_u1, right_and_left_v1),
  buildB(right_and_left_u2, right_and_left_v1),
  buildF(right_and_left_u1, right_and_left_v2),
  buildB(right_and_left_u2, right_and_left_v1),
  buildF(right_and_left_u1, right_and_left_v2),
  buildH(right_and_left_u2, right_and_left_v2),

  // left:
  buildA(right_and_left_u1, right_and_left_v1),
  buildC(right_and_left_u2, right_and_left_v1),
  buildG(right_and_left_u1, right_and_left_v2),
  buildC(right_and_left_u2, right_and_left_v1),
  buildG(right_and_left_u1, right_and_left_v2),
  buildE(right_and_left_u2, right_and_left_v2),

  // back:
  buildB(front_and_back_u1, front_and_back_v1),
  buildA(front_and_back_u2, front_and_back_v1),
  buildH(front_and_back_u1, front_and_back_v2),
  buildA(front_and_back_u2, front_and_back_v1),
  buildH(front_and_back_u1, front_and_back_v2),
  buildG(front_and_back_u2, front_and_back_v2),
};

for (auto &vertex : result)
{
   //vertex.x = -vertex.x;
}

return result;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


