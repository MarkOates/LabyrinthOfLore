

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


void EntityPickingRenderer::render_with_custom_transform()
{
   ALLEGRO_STATE previous_transform_state;
   al_store_state(&previous_transform_state, ALLEGRO_STATE_TRANSFORM);

   ALLEGRO_TRANSFORM transform;
   al_identity_transform(&transform);

   allegro_flare::placement3d &place = entity->get_placement_ref();


   al_translate_transform_3d(&transform, place.size.x * -place.align.x, 0, 0); //place.position.z, place.position.y);

   // rotate
   al_rotate_transform_3d(&transform, 1, 0, 0, place.rotation.x * (ALLEGRO_PI*2)); // "tilting head" transform
   al_rotate_transform_3d(&transform, 0, 1, 0, place.rotation.y * (ALLEGRO_PI*2)); // "turning head" transform
   //al_rotate_transform_3d(&transform, 0, 0, 1, place.rotation.z * (ALLEGRO_PI*2)); // <-- uuhh... not sure how this should work

   al_scale_transform_3d(&transform, place.scale.x, place.scale.y, place.scale.z);
                       // in world:      moves horizontal, moves vertical,   moves height
   al_translate_transform_3d(&transform, place.position.x, place.position.z, place.position.y);



   al_use_transform(&transform);

   al_draw_bitmap(entity->get_bitmap(), 0, 0, ALLEGRO_FLIP_VERTICAL);

   al_restore_state(&previous_transform_state);

   return;
}

void EntityPickingRenderer::render()
{
   if (!entity->get_model())
   {
       if (entity->get_bitmap())
       {
          clamped_color_shader->set_clamped_color(AllegroFlare::ColorIDConverter::encode_id(entity->get_id()));
          render_with_custom_transform();
          //clamped_color_shader->set_clamped_color(AllegroFlare::ColorIDConverter::encode_id(entity->get_id()));
          //entity->get_placement_ref().start_transform();
          //al_draw_bitmap(entity->get_bitmap(), 0, 0, ALLEGRO_FLIP_VERTICAL);
          //entity->get_placement_ref().restore_transform();
       }
    }
    //else
    //{
       //clamped_color_shader->set_clamped_color(AllegroFlare::ColorIDConverter::encode_id(entity->get_id()));
       //entity->get_placement_ref().start_transform();
       //entity->get_model()->set_texture(entity->get_bitmap());
       //entity->get_model()->draw();
       //entity->get_placement_ref().restore_transform();
    //}
}


} // namespace Rendering
} // namespace LabyrinthOfLore


