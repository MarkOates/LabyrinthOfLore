
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

   LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder(camera_placement, entities);

   sprites_billboarder.process();

   AllegroFlare::vec3d expected_reverse_camera_rotation = 0.5;//AllegroFlare::FULL_ROTATION/2;

   EXPECT_EQ(expected_reverse_camera_rotation, entities[0]->get_placement_ref().rotation.x);
   EXPECT_EQ(expected_reverse_camera_rotation, entities[0]->get_placement_ref().rotation.y);
   EXPECT_EQ(expected_reverse_camera_rotation, entities[0]->get_placement_ref().rotation.z);

   // cleanup
   for (auto &entity : entities) { delete entity; }
}

