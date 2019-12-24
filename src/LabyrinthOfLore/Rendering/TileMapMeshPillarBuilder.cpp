

#include <LabyrinthOfLore/Rendering/TileMapMeshPillarBuilder.hpp>
#include <AllegroFlare/Random.hpp>
#include <AllegroFlare/Useful.hpp>
#include <allegro5/allegro_color.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMeshPillarBuilder::TileMapMeshPillarBuilder(int x, int y, float height)
   : x(x)
   , y(y)
   , height(height)
{
}


TileMapMeshPillarBuilder::~TileMapMeshPillarBuilder()
{
}


ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildA()
{
return AllegroFlare::build_vertex(x, y, height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildB()
{
return AllegroFlare::build_vertex(x+1, y, height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildC()
{
return AllegroFlare::build_vertex(x, (y+1), height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildD()
{
return AllegroFlare::build_vertex(x+1, (y+1), height, al_color_name("green"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildE()
{
return AllegroFlare::build_vertex(x, (y+1), 0, al_color_name("dodgerblue"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildF()
{
return AllegroFlare::build_vertex(x+1, (y+1), 0, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildG()
{
return AllegroFlare::build_vertex(x, y, 0, al_color_name("red"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildH()
{
return AllegroFlare::build_vertex(x+1, y, 0, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildA_whole()
{
return AllegroFlare::build_vertex(x, y, height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildB_whole()
{
return AllegroFlare::build_vertex(x+1, y, height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildC_whole()
{
return AllegroFlare::build_vertex(x, (y+1), height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildD_whole()
{
return AllegroFlare::build_vertex(x+1, (y+1), height, al_color_name("green"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildE_whole()
{
return AllegroFlare::build_vertex(x, (y+1), 0, al_color_name("dodgerblue"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildF_whole()
{
return AllegroFlare::build_vertex(x+1, (y+1), 0, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildG_whole()
{
return AllegroFlare::build_vertex(x, y, 0, al_color_name("red"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildH_whole()
{
return AllegroFlare::build_vertex(x+1, y, 0, al_color_name("white"), 0, 0);
}

ALLEGRO_COLOR TileMapMeshPillarBuilder::random_color()
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

std::vector<ALLEGRO_VERTEX> TileMapMeshPillarBuilder::build_pillar()
{
ALLEGRO_COLOR cube_color = random_color();
float u = 0;
float v = 0; //texture ? al_get_bitmap_width(texture) : 1;
int tile_width = 48;

// this is the official ordering:
// top
// front
// right
// left
// back

int integer_floor_of_the_height = (int)height;

std::vector<ALLEGRO_VERTEX> result = {};

std::vector<ALLEGRO_VERTEX> top_face = {
  // top:
  buildC(),
  buildB(),
  buildA(),
  buildB(),
  buildC(),
  buildD()
};

std::vector<ALLEGRO_VERTEX> side_faces = {
  // front:
  buildE(),
  buildD(),
  buildC(),
  buildD(),
  buildE(),
  buildF(),

  // right: // looks correct
  buildF(),
  buildB(),
  buildD(),
  buildB(),
  buildF(),
  buildH(),

  // left: // looks correct
  buildG(),
  buildC(),
  buildA(),
  buildC(),
  buildG(),
  buildE(),

  // back:
  buildH(),
  buildA(),
  buildB(),
  buildA(),
  buildH(),
  buildG()
};

result.insert(result.begin(), top_face.begin(), top_face.end());
result.insert(result.begin(), side_faces.begin(), side_faces.end());

for (auto &vertex : result) { float swap = vertex.y; vertex.y = vertex.z; vertex.z = swap; }

return result;

}
} // namespace Rendering
} // namespace LabyrinthOfLore

