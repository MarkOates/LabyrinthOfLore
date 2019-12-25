
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMeshPillarBuilder.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <AllegroFlare/Vec3D.hpp>
#include <AllegroFlare/Useful.hpp> // for build_vertex
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>


using AllegroFlare::vec3d;
using AllegroFlare::build_vertex;


class LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;
   float near_threshold;

   LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest()
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
      if (al_get_current_display()) al_destroy_display(al_get_current_display());
      al_uninstall_system();
   }
};


static void ASSERT_EQ_VERTEX(ALLEGRO_VERTEX first_vertex, ALLEGRO_VERTEX second_vertex)
{
   ASSERT_EQ(first_vertex.x, second_vertex.x);
   ASSERT_EQ(first_vertex.y, second_vertex.y);
   ASSERT_EQ(first_vertex.z, second_vertex.z);
   ASSERT_EQ(first_vertex.u, second_vertex.u);
   ASSERT_EQ(first_vertex.v, second_vertex.v);
}


TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
}

// buildN()

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildA__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildA());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildB__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildB());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildC__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildC());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildD__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildD());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildE__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildE());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildF__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildF());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildG__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.0);
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildG());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildH__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.0);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildH());
}

// buildN() with clamp expectation

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildA__builds_the_expected_named_vertex_point__and_is_unaffected_by_clamping)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.6);
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 3.6, white, 0, 0), tile_map_mesh_pillar_builder.buildA());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildB__builds_the_expected_named_vertex_point__and_is_unaffected_by_clamping)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.6);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 3.6, white, 0, 0), tile_map_mesh_pillar_builder.buildB());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildC__builds_the_expected_named_vertex_point__and_is_unaffected_by_clamping)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.6);
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 3.6, white, 0, 0), tile_map_mesh_pillar_builder.buildC());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildD__builds_the_expected_named_vertex_point__and_is_unaffected_by_clamping)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.6);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 3.6, white, 0, 0), tile_map_mesh_pillar_builder.buildD());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildE__builds_the_expected_named_vertex_point__and_clamps_at_the_bottom_integer_edge)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.6);
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildE());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildF__builds_the_expected_named_vertex_point__and_clamps_at_the_bottom_integer_edge)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.6);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildF());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildG__builds_the_expected_named_vertex_point__and_clamps_at_the_bottom_integer_edge)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.6);
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildG());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildH__builds_the_expected_named_vertex_point__and_clamps_at_the_bottom_integer_edge)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, 3.6);
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 3.0, white, 0, 0), tile_map_mesh_pillar_builder.buildH());
}

// buildN_whole

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildA_whole__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 1.0, white, 0, 0), tile_map_mesh_pillar_builder.buildA_whole());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildB_whole__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 1.0, white, 0, 0), tile_map_mesh_pillar_builder.buildB_whole());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildC_whole__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 1.0, white, 0, 0), tile_map_mesh_pillar_builder.buildC_whole());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildD_whole__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 1.0, white, 0, 0), tile_map_mesh_pillar_builder.buildD_whole());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildE_whole__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, 0, white, 0, 0), tile_map_mesh_pillar_builder.buildE_whole());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildF_whole__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, 0, white, 0, 0), tile_map_mesh_pillar_builder.buildF_whole());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildG_whole__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(0, 0, 0, white, 0, 0), tile_map_mesh_pillar_builder.buildG_whole());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildH_whole__builds_the_expected_named_vertex_point)
{
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, 0, white, 0, 0), tile_map_mesh_pillar_builder.buildH_whole());
}

// buildN_whole with "height_origin" argument

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildA_whole__with_a_height_origin__builds_the_expected_named_vertex_point)
{
   float height_origin = 6.0;
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(0, 0, height_origin+1, white, 0, 0), tile_map_mesh_pillar_builder.buildA_whole(height_origin));
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildB_whole__with_a_height_origin__builds_the_expected_named_vertex_point)
{
   float height_origin = 6.0;
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, height_origin+1, white, 0, 0), tile_map_mesh_pillar_builder.buildB_whole(height_origin));
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildC_whole__with_a_height_origin__builds_the_expected_named_vertex_point)
{
   float height_origin = 6.0;
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, height_origin+1, white, 0, 0), tile_map_mesh_pillar_builder.buildC_whole(height_origin));
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildD_whole__with_a_height_origin__builds_the_expected_named_vertex_point)
{
   float height_origin = 6.0;
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, height_origin+1, white, 0, 0), tile_map_mesh_pillar_builder.buildD_whole(height_origin));
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildE_whole__with_a_height_origin__builds_the_expected_named_vertex_point)
{
   float height_origin = 6.0;
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(0, 1.0, height_origin, white, 0, 0), tile_map_mesh_pillar_builder.buildE_whole(height_origin));
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildF_whole__with_a_height_origin__builds_the_expected_named_vertex_point)
{
   float height_origin = 6.0;
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(1.0, 1.0, height_origin, white, 0, 0), tile_map_mesh_pillar_builder.buildF_whole(height_origin));
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildG_whole__with_a_height_origin__builds_the_expected_named_vertex_point)
{
   float height_origin = 6.0;
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(0, 0, height_origin, white, 0, 0), tile_map_mesh_pillar_builder.buildG_whole(height_origin));
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, buildH_whole__with_a_height_origin__builds_the_expected_named_vertex_point)
{
   float height_origin = 6.0;
   ALLEGRO_COLOR white = al_color_name("white");
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;
   ASSERT_EQ_VERTEX(build_vertex(1.0, 0, height_origin, white, 0, 0), tile_map_mesh_pillar_builder.buildH_whole(height_origin));
}

// other functions

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, needs_partial_height_side_faces_from_top__returns_true_if_the_height_is_not_a_whole_number)
{
   std::vector<float> non_whole_number_heights_to_test = { 0.2, 3.6, 0.001, 0.999, 17.781 };

   for (auto non_whole_number_height_to_test : non_whole_number_heights_to_test)
   {
      LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, non_whole_number_height_to_test);
      EXPECT_EQ(true, tile_map_mesh_pillar_builder.needs_partial_height_side_faces_from_top());
   }
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, needs_partial_height_side_faces_from_top__returns_false_if_the_height_is_not_a_whole_number)
{
   std::vector<float> whole_number_heights_to_test = { 1.0, 6.0, 93.0, 4.0 };

   for (auto whole_number_height_to_test : whole_number_heights_to_test)
   {
      LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder(0, 0, whole_number_height_to_test);
      EXPECT_EQ(false, tile_map_mesh_pillar_builder.needs_partial_height_side_faces_from_top());
   }
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, infer_number_of_whole_number_cubes_from_bottom__returns_the_number_of_whole_height_cubes_to_be_created_from_the_bottom)
{
   LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder tile_map_mesh_pillar_builder;

   tile_map_mesh_pillar_builder = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 0.2);
   ASSERT_EQ(0, tile_map_mesh_pillar_builder.infer_number_of_whole_number_cubes_from_bottom());

   tile_map_mesh_pillar_builder = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 1.0);
   ASSERT_EQ(1, tile_map_mesh_pillar_builder.infer_number_of_whole_number_cubes_from_bottom());

   tile_map_mesh_pillar_builder = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 6.98);
   ASSERT_EQ(6, tile_map_mesh_pillar_builder.infer_number_of_whole_number_cubes_from_bottom());

   tile_map_mesh_pillar_builder = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 6.001);
   ASSERT_EQ(6, tile_map_mesh_pillar_builder.infer_number_of_whole_number_cubes_from_bottom());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, build_pillar__partway_above_the_0_height__returns_the_expected_number_of_vertexes)
{
   std::vector<ALLEGRO_VERTEX> pillar_vertexes = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 0.2).build_pillar();
   ASSERT_EQ(30, pillar_vertexes.size());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, build_pillar__at_a_0_height__returns_only_the_6_vertexes__hint_its_just_the_top_face)
{
   std::vector<ALLEGRO_VERTEX> pillar_vertexes = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 0).build_pillar();
   ASSERT_EQ(6, pillar_vertexes.size());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, build_pillar__partway_above_a_height_of_1__returns_the_expected_number_of_vertexes)
{
   std::vector<ALLEGRO_VERTEX> pillar_vertexes = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 1.7).build_pillar();
   ASSERT_EQ(30+24, pillar_vertexes.size());
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, build_pillar__partway_above_a_whole_number_height__returns_the_expected_number_of_vertexes)
{
   int heights_above = 5;
   std::vector<ALLEGRO_VERTEX> pillar_vertexes = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, heights_above+0.7).build_pillar();
   ASSERT_EQ(30+24*heights_above, pillar_vertexes.size());
}

// facing tests

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, while_rendering_with_the_camera_facing_forward__with_a_non_whole_number_height__renders_a_partial_height_pillar)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, 3, 0), 0, 0); // facing towards the front face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   al_clear_to_color(al_color_name("chartreuse"));
   camera.start_projection(surface);

   std::vector<ALLEGRO_VERTEX> pillar_vertexes = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 1.2).build_pillar();

   al_draw_prim(&pillar_vertexes[0], nullptr, nullptr, 0, pillar_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(2);
   SUCCEED();
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, while_rendering_with_the_camera_the_left_face__with_a_non_whole_number_height__renders_a_partial_height_pillar)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(-3, 0, 0), 0.25, 0); // facing towards the left face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   al_clear_to_color(al_color_name("slategrey"));
   camera.start_projection(surface);

   std::vector<ALLEGRO_VERTEX> pillar_vertexes = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 1.2).build_pillar();

   al_draw_prim(&pillar_vertexes[0], nullptr, nullptr, 0, pillar_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(2);
   SUCCEED();
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, while_rendering_with_the_camera_facing_forward__appears_at_the_top_right_quadrant__near__with_green_in_the_top_right_corner)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, 3, 0), 0, 0); // facing towards the front face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   al_clear_to_color(al_color_name("pink"));
   camera.start_projection(surface);

   std::vector<ALLEGRO_VERTEX> pillar_vertexes = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 1.0).build_pillar();

   // looks like a small flat box in the top right, with green in the top right vertex, a blue "central" vertex on the left of the box,
   // and a red vertex on the box's bottom left.  It should appear that there is no bottom face, and you can see the inside edge on the
   // right where the back side of the green vertex is shown
   al_draw_prim(&pillar_vertexes[0], nullptr, nullptr, 0, pillar_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(2);
   SUCCEED();
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, while_rendering_with_the_camera_facing_down__appears_at_the_bottom_right_quadrant__near__with_green_in_the_bottom_right_corner)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, 0, 3), 0.0, -0.25); // facing towards the top face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   camera.start_projection(surface);
   al_clear_to_color(al_color_name("olive"));

   std::vector<ALLEGRO_VERTEX> pillar_vertexes = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 1.0).build_pillar();

   al_draw_prim(&pillar_vertexes[0], nullptr, nullptr, 0, pillar_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(2);
   SUCCEED();
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshPillarBuilderTest, while_rendering_with_the_camera_facing_right__appears_at_the_top_right_quadrant__distant__with_red_in_the_bottom_left_corner)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(-3, 0, 0), 0.25, 0); // facing towards the left face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   camera.start_projection(surface);
   al_clear_to_color(al_color_name("maroon"));

   std::vector<ALLEGRO_VERTEX> pillar_vertexes = LabyrinthOfLore::Rendering::TileMapMeshPillarBuilder(0, 0, 1.0).build_pillar();

   al_draw_prim(&pillar_vertexes[0], nullptr, nullptr, 0, pillar_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(2);
   SUCCEED();
}

