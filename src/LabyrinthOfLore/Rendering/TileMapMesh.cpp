

#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <iostream>
#include <LabyrinthOfLore/Rendering/TileMapMeshPillarBuilder.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMeshPillarTexturer.hpp>
#include <LabyrinthOfLore/WorldMap/TileTypeEnum.hpp>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMesh::TileMapMesh(Tileo::TileAtlas* tile_atlas, LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary, LabyrinthOfLore::WorldMap::TileMap tile_map, ALLEGRO_BITMAP* texture, int offset_to_first_texture_index)
   : tile_atlas(tile_atlas)
   , tile_type_dictionary(tile_type_dictionary)
   , tile_map(tile_map)
   , texture(texture)
   , offset_to_first_texture_index(offset_to_first_texture_index)
   , vertexes({})
{
}


TileMapMesh::~TileMapMesh()
{
}


std::vector<ALLEGRO_VERTEX> TileMapMesh::get_vertexes()
{
   return vertexes;
}


bool TileMapMesh::build()
{
if (!tile_atlas) throw std::runtime_error("cannot apply_textures with a nullptr tile_atlas");

vertexes.clear();
ALLEGRO_BITMAP *texture = tile_atlas->get_bitmap();

for (int y=0; y<tile_map.get_height(); y++)
{
   for (int x=0; x<tile_map.get_width(); x++)
   {
      LabyrinthOfLore::WorldMap::Tile tile = tile_map.get_tile(x, y);
      int tile_type = tile.get_type();

      LabyrinthOfLore::Rendering::TileTypeDefinition tile_type_definition = tile_type_dictionary.find_definition(tile_type);

      if (tile.get_type() == 0)
      {
         // don't create a tile
      }
      else
      {
         LabyrinthOfLore::WorldMap::Tile tile_behind = tile_map.get_tile(x, y-1);
         LabyrinthOfLore::WorldMap::Tile tile_to_the_right = tile_map.get_tile(x+1, y);
         LabyrinthOfLore::WorldMap::Tile tile_to_the_left = tile_map.get_tile(x-1, y);
         LabyrinthOfLore::WorldMap::Tile tile_in_front = tile_map.get_tile(x, y+1);

         float threshold = 0.00001f;
         bool do_not_include_top_face = false;
         bool do_not_include_front_face = false; //(tile_in_front.get_height() >= (tile.get_height() - threshold));
         bool do_not_include_right_face = false; //(tile_to_the_right.get_height() >= (tile.get_height() - threshold));
         bool do_not_include_left_face = false; //(tile_to_the_left.get_height() >= (tile.get_height() - threshold));
         bool do_not_include_back_face = false; //(tile_behind.get_height() >= (tile.get_height() - threshold));

         int texture_index_for_front_and_back = tile_type_definition.get_tile_index_for_front_and_back_texture()+offset_to_first_texture_index;
         int texture_index_for_left_and_right = tile_type_definition.get_tile_index_for_right_and_left_texture()+offset_to_first_texture_index;
         int texture_for_top = tile_type_definition.get_tile_index_for_top_texture()+offset_to_first_texture_index;

         if (tile.get_type() == LabyrinthOfLore::WorldMap::WATER_TILE)
         {
            texture_index_for_front_and_back = 0 + 9*10;
            texture_index_for_left_and_right = 0 + 9*10;
            texture_for_top = 0 + 9*10;
         }
         if (tile.get_type() == LabyrinthOfLore::WorldMap::LAVA_TILE)
         {
            texture_index_for_front_and_back = 1 + 9*10;
            texture_index_for_left_and_right = 1 + 9*10;
            texture_for_top = 1 + 9*10;
         }
         if (tile.get_type() == LabyrinthOfLore::WorldMap::GLOW_WATER_TILE)
         {
            texture_index_for_front_and_back = 2 + 9*10;
            texture_index_for_left_and_right = 2 + 9*10;
            texture_for_top = 2 + 9*10;
         }


         std::vector<ALLEGRO_VERTEX> pillar = {};
         LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder builder(
               x,
               y,
               tile.get_height(),
               do_not_include_top_face,
               do_not_include_front_face,
               do_not_include_right_face,
               do_not_include_left_face,
               do_not_include_back_face
            );
         pillar = builder.build_pillar();
         pillar = LabyrinthOfLore::Rendering::TileMapMeshPillarTexturer(
               tile_atlas,
               pillar,
               texture_index_for_front_and_back,
               texture_index_for_left_and_right,
               texture_for_top,
               builder.needs_partial_height_side_faces_from_top(),
               builder.get_height(),
               do_not_include_top_face,
               do_not_include_front_face,
               do_not_include_right_face,
               do_not_include_left_face,
               do_not_include_back_face
            ).build_textured_pillar();

         vertexes.insert(vertexes.end(), pillar.begin(), pillar.end());
      }
   }
}

for (auto &vertex : vertexes) { float swap = vertex.y; vertex.y = vertex.z; vertex.z = swap; }

std::cout << "TileMapMesh has been built.  The mesh contains " << vertexes.size() << " vertexes.";

return true;

}

void TileMapMesh::draw()
{
ALLEGRO_BITMAP *texture = nullptr;
if (tile_atlas) texture = tile_atlas->get_bitmap();

//ALLEGRO_STATE previous_transform_state;
//al_store_state(&previous_transform_state, ALLEGRO_STATE_TRANSFORM);

//ALLEGRO_TRANSFORM transform;
//al_identity_transform(&transform);
//al_rotate_transform_3d(&transform, 1, 0, 0, -ALLEGRO_PI/2);
//al_rotate_transform_3d(&transform, 0, 1, 0, -ALLEGRO_PI/2);
//al_rotate_transform_3d(&transform, 0, 1, 0, -ALLEGRO_PI/2);
////al_rotate_transform_3d(&transform, 0, 0, 1, -ALLEGRO_PI/2);
////al_scale_transform_3d(&transform, 1.0, 1.0, 1.0);
//al_translate_transform_3d(&transform, 1.0, 0, 0);

//al_use_transform(&transform);

al_draw_prim(&vertexes[0], nullptr, texture, 0, vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

//al_restore_state(&previous_transform_state);

}
} // namespace Rendering
} // namespace LabyrinthOfLore


