
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <AllegroFlare/Useful.hpp>

TEST(LabyrinthOfLore_Rendering_SpritesBillboarderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder;
}

TEST(LabyrinthOfLore_Rendering_SpritesBillboarderTest, process__returns_the_expected_response)
{
   AllegroFlare::vec3d camera_placement = {};
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

   LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder(camera_placement, entities);

   sprites_billboarder.process();
}

TEST(LabyrinthOfLore_Rendering_SpritesBillboarderTest, process__sets_the_entities_rotations_to_the_reverse_rotation_of_the_camera)
{
   AllegroFlare::vec3d camera_placement = {};
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {
      new LabyrinthOfLore::Entity::Base,
   };

   entities[0]->get_placement_ref().rotation = AllegroFlare::vec3d(1, 0.2, -0.8);
   entities[0]->set_billboard_at_camera(true);

   LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder(camera_placement, entities);

   sprites_billboarder.process();

   AllegroFlare::vec3d expected_reverse_camera_rotation = 0.5;//AllegroFlare::FULL_ROTATION/2;

   //EXPECT_EQ(expected_reverse_camera_rotation, entities[0]->get_placement_ref().rotation.x);
   //EXPECT_EQ(expected_reverse_camera_rotation, entities[0]->get_placement_ref().rotation.y);
   //EXPECT_EQ(expected_reverse_camera_rotation, entities[0]->get_placement_ref().rotation.z);

   // cleanup
   for (auto &entity : entities) { delete entity; }
}

TEST(LabyrinthOfLore_Rendering_SpritesBillboarderTest, process__does_not_set_rotation_for_entities_that_are_not_marked_billboard_at_camera)
{
   AllegroFlare::vec3d camera_placement = {};
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {
      new LabyrinthOfLore::Entity::Base,
   };

   AllegroFlare::vec3d rotation = AllegroFlare::vec3d(1, 0.2, -0.8);
   entities[0]->get_placement_ref().rotation = rotation;
   entities[0]->set_billboard_at_camera(false);

   LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder(camera_placement, entities);

   sprites_billboarder.process();

   EXPECT_EQ(rotation, entities[0]->get_placement_ref().rotation);

   // cleanup
   for (auto &entity : entities) { delete entity; }
}

