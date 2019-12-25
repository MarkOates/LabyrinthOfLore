

#include <LabyrinthOfLore/Rendering/TileMapMeshPillarTexturer.hpp>
#include <sstream>
#include <allegro5/allegro_color.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMeshPillarTexturer::TileMapMeshPillarTexturer(Tileo::TileAtlas* tile_atlas, std::vector<ALLEGRO_VERTEX> pillar_vertexes, int tile_index_for_front_and_back_texture, int tile_index_for_right_and_left_texture, int tile_index_for_top_texture)
   : tile_atlas(tile_atlas)
   , pillar_vertexes(pillar_vertexes)
   , tile_index_for_front_and_back_texture(tile_index_for_front_and_back_texture)
   , tile_index_for_right_and_left_texture(tile_index_for_right_and_left_texture)
   , tile_index_for_top_texture(tile_index_for_top_texture)
{
}


TileMapMeshPillarTexturer::~TileMapMeshPillarTexturer()
{
}


std::vector<ALLEGRO_VERTEX> TileMapMeshPillarTexturer::build_textured_pillar(bool scale_for_unit_sized_texture)
{
if (!tile_atlas) throw std::runtime_error("cannot build_textured_pillar with a nullptr tile_atlas");
if (pillar_vertexes.size()!=30)
{
   std::stringstream error_message;
   error_message << "cannot build_textured_pillar with pillar_vertexes that does not have the expected 30 vertexes. ";
   error_message << "The passed pillar_vertexes has " << pillar_vertexes.size() << " vertexes.";
   throw std::runtime_error(error_message.str());
}
ALLEGRO_BITMAP *texture = tile_atlas->get_bitmap();
if (!texture) throw std::runtime_error("Cannot build_textured_pillar with a nullptr tile_atlas bitmap.");

float u1 = 0;
float v1 = 0;
float u2 = 0;
float v2 = 0;

tile_atlas->get_tile_uv(tile_index_for_top_texture, &u1, &v1, &u2, &v2);
// top face
pillar_vertexes[6*0+0].u = u1;
pillar_vertexes[6*0+0].v = v2;//1.0 * 128;
pillar_vertexes[6*0+1].u = u2;//1.0 * 128;
pillar_vertexes[6*0+1].v = v1;
pillar_vertexes[6*0+2].u = u1;
pillar_vertexes[6*0+2].v = v1;
pillar_vertexes[6*0+3].u = u2;//1.0 * 128;
pillar_vertexes[6*0+3].v = v1;
pillar_vertexes[6*0+4].u = u1;
pillar_vertexes[6*0+4].v = v2;//1.0 * 128;
pillar_vertexes[6*0+5].u = u2;//1.0 * 128;
pillar_vertexes[6*0+5].v = v2;//1.0 * 128;

tile_atlas->get_tile_uv(tile_index_for_front_and_back_texture, &u1, &v1, &u2, &v2);
// front face
pillar_vertexes[6*1+0].u = u1;
pillar_vertexes[6*1+0].v = v2;//1.0 * 128;
pillar_vertexes[6*1+1].u = u2;//1.0 * 128;
pillar_vertexes[6*1+1].v = v1;
pillar_vertexes[6*1+2].u = u1;
pillar_vertexes[6*1+2].v = v1;
pillar_vertexes[6*1+3].u = u2;//1.0 * 128;
pillar_vertexes[6*1+3].v = v1;
pillar_vertexes[6*1+4].u = u1;
pillar_vertexes[6*1+4].v = v2;//1.0 * 128;
pillar_vertexes[6*1+5].u = u2;//1.0 * 128;
pillar_vertexes[6*1+5].v = v2;//1.0 * 128;

tile_atlas->get_tile_uv(tile_index_for_right_and_left_texture, &u1, &v1, &u2, &v2);
// right face
pillar_vertexes[6*2+0].u = u1;
pillar_vertexes[6*2+0].v = v2;//1.0 * 128;
pillar_vertexes[6*2+1].u = u2;//1.0 * 128;
pillar_vertexes[6*2+1].v = v1;
pillar_vertexes[6*2+2].u = u1;
pillar_vertexes[6*2+2].v = v1;
pillar_vertexes[6*2+3].u = u2;//1.0 * 128;
pillar_vertexes[6*2+3].v = v1;
pillar_vertexes[6*2+4].u = u1;
pillar_vertexes[6*2+4].v = v2;//1.0 * 128;
pillar_vertexes[6*2+5].u = u2;//1.0 * 128;
pillar_vertexes[6*2+5].v = v2;//1.0 * 128;

tile_atlas->get_tile_uv(tile_index_for_right_and_left_texture, &u1, &v1, &u2, &v2);
// left face
pillar_vertexes[6*3+0].u = u1;
pillar_vertexes[6*3+0].v = v2;//1.0 * 128;
pillar_vertexes[6*3+1].u = u2;//1.0 * 128;
pillar_vertexes[6*3+1].v = v1;
pillar_vertexes[6*3+2].u = u1;
pillar_vertexes[6*3+2].v = v1;
pillar_vertexes[6*3+3].u = u2;//1.0 * 128;
pillar_vertexes[6*3+3].v = v1;
pillar_vertexes[6*3+4].u = u1;
pillar_vertexes[6*3+4].v = v2;//1.0 * 128;
pillar_vertexes[6*3+5].u = u2;//1.0 * 128;
pillar_vertexes[6*3+5].v = v2;//1.0 * 128;

tile_atlas->get_tile_uv(tile_index_for_front_and_back_texture, &u1, &v1, &u2, &v2);
// back face
pillar_vertexes[6*4+0].u = u1;
pillar_vertexes[6*4+0].v = v2;//1.0 * 128;
pillar_vertexes[6*4+1].u = u2;//1.0 * 128;
pillar_vertexes[6*4+1].v = v1;
pillar_vertexes[6*4+2].u = u1;
pillar_vertexes[6*4+2].v = v1;
pillar_vertexes[6*4+3].u = u2;//1.0 * 128;
pillar_vertexes[6*4+3].v = v1;
pillar_vertexes[6*4+4].u = u1;
pillar_vertexes[6*4+4].v = v2;//1.0 * 128;
pillar_vertexes[6*4+5].u = u2;//1.0 * 128;
pillar_vertexes[6*4+5].v = v2;//1.0 * 128;

if (scale_for_unit_sized_texture)
{
   for (auto &pillar_vertex : pillar_vertexes)
   {
      pillar_vertex.u /= al_get_bitmap_width(texture);
      pillar_vertex.v /= -al_get_bitmap_height(texture);
   }
}

return pillar_vertexes;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


