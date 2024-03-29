

#include <LabyrinthOfLore/Rendering/TileMapMeshPillarTexturer.hpp>

#include <allegro5/allegro_color.h>
#include <cmath>
#include <sstream>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMeshPillarTexturer::TileMapMeshPillarTexturer(Tileo::TileAtlas* tile_atlas, std::vector<ALLEGRO_VERTEX> pillar_vertexes, int tile_index_for_front_and_back_texture, int tile_index_for_right_and_left_texture, int tile_index_for_top_texture, bool needs_partial_height_side_faces_from_top, float height, bool top_face_is_removed, bool front_face_is_removed, bool right_face_is_removed, bool left_face_is_removed, bool back_face_is_removed)
   : tile_atlas(tile_atlas)
   , pillar_vertexes(pillar_vertexes)
   , tile_index_for_front_and_back_texture(tile_index_for_front_and_back_texture)
   , tile_index_for_right_and_left_texture(tile_index_for_right_and_left_texture)
   , tile_index_for_top_texture(tile_index_for_top_texture)
   , needs_partial_height_side_faces_from_top(needs_partial_height_side_faces_from_top)
   , height(height)
   , top_face_is_removed(top_face_is_removed)
   , front_face_is_removed(front_face_is_removed)
   , right_face_is_removed(right_face_is_removed)
   , left_face_is_removed(left_face_is_removed)
   , back_face_is_removed(back_face_is_removed)
{
}


TileMapMeshPillarTexturer::~TileMapMeshPillarTexturer()
{
}


void TileMapMeshPillarTexturer::assign_texture_to_face(int this_face_start_index, int index_num_for_tile, bool needs_partial_height_side_faces_from_top)
{
   if ((this_face_start_index % 6) != 0) throw std::runtime_error("expecting assign_texture_to_face to have a this_face_start_index that is a multiple of 6");

   //float u1 = 0;
   //float v1 = 0;
   //float u2 = 0;
   //float v2 = 0;

   int u1 = 0;
   int v1 = 0;
   int u2 = 0;
   int v2 = 0;

   tile_atlas->get_tile_uv(index_num_for_tile, &u1, &v1, &u2, &v2);
   if (needs_partial_height_side_faces_from_top) { v1 = (v1 - v2) * fmod(height, 1.0) + v2; }
   pillar_vertexes[this_face_start_index+0].u = u1;
   pillar_vertexes[this_face_start_index+0].v = v2;//1.0 * 128;
   pillar_vertexes[this_face_start_index+1].u = u2;//1.0 * 128;
   pillar_vertexes[this_face_start_index+1].v = v1;
   pillar_vertexes[this_face_start_index+2].u = u1;
   pillar_vertexes[this_face_start_index+2].v = v1;
   pillar_vertexes[this_face_start_index+3].u = u2;//1.0 * 128;
   pillar_vertexes[this_face_start_index+3].v = v1;
   pillar_vertexes[this_face_start_index+4].u = u1;
   pillar_vertexes[this_face_start_index+4].v = v2;//1.0 * 128;
   pillar_vertexes[this_face_start_index+5].u = u2;//1.0 * 128;
   pillar_vertexes[this_face_start_index+5].v = v2;//1.0 * 128;
   return;
}

int TileMapMeshPillarTexturer::infer_number_of_front_right_left_back_sets_of_vertexes()
{
   if (pillar_vertexes.size() <= 6) return 0;
   return (pillar_vertexes.size()-6) / 24;
}

std::vector<ALLEGRO_VERTEX> TileMapMeshPillarTexturer::build_textured_pillar(bool scale_for_unit_sized_texture)
{
   if (!tile_atlas) throw std::runtime_error("cannot build_textured_pillar with a nullptr tile_atlas");
   if (pillar_vertexes.size() % 6 != 0)
   {
      std::stringstream error_message;
      error_message << "cannot build_textured_pillar with pillar_vertexes that does not have the expected number of vertexes. ";
      error_message << "Expecting 6 verticies for the top, and then an additional multiple of 6 for each face. ";
      error_message << "The passed pillar_vertexes have/has " << pillar_vertexes.size() << " vertexe(s).";
      throw std::runtime_error(error_message.str());
   }
   ALLEGRO_BITMAP *texture = tile_atlas->get_bitmap();
   if (!texture) throw std::runtime_error("Cannot build_textured_pillar with a nullptr tile_atlas bitmap.");

   float u1 = 0;
   float v1 = 0;
   float u2 = 0;
   float v2 = 0;

   int this_face_start_index = 0;
   int num_vertexes_in_face = 6;

   // top face
   if (!top_face_is_removed)
   {
      assign_texture_to_face(this_face_start_index, tile_index_for_top_texture);
      this_face_start_index += num_vertexes_in_face;
   }


   if (infer_number_of_front_right_left_back_sets_of_vertexes() > 0)
   {
      // front face
      if (!front_face_is_removed)
      {
         assign_texture_to_face(this_face_start_index, tile_index_for_front_and_back_texture, needs_partial_height_side_faces_from_top);
         this_face_start_index += num_vertexes_in_face;
      }

      // right face
      if (!right_face_is_removed)
      {
         assign_texture_to_face(this_face_start_index, tile_index_for_right_and_left_texture, needs_partial_height_side_faces_from_top);
         this_face_start_index += num_vertexes_in_face;
      }

      // left face
      if (!left_face_is_removed)
      {
         assign_texture_to_face(this_face_start_index, tile_index_for_right_and_left_texture, needs_partial_height_side_faces_from_top);
         this_face_start_index += num_vertexes_in_face;
      }

      // back face
      if (!back_face_is_removed)
      {
         assign_texture_to_face(this_face_start_index, tile_index_for_front_and_back_texture, needs_partial_height_side_faces_from_top);
         this_face_start_index += num_vertexes_in_face;
      }
   }

   for (int pass_num=1; pass_num<infer_number_of_front_right_left_back_sets_of_vertexes(); pass_num++)
   {
      // front face
      if (!front_face_is_removed)
      {
         assign_texture_to_face(this_face_start_index, tile_index_for_front_and_back_texture);
         this_face_start_index += num_vertexes_in_face;
      }

      // right face
      if (!right_face_is_removed)
      {
         assign_texture_to_face(this_face_start_index, tile_index_for_right_and_left_texture);
         this_face_start_index += num_vertexes_in_face;
      }

      // left face
      if (!left_face_is_removed)
      {
         assign_texture_to_face(this_face_start_index, tile_index_for_right_and_left_texture);
         this_face_start_index += num_vertexes_in_face;
      }

      // back face
      if (!back_face_is_removed)
      {
         assign_texture_to_face(this_face_start_index, tile_index_for_front_and_back_texture);
         this_face_start_index += num_vertexes_in_face;
      }
   }

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


