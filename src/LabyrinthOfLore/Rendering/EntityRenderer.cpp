

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


void EntityRenderer::render_with_legacy_transform()
{
entity->get_placement_ref().start_transform();
al_draw_bitmap(entity->get_bitmap(), 0, 0, 0);
entity->get_placement_ref().restore_transform();

}

void EntityRenderer::render_with_custom_transform()
{
ALLEGRO_STATE previous_transform_state;
al_store_state(&previous_transform_state, ALLEGRO_STATE_TRANSFORM);

ALLEGRO_TRANSFORM transform;
al_identity_transform(&transform);

allegro_flare::placement3d &place = entity->get_placement_ref();

al_scale_transform_3d(&transform, place.scale.x, place.scale.y, place.scale.z);

//al_rotate_transform_3d(&transform, 1, 0, 0, -ALLEGRO_PI/2);
//al_rotate_transform_3d(&transform, 0, 1, 0, -ALLEGRO_PI/2);
//al_rotate_transform_3d(&transform, 0, 1, 0, -ALLEGRO_PI/2);
//al_rotate_transform_3d(&transform, 0, 0, 1, -ALLEGRO_PI/2);
//al_scale_transform_3d(&transform, 1.0, 1.0, 1.0);
                    // in world:      moves horizontal, moves vertical,   moves height
al_translate_transform_3d(&transform, place.position.x, place.position.z, place.position.y);

al_use_transform(&transform);

al_draw_bitmap(entity->get_bitmap(), 0, 0, ALLEGRO_FLIP_VERTICAL);

al_restore_state(&previous_transform_state);

return;

}

void EntityRenderer::render()
{

if (!entity->get_model())
{
   if (entity->get_bitmap())
   {
      render_with_custom_transform();
   }
}
else
{
   /* // world model is drawn as a single mesh separately
   entity->get_placement_ref().scale = AllegroFlare::vec3d(0.8, 0.8, 0.8);
   entity->get_placement_ref().start_transform();
   entity->get_model()->set_texture(entity->get_bitmap());
   entity->get_model()->draw();
   entity->get_placement_ref().restore_transform();
   */
}

}
} // namespace Rendering
} // namespace LabyrinthOfLore


