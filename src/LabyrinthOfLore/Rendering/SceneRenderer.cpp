

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <LabyrinthOfLore/Rendering/EntityRenderer.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


SceneRenderer::SceneRenderer(ALLEGRO_BITMAP* rendering_surface, LabyrinthOfLore::Rendering::Camera* camera, std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : rendering_surface(rendering_surface)
   , camera(camera)
   , entities(entities)
{
}


SceneRenderer::~SceneRenderer()
{
}


void SceneRenderer::render()
{
if (!rendering_surface || !camera) throw std::runtime_error("cannot render with null rendering_surface and/or camera");

ALLEGRO_STATE previous_render_state;
al_store_state(&previous_render_state, ALLEGRO_STATE_TARGET_BITMAP);
al_set_target_bitmap(rendering_surface);

al_clear_to_color(al_color_name("maroon"));

camera->start_projection(rendering_surface);

for (auto &entity : entities)
{
   LabyrinthOfLore::Rendering::EntityRenderer(entity).render();
}

al_restore_state(&previous_render_state);
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


