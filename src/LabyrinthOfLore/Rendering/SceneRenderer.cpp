

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>



namespace LabyrinthOfLore
{
namespace Rendering
{


SceneRenderer::SceneRenderer(AllegroFlare::vec3d camera_rotation, std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : camera_rotation(camera_rotation)
   , entities(entities)
{
}


SceneRenderer::~SceneRenderer()
{
}


void SceneRenderer::render()
{
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


