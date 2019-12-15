

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>



namespace LabyrinthOfLore
{
namespace Rendering
{


SceneRenderer::SceneRenderer(allegro_flare::placement3d camera, std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : camera(camera)
   , entities(entities)
{
}


SceneRenderer::~SceneRenderer()
{
}


void SceneRenderer::prep_render()
{
// setup the render settings

}

void SceneRenderer::render()
{
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


