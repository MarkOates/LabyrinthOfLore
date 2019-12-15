
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/PickingBufferRenderer.hpp>
#include <allegro5/allegro_image.h>


class LabyrinthOfLore_Rendering_PickingBufferRendererTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;

   LabyrinthOfLore_Rendering_PickingBufferRendererTest()
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


TEST_F(LabyrinthOfLore_Rendering_PickingBufferRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer;
}


TEST_F(LabyrinthOfLore_Rendering_PickingBufferRendererTest, render__does_not_explode_with_reasonable_arguments)
{
   AllegroFlare::PickingBuffer picking_buffer(800, 600);
   picking_buffer.initialize();
   allegro_flare::placement3d camera_placement;
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

   LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(&picking_buffer, camera_placement, entities);

   picking_buffer_renderer.render();
}


TEST_F(LabyrinthOfLore_Rendering_PickingBufferRendererTest, render__displays_the_entities_on_the_scene)
{
   al_init_image_addon();

   AllegroFlare::PickingBuffer picking_buffer(800, 600);
   picking_buffer.initialize();
   allegro_flare::placement3d camera_placement;
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {};
   ALLEGRO_BITMAP *billboard_tester_sprite = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/billboarding_tester_sprite.png");
   ASSERT_NE(nullptr, billboard_tester_sprite);

   LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
   entity->set_bitmap(billboard_tester_sprite);
   entity->get_placement_ref().position = AllegroFlare::vec3d(0, 0, -5);
   entity->get_placement_ref().scale = AllegroFlare::vec3d(0.01, 0.01, 0.01);
   entities.push_back(entity);

   LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(&picking_buffer, camera_placement, entities);
   picking_buffer_renderer.render();

   al_init_image_addon();
   ASSERT_EQ(true, al_save_bitmap("/Users/markoates/Repos/LabyrinthOfLore/tmp/test2.png", picking_buffer.get_surface_render()));
}
