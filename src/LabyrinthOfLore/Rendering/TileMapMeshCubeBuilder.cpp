

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


ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildA()
{
   return AllegroFlare::build_vertex(mul*x, y, height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildB()
{
   return AllegroFlare::build_vertex(mul*x+1, y, height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildC()
{
   return AllegroFlare::build_vertex(mul*x, (y+1), height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildD()
{
   return AllegroFlare::build_vertex(mul*x+1, (y+1), height, al_color_name("green"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildE()
{
   return AllegroFlare::build_vertex(mul*x, (y+1), 0, al_color_name("dodgerblue"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildF()
{
   return AllegroFlare::build_vertex(mul*x+1, (y+1), 0, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildG()
{
   return AllegroFlare::build_vertex(mul*x, y, 0, al_color_name("red"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshCubeBuilder::buildH()
{
   return AllegroFlare::build_vertex(mul*x+1, y, 0, al_color_name("white"), 0, 0);
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
   float u = 0;
   float v = 0; //texture ? al_get_bitmap_width(texture) : 1;
   int tile_width = 48;

   //float mul = -1;

   // this is the official ordering:
   // top
   // front
   // right
   // left
   // back

   std::vector<ALLEGRO_VERTEX> result = {
     // top:
     buildC(),
     buildB(),
     buildA(),
     buildB(),
     buildC(),
     buildD(),

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

   for (auto &vertex : result) { float swap = vertex.y; vertex.y = vertex.z; vertex.z = swap; }

   return result;
}


} // namespace Rendering
} // namespace LabyrinthOfLore


