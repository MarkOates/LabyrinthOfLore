

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeTexturer.hpp>
#include <sstream>
#include <allegro5/allegro_color.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMeshCubeTexturer::TileMapMeshCubeTexturer(Tileo::TileAtlas* tile_atlas, std::vector<ALLEGRO_VERTEX> cube_vertexes, int tile_index_for_front_and_back_texture, int tile_index_for_right_and_left_texture, int tile_index_for_top_texture)
   : tile_atlas(tile_atlas)
   , cube_vertexes(cube_vertexes)
   , tile_index_for_front_and_back_texture(tile_index_for_front_and_back_texture)
   , tile_index_for_right_and_left_texture(tile_index_for_right_and_left_texture)
   , tile_index_for_top_texture(tile_index_for_top_texture)
{
}


TileMapMeshCubeTexturer::~TileMapMeshCubeTexturer()
{
}


std::vector<ALLEGRO_VERTEX> TileMapMeshCubeTexturer::build_textured_cube(bool scale_for_unit_sized_texture)
{
   if (!tile_atlas) throw std::runtime_error("cannot build_textured_cube with a nullptr tile_atlas");
   if (cube_vertexes.size()!=30)
   {
      std::stringstream error_message;
      error_message << "cannot build_textured_cube with cube_vertexes that does not have the expected 30 vertexes. ";
      error_message << "The passed cube_vertexes has " << cube_vertexes.size() << " vertexes.";
      throw std::runtime_error(error_message.str());
   }
   ALLEGRO_BITMAP *texture = tile_atlas->get_bitmap();
   if (!texture) throw std::runtime_error("Cannot build_textured_cube with a nullptr tile_atlas bitmap.");

   //float u1 = 0;
   //float v1 = 0;
   //float u2 = 0;
   //float v2 = 0;

   int u1 = 0;
   int v1 = 0;
   int u2 = 0;
   int v2 = 0;

   tile_atlas->get_tile_uv(tile_index_for_top_texture, &u1, &v1, &u2, &v2);
   // top face
   cube_vertexes[6*0+0].u = u1;
   cube_vertexes[6*0+0].v = v2;//1.0 * 128;
   cube_vertexes[6*0+1].u = u2;//1.0 * 128;
   cube_vertexes[6*0+1].v = v1;
   cube_vertexes[6*0+2].u = u1;
   cube_vertexes[6*0+2].v = v1;
   cube_vertexes[6*0+3].u = u2;//1.0 * 128;
   cube_vertexes[6*0+3].v = v1;
   cube_vertexes[6*0+4].u = u1;
   cube_vertexes[6*0+4].v = v2;//1.0 * 128;
   cube_vertexes[6*0+5].u = u2;//1.0 * 128;
   cube_vertexes[6*0+5].v = v2;//1.0 * 128;

   tile_atlas->get_tile_uv(tile_index_for_front_and_back_texture, &u1, &v1, &u2, &v2);
   // front face
   cube_vertexes[6*1+0].u = u1;
   cube_vertexes[6*1+0].v = v2;//1.0 * 128;
   cube_vertexes[6*1+1].u = u2;//1.0 * 128;
   cube_vertexes[6*1+1].v = v1;
   cube_vertexes[6*1+2].u = u1;
   cube_vertexes[6*1+2].v = v1;
   cube_vertexes[6*1+3].u = u2;//1.0 * 128;
   cube_vertexes[6*1+3].v = v1;
   cube_vertexes[6*1+4].u = u1;
   cube_vertexes[6*1+4].v = v2;//1.0 * 128;
   cube_vertexes[6*1+5].u = u2;//1.0 * 128;
   cube_vertexes[6*1+5].v = v2;//1.0 * 128;

   tile_atlas->get_tile_uv(tile_index_for_right_and_left_texture, &u1, &v1, &u2, &v2);
   // right face
   cube_vertexes[6*2+0].u = u1;
   cube_vertexes[6*2+0].v = v2;//1.0 * 128;
   cube_vertexes[6*2+1].u = u2;//1.0 * 128;
   cube_vertexes[6*2+1].v = v1;
   cube_vertexes[6*2+2].u = u1;
   cube_vertexes[6*2+2].v = v1;
   cube_vertexes[6*2+3].u = u2;//1.0 * 128;
   cube_vertexes[6*2+3].v = v1;
   cube_vertexes[6*2+4].u = u1;
   cube_vertexes[6*2+4].v = v2;//1.0 * 128;
   cube_vertexes[6*2+5].u = u2;//1.0 * 128;
   cube_vertexes[6*2+5].v = v2;//1.0 * 128;

   tile_atlas->get_tile_uv(tile_index_for_right_and_left_texture, &u1, &v1, &u2, &v2);
   // left face
   cube_vertexes[6*3+0].u = u1;
   cube_vertexes[6*3+0].v = v2;//1.0 * 128;
   cube_vertexes[6*3+1].u = u2;//1.0 * 128;
   cube_vertexes[6*3+1].v = v1;
   cube_vertexes[6*3+2].u = u1;
   cube_vertexes[6*3+2].v = v1;
   cube_vertexes[6*3+3].u = u2;//1.0 * 128;
   cube_vertexes[6*3+3].v = v1;
   cube_vertexes[6*3+4].u = u1;
   cube_vertexes[6*3+4].v = v2;//1.0 * 128;
   cube_vertexes[6*3+5].u = u2;//1.0 * 128;
   cube_vertexes[6*3+5].v = v2;//1.0 * 128;

   tile_atlas->get_tile_uv(tile_index_for_front_and_back_texture, &u1, &v1, &u2, &v2);
   // back face
   cube_vertexes[6*4+0].u = u1;
   cube_vertexes[6*4+0].v = v2;//1.0 * 128;
   cube_vertexes[6*4+1].u = u2;//1.0 * 128;
   cube_vertexes[6*4+1].v = v1;
   cube_vertexes[6*4+2].u = u1;
   cube_vertexes[6*4+2].v = v1;
   cube_vertexes[6*4+3].u = u2;//1.0 * 128;
   cube_vertexes[6*4+3].v = v1;
   cube_vertexes[6*4+4].u = u1;
   cube_vertexes[6*4+4].v = v2;//1.0 * 128;
   cube_vertexes[6*4+5].u = u2;//1.0 * 128;
   cube_vertexes[6*4+5].v = v2;//1.0 * 128;

   if (scale_for_unit_sized_texture)
   {
      for (auto &cube_vertex : cube_vertexes)
      {
         cube_vertex.u /= al_get_bitmap_width(texture);
         cube_vertex.v /= -al_get_bitmap_height(texture);
      }
   }

   return cube_vertexes;
}
} // namespace Rendering
} // namespace LabyrinthOfLore


