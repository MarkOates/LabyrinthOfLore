
#include <gtest/gtest.h>


#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }


#include <LabyrinthOfLore/Shader/FlatColor.hpp>


class LabyrinthOfLore_Shader_FlatColorTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;

   LabyrinthOfLore_Shader_FlatColorTest()
      : display(nullptr)
   {
   }

   virtual void SetUp() override
   {
      ASSERT_EQ(false, al_is_system_installed());
      ASSERT_EQ(true, al_init());

      ALLEGRO_DISPLAY *display = al_create_display(800, 600);
      ASSERT_NE(nullptr, display);
   }

   virtual void TearDown() override
   {
      if (display) al_destroy_display(display);
      al_uninstall_system();
   }
};


TEST(LabyrinthOfLore_Shader_FlatColorTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Shader::FlatColor flat_color_shader;
}


TEST(LabyrinthOfLore_Shader_FlatColorTest, activate__before_being_initialized_raises_an_exception)
{
   LabyrinthOfLore::Shader::FlatColor flat_color_shader;
   std::string expected_error_message = "[LabyrinthOfLore::Shader::FlatColor] Attempting to activate() shader before it has been initialized";
   ASSERT_THROW_WITH_MESSAGE(flat_color_shader.activate(), std::runtime_error, expected_error_message);
}


