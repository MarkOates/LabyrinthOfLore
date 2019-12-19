

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

if (!entity->get_model())
{
   if (entity->get_bitmap())
   {
      entity->get_placement_ref().start_transform();
      al_draw_bitmap(entity->get_bitmap(), 0, 0, ALLEGRO_FLIP_VERTICAL);
      entity->get_placement_ref().restore_transform();
   }
}
else
{
   entity->get_placement_ref().scale = AllegroFlare::vec3d(0.8, 0.8, 0.8);
   entity->get_placement_ref().start_transform();
   entity->get_model()->set_texture(entity->get_bitmap());
   entity->get_model()->draw();
   entity->get_placement_ref().restore_transform();
}

}
} // namespace Rendering
} // namespace LabyrinthOfLore


