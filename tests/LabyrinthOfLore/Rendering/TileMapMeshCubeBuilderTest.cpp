
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeBuilder.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <AllegroFlare/Vec3D.hpp>
#include <AllegroFlare/Useful.hpp> // for build_vertex
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>


using AllegroFlare::vec3d;
using AllegroFlare::build_vertex;


class LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;
   float near_threshold;

   LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest()
      : display(nullptr)
      , near_threshold(0.0001f)
   {
   }

   virtual void SetUp() override
   {
      ASSERT_EQ(false, al_is_system_installed());
      ASSERT_EQ(true, al_init());
      ASSERT_EQ(true, al_init_primitives_addon());
      ASSERT_EQ(true, al_init_image_addon());

      al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST);
      al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
      ASSERT_EQ(ALLEGRO_OPENGL, al_get_new_display_flags() & ALLEGRO_OPENGL);
      ASSERT_EQ(ALLEGRO_PROGRAMMABLE_PIPELINE, al_get_new_display_flags() & ALLEGRO_PROGRAMMABLE_PIPELINE);

      ALLEGRO_DISPLAY *display = al_create_display(800, 600);
      ASSERT_NE(nullptr, display);
   }

   virtual void TearDown() override
   {
      if (display) al_destroy_display(display);
      al_uninstall_system();
   }
};


void ASSERT_EQ_VERTEX(ALLEGRO_VERTEX first_vertex, ALLEGRO_VERTEX second_vertex)
{
   ASSERT_EQ(first_vertex.x, second_vertex.x);
   ASSERT_EQ(first_vertex.y, second_vertex.y);
   ASSERT_EQ(first_vertex.z, second_vertex.z);
   ASSERT_EQ(first_vertex.u, second_vertex.u);
   ASSERT_EQ(first_vertex.v, second_vertex.v);
}


TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder;
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildA__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildA());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildB__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildB());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildC__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildC());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildD__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildD());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildE__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildE());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildF__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildF());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildG__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildG());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildH__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(0, 0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildH());
}

/// buildN with args

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildA__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(7.0, 11.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildA());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildB__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(8.0, 11.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildB());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildC__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(7, 12.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildC());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildD__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(8.0, 12.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildD());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildE__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(7, 12.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildE());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildF__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(8.0, 12.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildF());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildG__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(7, 11.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildG());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildH__with_args__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, 1.0);
   ASSERT_EQ_VERTEX(build_vertex(8.0, 11.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildH());
}

/// buildN with args (with negative "mul")

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildA__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-7.0, 11.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildA());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildB__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-6.0, 011.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildB());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildC__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-7, 12.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildC());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildD__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-6.0, 12.0, 3.0, white, 0, 0), tile_map_mesh_cube_builder.buildD());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildE__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-7, 12.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildE());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildF__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-6.0, 12.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildF());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildG__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-7, 11.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildG());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, buildH__with_args__and_negative_mul__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder tile_map_mesh_cube_builder(7.0, 11.0, 3.0, -1.0);
   ASSERT_EQ_VERTEX(build_vertex(-6.0, 11.0, 0, white, 0, 0), tile_map_mesh_cube_builder.buildH());
}

// facing tests

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, while_rendering_with_the_camera_facing_forward__appears_at_the_top_right_quadrant__near__with_green_in_the_top_right_corner)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0.5, 3, 0.5), 0, 0); // facing towards the front face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   al_clear_to_color(al_color_name("pink"));
   camera.start_projection(surface);

   std::vector<ALLEGRO_VERTEX> cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(0, 0, 1.0, 1.0).build_cube();

   al_draw_prim(&cube_vertexes[0], nullptr, nullptr, 0, cube_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   sleep(2);
   SUCCEED();
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, while_rendering_with_the_camera_facing_down__appears_at_the_bottom_right_quadrant__near__with_green_in_the_bottom_right_corner)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, 0, 3), 0.0, -0.25); // facing towards the top face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   camera.start_projection(surface);
   al_clear_to_color(al_color_name("olive"));

   std::vector<ALLEGRO_VERTEX> cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(0, 0, 1.0, 1.0).build_cube();

   al_draw_prim(&cube_vertexes[0], nullptr, nullptr, 0, cube_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   sleep(2);
   SUCCEED();
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeBuilderTest, while_rendering_with_the_camera_facing_right__appears_at_the_top_right_quadrant__distant__with_red_in_the_bottom_left_corner)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(-3, 0, 0), 0.25, 0); // facing towards the left face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   camera.start_projection(surface);
   al_clear_to_color(al_color_name("maroon"));

   std::vector<ALLEGRO_VERTEX> cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(0, 0, 1.0, 1.0).build_cube();

   al_draw_prim(&cube_vertexes[0], nullptr, nullptr, 0, cube_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   sleep(2);
   SUCCEED();
}

