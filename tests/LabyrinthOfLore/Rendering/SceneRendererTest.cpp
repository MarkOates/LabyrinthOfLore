
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <AllegroFlare/Random.hpp>


TEST(LabyrinthOfLore_Rendering_SceneRendererTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::SceneRenderer scene_renderer;
}


TEST(LabyrinthOfLore_Rendering_SceneRendererTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::SceneRenderer scene_renderer;
}


TEST(LabyrinthOfLore_Rendering_SceneRendererTest, select_sorted_billboard_sprites__returns_entities_sorted_by_furthest_to_closest_to_camera)
{
   std::vector<LabyrinthOfLore::Entity::Base*> entities = { };
   float min = -100;
   float max = 100;
   AllegroFlare::Random random(123456);
   for (unsigned i=0; i<100; i++)
   {
      LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;
      entity->get_placement_ref().position = random.get_random_float(min, max);
      entities.push_back(entity);
   }

   LabyrinthOfLore::Rendering::SceneRenderer scene_renderer;

   bool in_order = true;
   //for (entities.push_back)
   //{

   //}
}


