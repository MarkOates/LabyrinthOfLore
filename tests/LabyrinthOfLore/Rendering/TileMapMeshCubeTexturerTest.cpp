
#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeTexturer.hpp>
#include <LabyrinthOfLore/Rendering/TileMapMeshCubeBuilder.hpp>
#include <LabyrinthOfLore/Rendering/Camera.hpp>
#include <AllegroFlare/BitmapBin.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>


#define TEST_TEXTURE_FILENAME "/Users/markoates/Repos/LabyrinthOfLore/bin/data/bitmaps/3x3_test_texture.png"




class LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;
   float near_threshold;

   LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest()
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


TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer;
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, build_textured_cube__without_a_tile_atlas_raises_an_exception)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer;
   std::string expected_error_message = "cannot build_textured_cube with a nullptr tile_atlas";
   ASSERT_THROW_WITH_MESSAGE(tile_map_mesh_cube_texturer.build_textured_cube(false), std::runtime_error, expected_error_message);
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, build_textured_cube__without_a_cube__returns_an_exception)
{
   Tileo::TileAtlas tile_atlas;
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer(&tile_atlas);
   std::string expected_error_message = "cannot build_textured_cube with cube_vertexes that does not have the expected 30 vertexes. The passed cube_vertexes has 0 vertexes.";
   ASSERT_THROW_WITH_MESSAGE(tile_map_mesh_cube_texturer.build_textured_cube(false), std::runtime_error, expected_error_message);
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, build_textured_cube__with_a_tile_atlas_that_does_not_have_a_bitmap__raises_an_exception)
{
   Tileo::TileAtlas tile_atlas;
   std::vector<ALLEGRO_VERTEX> cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(0, 0, 1.0, 1.0).build_cube();
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer(&tile_atlas, cube_vertexes);
   std::string expected_error_message = "Cannot build_textured_cube with a nullptr tile_atlas bitmap.";
   ASSERT_THROW_WITH_MESSAGE(tile_map_mesh_cube_texturer.build_textured_cube(false), std::runtime_error, expected_error_message);
}

// facing tests

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, while_rendering_with_the_camera_facing_down_should_see_a2)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, 0, 3), 0, -0.25); // facing down, towards the top face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   ALLEGRO_BITMAP *b = al_load_bitmap(TEST_TEXTURE_FILENAME);
   if (!b) throw std::runtime_error("in test, cannot load test texture \"b\"");
   Tileo::TileAtlas tile_atlas;
   tile_atlas.load(b, al_get_bitmap_width(b)/3, al_get_bitmap_height(b)/3, 0);

   // setup the scene

   camera.start_projection(surface);
   al_clear_to_color(al_color_name("slategray"));
   std::vector<ALLEGRO_VERTEX> cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(0, 0, 1.0, 1.0).build_cube();

   cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer(&tile_atlas, cube_vertexes, 0, 0, 1).build_textured_cube(false);

   // draw the scene

   al_draw_prim(&cube_vertexes[0], nullptr, b, 0, cube_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(1);
   SUCCEED();
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, while_rendering_with_the_camera_facing_towards_the_front_face_should_see_a2)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, 3, 0), 0, 0); // facing towards the front face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   ALLEGRO_BITMAP *b = al_load_bitmap(TEST_TEXTURE_FILENAME);
   if (!b) throw std::runtime_error("in test, cannot load test texture \"b\"");
   Tileo::TileAtlas tile_atlas;
   tile_atlas.load(b, al_get_bitmap_width(b)/3, al_get_bitmap_height(b)/3, 0);

   // setup the scene

   camera.start_projection(surface);
   al_clear_to_color(al_color_name("slategray"));
   std::vector<ALLEGRO_VERTEX> cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(0, 0, 1.0, 1.0).build_cube();

   cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer(&tile_atlas, cube_vertexes, 1, 0, 0).build_textured_cube(false);

   // draw the scene

   al_draw_prim(&cube_vertexes[0], nullptr, b, 0, cube_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(1);
   SUCCEED();
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, while_rendering_with_the_camera_facing_towards_the_right_face_should_see_a2)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(3, 0, 0), -0.25, 0); // facing towards the right face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   ALLEGRO_BITMAP *b = al_load_bitmap(TEST_TEXTURE_FILENAME);
   if (!b) throw std::runtime_error("in test, cannot load test texture \"b\"");
   Tileo::TileAtlas tile_atlas;
   tile_atlas.load(b, al_get_bitmap_width(b)/3, al_get_bitmap_height(b)/3, 0);

   // setup the scene

   camera.start_projection(surface);
   al_clear_to_color(al_color_name("slategray"));
   std::vector<ALLEGRO_VERTEX> cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(0, 0, 1.0, 1.0).build_cube();

   cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer(&tile_atlas, cube_vertexes, 0, 1, 0).build_textured_cube(false);

   // draw the scene

   al_draw_prim(&cube_vertexes[0], nullptr, b, 0, cube_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(1);
   SUCCEED();
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, while_rendering_with_the_camera_facing_towards_the_left_face_should_see_a2)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(-3, 0, 0), 0.25, 0); // facing towards the left face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   ALLEGRO_BITMAP *b = al_load_bitmap(TEST_TEXTURE_FILENAME);
   if (!b) throw std::runtime_error("in test, cannot load test texture \"b\"");
   Tileo::TileAtlas tile_atlas;
   tile_atlas.load(b, al_get_bitmap_width(b)/3, al_get_bitmap_height(b)/3, 0);

   // setup the scene

   camera.start_projection(surface);
   al_clear_to_color(al_color_name("slategray"));
   std::vector<ALLEGRO_VERTEX> cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(0, 0, 1.0, 1.0).build_cube();

   cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer(&tile_atlas, cube_vertexes, 0, 1, 0).build_textured_cube(false);

   // draw the scene

   al_draw_prim(&cube_vertexes[0], nullptr, b, 0, cube_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(1);
   SUCCEED();
}


TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, while_rendering_with_the_camera_facing_towards_the_back_face_should_see_a2)
{
   LabyrinthOfLore::Rendering::Camera camera(AllegroFlare::vec3d(0, -3, 0), 0.5, 0); // facing towards the back face
   ALLEGRO_BITMAP *surface = al_get_backbuffer(al_get_current_display());
   ASSERT_NE(nullptr, surface);

   ALLEGRO_BITMAP *b = al_load_bitmap(TEST_TEXTURE_FILENAME);
   if (!b) throw std::runtime_error("in test, cannot load test texture \"b\"");
   Tileo::TileAtlas tile_atlas;
   tile_atlas.load(b, al_get_bitmap_width(b)/3, al_get_bitmap_height(b)/3, 0);

   // setup the scene

   camera.start_projection(surface);
   al_clear_to_color(al_color_name("slategray"));
   std::vector<ALLEGRO_VERTEX> cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeBuilder(0, 0, 1.0, 1.0).build_cube();

   cube_vertexes = LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer(&tile_atlas, cube_vertexes, 1, 0, 0).build_textured_cube(false);

   // draw the scene

   al_draw_prim(&cube_vertexes[0], nullptr, b, 0, cube_vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   al_flip_display();
   //sleep(1);
   SUCCEED();
}

