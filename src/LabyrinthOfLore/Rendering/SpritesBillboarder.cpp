

#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <allegro_flare/placement3d.h>
#include <AllegroFlare/Vec3D.hpp>
#include <AllegroFlare/Useful.hpp>


namespace LabyrinthOfLore
{
namespace Rendering
{


SpritesBillboarder::SpritesBillboarder(allegro_flare::placement3d camera_placement, std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : camera_placement(camera_placement)
   , entities(entities)
{
}


SpritesBillboarder::~SpritesBillboarder()
{
}


void SpritesBillboarder::process()
{
return;
AllegroFlare::vec3d camera_rotation = camera_placement.rotation;

for (auto &entity : entities)
{
   if (entity->get_billboard_at_camera())
   {
      entity->get_placement_ref().rotation = camera_rotation;
   }
}
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


