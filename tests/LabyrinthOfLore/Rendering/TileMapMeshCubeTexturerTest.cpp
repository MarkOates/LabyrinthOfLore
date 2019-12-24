
#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeTexturer.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>



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
      if (display) al_destroy_display(display);
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
   ASSERT_THROW_WITH_MESSAGE(tile_map_mesh_cube_texturer.build_textured_cube(), std::runtime_error, expected_error_message);
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, build_textured_cube__without_a_cube__returns_an_exception)
{
   Tileo::TileAtlas tile_atlas;
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer(&tile_atlas);
   std::string expected_error_message = "cannot build_textured_cube with cube_vertexes that does not have the expected 30 vertexes. The passed cube_vertexes has 0 vertexes.";
   ASSERT_THROW_WITH_MESSAGE(tile_map_mesh_cube_texturer.build_textured_cube(), std::runtime_error, expected_error_message);
}

TEST_F(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, build_textured_cube__creates_a_cube_with_the_texture_applied)
{
   //AllegroFlare::BitmapBin bitmap_bin;
   //bitmap_bin.set_path("data/bitmaps");
   //tile_atlas.load(bitmap_bin["world_texture_tile_atlas-02.png"], 16*3, 16*3, 0);

   //LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer;
}

