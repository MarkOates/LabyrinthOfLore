
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>

TEST(LabyrinthOfLore_Rendering_SpritesBillboarderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder;
}

TEST(LabyrinthOfLore_Rendering_SpritesBillboarderTest, process__returns_the_expected_response)
{
   allegro_flare::placement3d camera_placement = {};
   std::vector<LabyrinthOfLore::Entity::Base*> entities = {};

   LabyrinthOfLore::Rendering::SpritesBillboarder sprites_billboarder(camera_placement, entities);

   sprites_billboarder.process();
}

