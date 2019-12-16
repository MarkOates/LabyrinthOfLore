
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/PickingBufferRenderer.hpp>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>


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

      al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
      ASSERT_EQ(ALLEGRO_OPENGL, al_get_new_display_flags() & ALLEGRO_OPENGL);
      ASSERT_EQ(ALLEGRO_PROGRAMMABLE_PIPELINE, al_get_new_display_flags() & ALLEGRO_PROGRAMMABLE_PIPELINE);
      ALLEGRO_DISPLAY *display = al_create_display(300, 200);
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
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
   clamped_color_shader.initialize();

   LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(&picking_buffer, camera_placement, entities, &clamped_color_shader);

   picking_buffer_renderer.render();
}


TEST_F(LabyrinthOfLore_Rendering_PickingBufferRendererTest, render__displays_the_entities_on_the_scene)
{
   al_init_image_addon();

   AllegroFlare::PickingBuffer picking_buffer(800, 600);
   picking_buffer.initialize();
   allegro_flare::placement3d camera_placement;
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {};
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
   clamped_color_shader.initialize();

   ALLEGRO_BITMAP *billboard_tester_sprite = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/billboarding_tester_sprite.png");
   ASSERT_NE(nullptr, billboard_tester_sprite);

   LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
   entity->set_bitmap(billboard_tester_sprite);
   entity->get_placement_ref().position = AllegroFlare::vec3d(0, 0, -5);
   entity->get_placement_ref().scale = AllegroFlare::vec3d(0.01, 0.01, 0.01);
   entities.push_back(entity);

   LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(&picking_buffer, camera_placement, entities, &clamped_color_shader);
   picking_buffer_renderer.render();

   al_init_image_addon();
   ASSERT_EQ(true, al_save_bitmap("/Users/markoates/Repos/LabyrinthOfLore/tmp/render__displays_the_entities_on_the_scene.png", picking_buffer.get_surface_render()));
}


TEST_F(LabyrinthOfLore_Rendering_PickingBufferRendererTest, render__renders_the_entity_ids_to_the_surface)
{
   al_init_image_addon();

   AllegroFlare::PickingBuffer picking_buffer(800, 600);
   picking_buffer.initialize();
   allegro_flare::placement3d camera_placement(0, 0, 5);
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {};
   LabyrinthOfLore::Shader::ClampedColor clamped_color_shader;
   clamped_color_shader.initialize();

   ALLEGRO_BITMAP *billboard_tester_sprite = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/billboarding_tester_sprite.png");
   ASSERT_NE(nullptr, billboard_tester_sprite);

   int total_passes = 8;
   for(int i=-total_passes/2; i<total_passes/2; i++)
   {
      float here_pos = (float)i / total_passes;
      LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
      entity->set_bitmap(billboard_tester_sprite);
      entity->get_placement_ref().position = AllegroFlare::vec3d(here_pos * 5, here_pos * 5, here_pos * 5);
      entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(billboard_tester_sprite), al_get_bitmap_height(billboard_tester_sprite));
      entity->get_placement_ref().align = AllegroFlare::vec3d(0.5, 0.5, 0);
      entity->get_placement_ref().rotation = AllegroFlare::vec3d(0, here_pos * 0.1, 0);
      entity->get_placement_ref().scale = AllegroFlare::vec3d(0.05, 0.05, 0.05);
      entities.push_back(entity);
   }

   LabyrinthOfLore::Rendering::PickingBufferRenderer picking_buffer_renderer(&picking_buffer, camera_placement, entities, &clamped_color_shader);
   picking_buffer_renderer.render();

   al_init_image_addon();
   ASSERT_EQ(true, al_save_bitmap("/Users/markoates/Repos/LabyrinthOfLore/tmp/render__renders_the_entity_ids_to_the_surface.png", picking_buffer.get_surface_render()));
}


