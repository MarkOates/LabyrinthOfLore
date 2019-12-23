
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeBuilder.hpp>
#include <AllegroFlare/Vec3D.hpp>
#include <AllegroFlare/Useful.hpp> // for build_vertex
#include <allegro5/allegro_color.h>


using AllegroFlare::vec3d;
using AllegroFlare::build_vertex;


void ASSERT_EQ_VERTEX(ALLEGRO_VERTEX first_vertex, ALLEGRO_VERTEX second_vertex)
{
   ASSERT_EQ(first_vertex.x, second_vertex.x);
   ASSERT_EQ(first_vertex.y, second_vertex.y);
   ASSERT_EQ(first_vertex.z, second_vertex.z);
   ASSERT_EQ(first_vertex.u, second_vertex.u);
   ASSERT_EQ(first_vertex.v, second_vertex.v);
}


TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder;
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildA__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildA());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildB__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildB());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildC__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildC());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildD__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildD());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildE__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildE());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildF__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildF());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildG__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildG());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildH__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildH());
}

/// buildN with args

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildA__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(7.0, 11.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildA());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildB__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(8.0, 11.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildB());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildC__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(7, 12.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildC());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildD__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(8.0, 12.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildD());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildE__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(7, 12.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildE());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildF__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(8.0, 12.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildF());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildG__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(7, 11.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildG());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildH__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(8.0, 11.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildH());
}

/// buildN with args (with negative "mul")

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildA__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-7.0, 11.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildA());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildB__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-6.0, 011.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildB());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildC__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-7, 12.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildC());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildD__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-6.0, 12.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildD());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildE__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-7, 12.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildE());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildF__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-6.0, 12.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildF());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildG__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-7, 11.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildG());
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildH__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-6.0, 11.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildH());
}
