
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/EntityPickingRenderer.hpp>

class LabyrinthOfLore_Rendering_EntityPickingRendererTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;

   LabyrinthOfLore_Rendering_EntityPickingRendererTest()
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
      if (al_get_current_display()) al_destroy_display(al_get_current_display());
      al_uninstall_system();
   }
};


TEST(LabyrinthOfLore_Rendering_EntityPickingRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::EntityPickingRenderer entity_renderer;
}


TEST(LabyrinthOfLore_Rendering_EntityPickingRendererTest, render__with_with_entity_that_do_not_have_a_bitmap_or_model__will_not_crash)
{
   LabyrinthOfLore::Entity::Base entity;
   entity.set_bitmap(nullptr);

   LabyrinthOfLore::Rendering::EntityPickingRenderer entity_renderer(&entity);
   entity_renderer.render();
}


