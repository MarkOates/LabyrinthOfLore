
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeBuilder.hpp>
#include <AllegroFlare/Vec3D.hpp>


using AllegroFlare::vec3d;


TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder;
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, build_cube__with_no_arguments__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder;
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, build_n__builds_the_expected_named_vertex_point)
{
   float height = 1.0;
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, height, 1.0);

   vec3d expected_vertex = vec3d(0, 0, 0);
   //ASSERT_EQ(expected_vertex, tile_map_mesh_cube_builder.build_a());

   //tile_map_mesh_cube_builder.build_b
      //tile_map_mesh_cube_builder.build_c
      //tile_map_mesh_cube_builder.build_d
      //tile_map_mesh_cube_builder.build_e
      //tile_map_mesh_cube_builder.build_f
      //tile_map_mesh_cube_builder.build_g
      //tile_map_mesh_cube_builder.build_h
}
