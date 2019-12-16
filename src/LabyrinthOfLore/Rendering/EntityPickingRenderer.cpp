

#include <LabyrinthOfLore/Rendering/EntityPickingRenderer.hpp>



namespace LabyrinthOfLore
{
namespace Rendering
{


EntityPickingRenderer::EntityPickingRenderer(LabyrinthOfLore::Entity::Base* entity)
   : entity(entity)
{
}


EntityPickingRenderer::~EntityPickingRenderer()
{
}


void EntityPickingRenderer::render()
{
entity->get_placement_ref().start_transform();

if (!entity->get_model())
{
   if (entity->get_bitmap())
   {
      al_draw_bitmap(entity->get_bitmap(), 0, 0, ALLEGRO_FLIP_VERTICAL);
   }
}
else
{
   //shader->set_
   entity->get_model()->set_texture(entity->get_bitmap());
   entity->get_model()->draw();
}
entity->get_placement_ref().restore_transform();

}
} // namespace Rendering
} // namespace LabyrinthOfLore


