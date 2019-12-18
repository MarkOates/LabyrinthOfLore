

#include <LabyrinthOfLore/Rendering/PickingBufferRenderer.hpp>
#include <LabyrinthOfLore/Rendering/EntityPickingRenderer.hpp>


namespace LabyrinthOfLore
{
namespace Rendering
{


PickingBufferRenderer::PickingBufferRenderer(AllegroFlare::PickingBuffer* picking_buffer, allegro_flare::placement3d camera_view, std::vector<LabyrinthOfLore::Entity::Base*> entities, LabyrinthOfLore::Shader::ClampedColor* clamped_color_shader, LabyrinthOfLore::Rendering::Camera* camera)
   : picking_buffer(picking_buffer)
   , camera_view(camera_view)
   , entities(entities)
   , clamped_color_shader(clamped_color_shader)
   , camera(camera)
{
}


PickingBufferRenderer::~PickingBufferRenderer()
{
}


void PickingBufferRenderer::render()
{
if (!picking_buffer) throw std::runtime_error("picking buffer must not be a nullptr");
if (!camera) throw std::runtime_error("PickingBuffer camera must not be a nullptr");
if (!clamped_color_shader) throw std::runtime_error("clamped_color_shader must not be a nullptr");

ALLEGRO_STATE previous_render_state;
al_store_state(&previous_render_state, ALLEGRO_STATE_TARGET_BITMAP);
al_set_target_bitmap(picking_buffer->get_surface_render());

al_clear_to_color(al_map_rgba_f(0, 0, 0, 0));

camera->start_projection(picking_buffer->get_surface_render());

clamped_color_shader->activate();


for (auto &entity : entities)
{
   LabyrinthOfLore::Rendering::EntityPickingRenderer(entity, clamped_color_shader).render();
}

clamped_color_shader->deactivate();

al_restore_state(&previous_render_state);
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


