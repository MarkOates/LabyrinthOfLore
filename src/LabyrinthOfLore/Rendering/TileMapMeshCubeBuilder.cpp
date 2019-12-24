

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

std::vector<ALLEGRO_VERTEX> TileMapMeshCubeBuilder::build_cube()
{
ALLEGRO_COLOR cube_color = random_color();
int u = 0;
int v = 0; //texture ? al_get_bitmap_width(texture) : 1;
int tile_width = 48;

//float mul = -1;

int top_u = u;
int top_v = v;
int front_and_back_u = u;
int front_and_back_v = v;
int right_and_left_u = u;
int right_and_left_v = v;

// this is the official ordering:
// top
// front
// right
// left
// back

std::vector<ALLEGRO_VERTEX> result = {
  // top:
  buildA(top_u, top_v),
  buildB(top_u+1, top_v),
  buildC(top_u, top_v+1),
  buildB(top_u+1, top_v),
  buildC(top_u, top_v+1),
  buildD(top_u+1, top_v+1),

  // front:
  buildC(front_and_back_u, front_and_back_v),
  buildD(front_and_back_u+1, front_and_back_v),
  buildE(front_and_back_u, front_and_back_v+1),
  buildD(front_and_back_u+1, front_and_back_v),
  buildE(front_and_back_u, front_and_back_v+1),
  buildF(front_and_back_u+1, front_and_back_v+1),

  // right:
  buildD(right_and_left_u, right_and_left_v),
  buildB(right_and_left_u+1, right_and_left_v),
  buildF(right_and_left_u, right_and_left_v+1),
  buildB(right_and_left_u+1, right_and_left_v),
  buildF(right_and_left_u, right_and_left_v+1),
  buildH(right_and_left_u+1, right_and_left_v+1),

  // left:
  buildA(right_and_left_u, right_and_left_v),
  buildC(right_and_left_u+1, right_and_left_v),
  buildG(right_and_left_u, right_and_left_v+1),
  buildC(right_and_left_u+1, right_and_left_v),
  buildG(right_and_left_u, right_and_left_v+1),
  buildE(right_and_left_u+1, right_and_left_v+1),

  // back:
  buildB(front_and_back_u+1, front_and_back_v),
  buildA(front_and_back_u+1, front_and_back_v),
  buildH(front_and_back_u, front_and_back_v+1),
  buildA(front_and_back_u+1, front_and_back_v),
  buildH(front_and_back_u, front_and_back_v+1),
  buildG(front_and_back_u+1, front_and_back_v+1),
};

for (auto &vertex : result)
{
   //vertex.x = -vertex.x;
}

return result;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


