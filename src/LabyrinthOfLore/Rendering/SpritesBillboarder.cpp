

#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <allegro_flare/placement3d.h>
#include <AllegroFlare/Vec3D.hpp>
#include <AllegroFlare/Useful.hpp>


namespace LabyrinthOfLore
{
namespace Rendering
{


SpritesBillboarder::SpritesBillboarder(LabyrinthOfLore::Rendering::Camera camera, std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : camera(camera)
   , entities(entities)
{
}


SpritesBillboarder::~SpritesBillboarder()
{
}


void SpritesBillboarder::process()
{
   for (auto &entity : entities)
   {
      if (entity->get_billboard_at_camera())
      {
         entity->get_placement_ref().rotation.y = -camera.get_yaw_ref();
         entity->get_placement_ref().rotation.x = camera.get_pitch_ref();
      }
   }
   return;
}
} // namespace Rendering
} // namespace LabyrinthOfLore


