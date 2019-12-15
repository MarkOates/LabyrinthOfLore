

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


SceneRenderer::SceneRenderer(allegro_flare::placement3d camera_view, ALLEGRO_BITMAP* rendering_surface, std::vector<LabyrinthOfLore::Entity::Base*> entities)
   : camera_view(camera_view)
   , rendering_surface(rendering_surface)
   , entities(entities)
{
}


SceneRenderer::~SceneRenderer()
{
}


void SceneRenderer::set_projection(ALLEGRO_BITMAP* bitmap, ALLEGRO_TRANSFORM* t)
{
float aspect_ratio = (float)al_get_bitmap_height(bitmap) / al_get_bitmap_width(bitmap);
al_perspective_transform(t, -1, aspect_ratio, 1, 1, -aspect_ratio, 100);
al_use_projection_transform(t);

}

void SceneRenderer::prep_render()
{
// setup the render settings
al_set_render_state(ALLEGRO_DEPTH_TEST, 1);
al_set_render_state(ALLEGRO_WRITE_MASK, ALLEGRO_MASK_DEPTH | ALLEGRO_MASK_RGBA);
al_clear_depth_buffer(1);

ALLEGRO_TRANSFORM t;
camera_view.build_reverse_transform(&t);
set_projection(rendering_surface, &t);

}

void SceneRenderer::render()
{
al_clear_to_color(al_color_name("maroon"));
prep_render();

LabyrinthOfLore::Rendering::SpritesBillboarder billboarder(camera_view.rotation, entities);
billboarder.process();

for (auto &entity : entities)
{
   entity->get_placement_ref().start_transform();
   al_draw_bitmap(entity->get_bitmap(), 0, 0, ALLEGRO_FLIP_VERTICAL);
   entity->get_placement_ref().restore_transform();
}

return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


