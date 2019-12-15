

#include <LabyrinthOfLore/Rendering/EntityRenderer.hpp>



namespace LabyrinthOfLore
{
namespace Rendering
{


EntityRenderer::EntityRenderer(LabyrinthOfLore::Entity::Base* entity)
   : entity(entity)
{
}


EntityRenderer::~EntityRenderer()
{
}


void EntityRenderer::render()
{
entity->get_placement_ref().start_transform();

if (!entity->get_model())
{
   al_draw_bitmap(entity->get_bitmap(), 0, 0, ALLEGRO_FLIP_VERTICAL);
}
else
{
   entity->get_model()->set_texture(entity->get_bitmap());
   entity->get_model()->draw();
}
entity->get_placement_ref().restore_transform();

}
} // namespace Rendering
} // namespace LabyrinthOfLore


