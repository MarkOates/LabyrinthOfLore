
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <LabyrinthOfLore/WorldMap/PixelRenderer.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>


#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <AllegroFlare/Useful.hpp> // for TAU


class LabyrinthOfLore_WorldMap_PixelRendererTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;
   float near_threshold;

   LabyrinthOfLore_WorldMap_PixelRendererTest()
      : display(nullptr)
      , near_threshold(0.0001f)
   {
   }

   virtual void SetUp() override
   {
      if (al_is_system_installed())
      {
         std::cout << "Warning: This test is expecting to start with allegro in an uninstalled state. "
            << "However, during test setup, allegro is installed. This should be fixed, but in the "
            << "mean time allegro will be uninstalled so that setup can continue as expected."
            << std::endl;
         al_uninstall_system();
      }
      ASSERT_EQ(true, al_init());
      ASSERT_EQ(true, al_init_primitives_addon());
      ASSERT_EQ(true, al_init_image_addon());

      //al_set_new_display_option(ALLEGRO_DEPTH_SIZE, 32, ALLEGRO_SUGGEST);
      //al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
      //ASSERT_EQ(ALLEGRO_OPENGL, al_get_new_display_flags() & ALLEGRO_OPENGL);
      //ASSERT_EQ(ALLEGRO_PROGRAMMABLE_PIPELINE, al_get_new_display_flags() & ALLEGRO_PROGRAMMABLE_PIPELINE);

      ALLEGRO_DISPLAY *display = al_create_display(800, 600);
      ASSERT_NE(nullptr, display);
   }

   virtual void TearDown() override
   {
      if (al_get_current_display()) al_destroy_display(al_get_current_display());
      al_uninstall_system();
   }
};



TEST_F(LabyrinthOfLore_WorldMap_PixelRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::PixelRenderer pixel_renderer;
}

TEST_F(LabyrinthOfLore_WorldMap_PixelRendererTest, run__returns_the_expected_response)
{
   float topmost_wall_height = 2.0;
   float &t = topmost_wall_height;
   float ground_level = 1.0f;
   float &_ = ground_level;

   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = {
      { { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, },
      { { 1, t },  { 1, _+0.25f },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
      { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
      { { 1, t },  { 1, _ },      { 1, _ },     { 1, _ }, { 1, _ }, { 1, _ }, { 1, _ }, { 1, t }, },
      { { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, { 1, t }, },
   };

   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::WorldMap::PixelRenderer pixel_renderer(tile_map);

   ALLEGRO_BITMAP *render = pixel_renderer.create_render();

   ALLEGRO_TRANSFORM transform;
   al_identity_transform(&transform);
   al_scale_transform(&transform, 24, 24);
   al_use_transform(&transform);

   al_draw_bitmap(render, 0, 0, 0);

   al_flip_display();
   //sleep(1);

   al_destroy_bitmap(render);
}

