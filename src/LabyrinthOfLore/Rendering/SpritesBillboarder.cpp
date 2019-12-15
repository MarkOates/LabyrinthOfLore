

#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <allegro_flare/placement3d.h>
#include <AllegroFlare/Vec3D.hpp>
#include <AllegroFlare/Useful.hpp>


namespace LabyrinthOfLore
{
namespace Rendering
{


SpritesBillboarder::SpritesBillboarder(AllegroFlare::vec3d camera_rotation, std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : camera_rotation(camera_rotation)
   , entities(entities)
{
}


SpritesBillboarder::~SpritesBillboarder()
{
}


void SpritesBillboarder::process()
{
AllegroFlare::vec3d reverse_camera_rotation(
   camera_rotation.x + AllegroFlare::FULL_ROTATION/2,
   camera_rotation.y + AllegroFlare::FULL_ROTATION/2,
   camera_rotation.z + AllegroFlare::FULL_ROTATION/2
);
for (auto &entity : entities)
{
   entity->get_placement_ref().rotation = reverse_camera_rotation;
}
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


