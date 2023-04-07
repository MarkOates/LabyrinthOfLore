
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Gameplay/Screen.hpp>

#include <AllegroFlare/Testing/WithAllegroRenderingFixture.hpp>
#include <AllegroFlare/Testing/WithAllegroFlareFrameworksFullFixture.hpp>
//#include <AllegroFlare/Frameworks/Full.hpp>

class LabyrinthOfLore_Gameplay_ScreenTest : public ::testing::Test {};
class LabyrinthOfLore_Gameplay_ScreenTestWithAllegroRenderingFixture
   : public AllegroFlare::Testing::WithAllegroRenderingFixture
{};
class LabyrinthOfLore_Gameplay_ScreenTestWithAllegroFrameworksFullFixture
   : public AllegroFlare::Testing::WithAllegroFlareFrameworksFullFixture
{};



TEST_F(LabyrinthOfLore_Gameplay_ScreenTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Gameplay::Screen screen;
}


TEST_F(LabyrinthOfLore_Gameplay_ScreenTest, TYPE__has_the_expected_value)
{
   LabyrinthOfLore::Gameplay::Screen screen;
   EXPECT_EQ("LabyrinthOfLore/Gameplay/Screen", screen.get_type());
}


TEST_F(LabyrinthOfLore_Gameplay_ScreenTest, type__has_the_expected_value_matching_TYPE)
{
   LabyrinthOfLore::Gameplay::Screen screen;
   EXPECT_EQ(LabyrinthOfLore::Gameplay::Screen::TYPE, screen.get_type());
}


TEST_F(LabyrinthOfLore_Gameplay_ScreenTestWithAllegroFrameworksFullFixture,
   DISABLED__TIMED_INTERACTIVE__will_run_as_expected)
{
   AllegroFlare::Display *display = get_framework_ref().get_primary_display();
   LabyrinthOfLore::Gameplay::Screen screen;
   screen.set_event_emitter(get_framework_event_emitter());
   screen.set_bitmap_bin(get_framework_bitmap_bin());
   screen.set_font_bin(get_framework_font_bin());
   screen.set_model_bin(get_framework_model_bin());
   screen.set_render_surface_width(display->get_width());
   screen.set_render_surface_height(display->get_height());
   screen.set_render_surface_display(display->al_display);
   screen.initialize();

   framework_register_and_activate_screen("screen", &screen);

   framework_run_loop(3);
}


