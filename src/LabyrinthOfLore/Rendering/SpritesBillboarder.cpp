

#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <allegro_flare/placement3d.h>


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


void SpritesBillboarder::reverse_rotation(AllegroFlare::vec3d* entity_rotation)
{
return;

}

void SpritesBillboarder::process()
{
for (auto &entity : entities)
{
   reverse_rotation(&entity->get_placement_ref().rotation);
}
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


