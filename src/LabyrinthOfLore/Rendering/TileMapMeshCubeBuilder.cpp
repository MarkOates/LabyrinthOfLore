

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
int v = 1; //texture ? al_get_bitmap_width(texture) : 1;

//float mul = -1;

std::vector<ALLEGRO_VERTEX> result = {
  // top:
  AllegroFlare::build_vertex(mul*x, y, height, cube_color, 0, 0), // top left triangle
  AllegroFlare::build_vertex(mul*x+1, y, height, cube_color, v, 0),
  AllegroFlare::build_vertex(mul*x, y+1, height, cube_color, 0, v),

  AllegroFlare::build_vertex(mul*x+1, y, height, cube_color, v, 0), // bottom right triangle
  AllegroFlare::build_vertex(mul*x, y+1, height, cube_color, 0, v),
  AllegroFlare::build_vertex(mul*x+1, y+1, height, cube_color, v, v),
};

for (auto &vertex : result)
{
   //vertex.x = -vertex.x;
}

return result;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


