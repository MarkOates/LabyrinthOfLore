

#include <LabyrinthOfLore/Rendering/TileMapMeshPillarBuilder.hpp>
#include <AllegroFlare/Useful.hpp>
#include <AllegroFlare/Useful.hpp>
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
   , remove_left_face(false)
{
}


TileMapMeshPillarBuilder::~TileMapMeshPillarBuilder()
{
}


float TileMapMeshPillarBuilder::get_height()
{
   return height;
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
return AllegroFlare::build_vertex(x, (y+1), (int)height, al_color_name("dodgerblue"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildF()
{
return AllegroFlare::build_vertex(x+1, (y+1), (int)height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildG()
{
return AllegroFlare::build_vertex(x, y, (int)height, al_color_name("red"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildH()
{
return AllegroFlare::build_vertex(x+1, y, (int)height, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildA_whole(float height_origin)
{
return AllegroFlare::build_vertex(x, y, height_origin+1, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildB_whole(float height_origin)
{
return AllegroFlare::build_vertex(x+1, y, height_origin+1, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildC_whole(float height_origin)
{
return AllegroFlare::build_vertex(x, (y+1), height_origin+1, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildD_whole(float height_origin)
{
return AllegroFlare::build_vertex(x+1, (y+1), height_origin+1, al_color_name("green"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildE_whole(float height_origin)
{
return AllegroFlare::build_vertex(x, (y+1), height_origin, al_color_name("dodgerblue"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildF_whole(float height_origin)
{
return AllegroFlare::build_vertex(x+1, (y+1), height_origin, al_color_name("white"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildG_whole(float height_origin)
{
return AllegroFlare::build_vertex(x, y, height_origin, al_color_name("red"), 0, 0);
}

ALLEGRO_VERTEX TileMapMeshPillarBuilder::buildH_whole(float height_origin)
{
return AllegroFlare::build_vertex(x+1, y, height_origin, al_color_name("white"), 0, 0);
}

bool TileMapMeshPillarBuilder::needs_partial_height_side_faces_from_top()
{
return !AllegroFlare::basically_equal(height, (int)height, 0.00001f);
}

int TileMapMeshPillarBuilder::infer_number_of_whole_number_cubes_from_bottom()
{
return (int)height;

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
// this is the official ordering:
// top
// front
// right
// left
// back

std::vector<ALLEGRO_VERTEX> result = {};
std::vector<ALLEGRO_VERTEX> partial_height_side_faces_from_top = {};
std::vector<ALLEGRO_VERTEX> whole_height_side_faces_from_bottom = {};

std::vector<ALLEGRO_VERTEX> top_face = {
  // top:
  buildC(),
  buildB(),
  buildA(),
  buildB(),
  buildC(),
  buildD()
};

if (needs_partial_height_side_faces_from_top())
{
   partial_height_side_faces_from_top = {};

   std::vector<ALLEGRO_VERTEX> front_face = {
      // front:
      buildE(),
      buildD(),
      buildC(),
      buildD(),
      buildE(),
      buildF(),
   };

   std::vector<ALLEGRO_VERTEX> right_face = {
      // right: // looks correct
      buildF(),
      buildB(),
      buildD(),
      buildB(),
      buildF(),
      buildH(),
   };

   std::vector<ALLEGRO_VERTEX> left_face = {
      // left: // looks correct
      buildG(),
      buildC(),
      buildA(),
      buildC(),
      buildG(),
      buildE(),
   };

   std::vector<ALLEGRO_VERTEX> back_face = {
      // back:
      buildH(),
      buildA(),
      buildB(),
      buildA(),
      buildH(),
      buildG()
   };

   partial_height_side_faces_from_top.insert(partial_height_side_faces_from_top.end(), front_face.begin(), front_face.end());
   partial_height_side_faces_from_top.insert(partial_height_side_faces_from_top.end(), right_face.begin(), right_face.end());
   partial_height_side_faces_from_top.insert(partial_height_side_faces_from_top.end(), left_face.begin(), left_face.end());
   partial_height_side_faces_from_top.insert(partial_height_side_faces_from_top.end(), back_face.begin(), back_face.end());
}

for (int z=0; z<infer_number_of_whole_number_cubes_from_bottom(); z++)
{
   float height_origin = z;

   std::vector<ALLEGRO_VERTEX> vertexes_from_this_pass = {
      // front:
      buildE_whole(height_origin),
      buildD_whole(height_origin),
      buildC_whole(height_origin),
      buildD_whole(height_origin),
      buildE_whole(height_origin),
      buildF_whole(height_origin),

      // right: // looks correct
      buildF_whole(height_origin),
      buildB_whole(height_origin),
      buildD_whole(height_origin),
      buildB_whole(height_origin),
      buildF_whole(height_origin),
      buildH_whole(height_origin),

      // left: // looks correct
      buildG_whole(height_origin),
      buildC_whole(height_origin),
      buildA_whole(height_origin),
      buildC_whole(height_origin),
      buildG_whole(height_origin),
      buildE_whole(height_origin),

      // back:
      buildH_whole(height_origin),
      buildA_whole(height_origin),
      buildB_whole(height_origin),
      buildA_whole(height_origin),
      buildH_whole(height_origin),
      buildG_whole(height_origin)
   };

   whole_height_side_faces_from_bottom.insert(whole_height_side_faces_from_bottom.begin(), vertexes_from_this_pass.begin(), vertexes_from_this_pass.end());
}

result.insert(result.end(), top_face.begin(), top_face.end());
result.insert(result.end(), partial_height_side_faces_from_top.begin(), partial_height_side_faces_from_top.end());
result.insert(result.end(), whole_height_side_faces_from_bottom.begin(), whole_height_side_faces_from_bottom.end());

for (auto &vertex : result) { float swap = vertex.y; vertex.y = vertex.z; vertex.z = swap; }

return result;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


