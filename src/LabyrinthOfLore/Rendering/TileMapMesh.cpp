

#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMeshCubeBuilder.hpp>


namespace LabyrinthOfLore
{
namespace Rendering
{


TileMapMesh::TileMapMesh(Tileo::TileAtlas* tile_atlas, LabyrinthOfLore::WorldMap::TileMap tile_map, ALLEGRO_BITMAP* texture)
   : tile_atlas(tile_atlas)
   , tile_map(tile_map)
   , texture(texture)
   , vertexes({})
{
}


TileMapMesh::~TileMapMesh()
{
}


bool TileMapMesh::build()
{
if (!tile_atlas) throw std::runtime_error("cannot apply_textures with a nullptr tile_atlas");

vertexes.clear();

for (int y=0; y<tile_map.get_height(); y++)
{
   for (int x=0; x<tile_map.get_width(); x++)
   {
      LabyrinthOfLore::WorldMap::Tile tile = tile_map.get_tile(x, y);

      float front_and_back_u1 = 0;
      float front_and_back_v1 = 0;
      float front_and_back_u2 = 1;
      float front_and_back_v2 = 1;

      float right_and_left_u1 = 0;
      float right_and_left_v1 = 0;
      float right_and_left_u2 = 1;
      float right_and_left_v2 = 1;

      float top_u1 = 0;
      float top_v1 = 0;
      float top_u2 = 1;
      float top_v2 = 1;

      int tile_index_for_front_and_back_texture = 0;
      int tile_index_for_right_and_left_texture = 0;
      int tile_index_for_top_texture = 0;

      //tile_atlas->get_tile_uv(tile_index_for_front_and_back_texture, &front_and_back_u1, &front_and_back_v1, &front_and_back_u2, &front_and_back_v2);
      //tile_atlas->get_tile_uv(tile_index_for_right_and_left_texture, &right_and_left_u_u1, &right_and_left_u_v1, &right_and_left_u_u2, &right_and_left_u_v2);
      //tile_atlas->get_tile_uv(tile_index_for_top_texture, &top_u1, &top_v1, &top_u2, &top_v2);


      std::vector<ALLEGRO_VERTEX> cube = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(x, y, tile.get_height())
        .build_cube(
          front_and_back_u1,
          front_and_back_v1,
          front_and_back_u2,
          front_and_back_v2,
          right_and_left_u1,
          right_and_left_v1,
          right_and_left_u2,
          right_and_left_v2,
          top_u1,
          top_v1,
          top_u2,
          top_v2
        );

      vertexes.insert(vertexes.end(), cube.begin(), cube.end());
   }
}

return true;

}

void TileMapMesh::draw()
{
//ALLEGRO_BITMAP *texture = nullptr;
//if (tile_atlas) texture = tile_atlas->get_bitmap();

ALLEGRO_STATE previous_transform_state;
al_store_state(&previous_transform_state, ALLEGRO_STATE_TRANSFORM);

ALLEGRO_TRANSFORM transform;
al_identity_transform(&transform);
al_rotate_transform_3d(&transform, 1, 0, 0, -ALLEGRO_PI/2);
al_rotate_transform_3d(&transform, 0, 1, 0, -ALLEGRO_PI/2);
al_rotate_transform_3d(&transform, 0, 1, 0, -ALLEGRO_PI/2);
//al_rotate_transform_3d(&transform, 0, 0, 1, -ALLEGRO_PI/2);
//al_scale_transform_3d(&transform, 1.0, 1.0, 1.0);
al_translate_transform_3d(&transform, 1.0, 0, 0);

al_use_transform(&transform);

al_draw_prim(&vertexes[0], nullptr, texture, 0, vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

al_restore_state(&previous_transform_state);

}
} // namespace Rendering
} // namespace LabyrinthOfLore


