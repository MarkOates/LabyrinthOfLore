

#include <LabyrinthOfLore/Rendering/PickingBufferRenderer.hpp>
#include <LabyrinthOfLore/Rendering/EntityPickingRenderer.hpp>
#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>


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


void PickingBufferRenderer::set_projection(ALLEGRO_BITMAP* bitmap, ALLEGRO_TRANSFORM* t)
{
float aspect_ratio = (float)al_get_bitmap_height(bitmap) / al_get_bitmap_width(bitmap);
al_perspective_transform(t, -1, aspect_ratio, 1, 1, -aspect_ratio, 100);
al_use_projection_transform(t);

}

void PickingBufferRenderer::prep_render()
{
// setup the render settings
al_set_render_state(ALLEGRO_DEPTH_TEST, 1);
al_set_render_state(ALLEGRO_WRITE_MASK, ALLEGRO_MASK_DEPTH | ALLEGRO_MASK_RGBA);
al_clear_depth_buffer(1);

ALLEGRO_TRANSFORM t;
camera_view.build_reverse_transform(&t);
set_projection(picking_buffer->get_surface_render(), &t);

}

void PickingBufferRenderer::render()
{
if (!picking_buffer) throw std::runtime_error("picking buffer must not be a nullptr");
if (!clamped_color_shader) throw std::runtime_error("clamped_color_shader must not be a nullptr");
ALLEGRO_STATE previous_render_state;
al_store_state(&previous_render_state, ALLEGRO_STATE_TARGET_BITMAP);
al_set_target_bitmap(picking_buffer->get_surface_render());

if (camera) camera->start_projection(picking_buffer->get_surface_render());
else prep_render();

clamped_color_shader->activate();


LabyrinthOfLore::Rendering::SpritesBillboarder billboarder(camera_view, entities);
billboarder.process();

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


