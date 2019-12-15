

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

//ALLEGRO_TRANSFORM transform;
//al_identity_transform(&transform);

//camera_placement.build_reverse_transform(&transform);

AllegroFlare::vec3d camera_rotation = camera_placement.rotation;

AllegroFlare::vec3d reverse_camera_rotation(
   camera_rotation.x, // + 0.5, //AllegroFlare::FULL_ROTATION/2,
   camera_rotation.y, // + 0.5, //AllegroFlare::FULL_ROTATION/2,
   camera_rotation.z //  + 0.5 //AllegroFlare::FULL_ROTATION/2
);


for (auto &entity : entities)
{
   if (entity->get_billboard_at_camera())
   {
      entity->get_placement_ref().rotation = reverse_camera_rotation;
   }
}
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


