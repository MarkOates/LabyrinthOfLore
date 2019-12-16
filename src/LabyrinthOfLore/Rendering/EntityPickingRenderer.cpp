

#include <LabyrinthOfLore/Rendering/EntityPickingRenderer.hpp>
#include <AllegroFlare/ColorIDConverter.hpp>


namespace LabyrinthOfLore
{
namespace Rendering
{


EntityPickingRenderer::EntityPickingRenderer(LabyrinthOfLore::Entity::Base* entity, LabyrinthOfLore::Shader::ClampedColor* clamped_color_shader)
   : entity(entity)
   , clamped_color_shader(clamped_color_shader)
{
}


EntityPickingRenderer::~EntityPickingRenderer()
{
}


void EntityPickingRenderer::render()
{
if (!entity->get_model())
{
    if (entity->get_bitmap())
    {
       clamped_color_shader->set_clamped_color(AllegroFlare::ColorIDConverter::encode_id(entity->get_id()));
       entity->get_placement_ref().start_transform();
       al_draw_bitmap(entity->get_bitmap(), 0, 0, ALLEGRO_FLIP_VERTICAL);
       entity->get_placement_ref().restore_transform();
    }
 }
 else
 {
    clamped_color_shader->set_clamped_color(AllegroFlare::ColorIDConverter::encode_id(entity->get_id()));
    entity->get_placement_ref().start_transform();
    entity->get_model()->set_texture(entity->get_bitmap());
    entity->get_model()->draw();
    entity->get_placement_ref().restore_transform();
 }

}
} // namespace Rendering
} // namespace LabyrinthOfLore


