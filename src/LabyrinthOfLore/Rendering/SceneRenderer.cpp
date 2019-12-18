

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <algorithm>
#include <LabyrinthOfLore/Rendering/SpritesBillboarder.hpp>
#include <LabyrinthOfLore/Rendering/EntityRenderer.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


SceneRenderer::SceneRenderer(allegro_flare::placement3d camera_view, ALLEGRO_BITMAP* rendering_surface, std::vector<LabyrinthOfLore::Entity::Base*> entities, LabyrinthOfLore::Rendering::Camera* camera)
   : camera_view(camera_view)
   , rendering_surface(rendering_surface)
   , entities(entities)
   , camera(camera)
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

bool SceneRenderer::dot_product_sorter(LabyrinthOfLore::Entity::Base* a, LabyrinthOfLore::Entity::Base* b)
{
return true;
//return a->get_placement_ref().position * b->get_placement_ref().position;

}

std::vector<LabyrinthOfLore::Entity::Base*> SceneRenderer::select_non_billboarded_sprites()
{
std::vector<LabyrinthOfLore::Entity::Base*> billboarded_sprites = {};
for (auto &entity : entities)
{
   if (!entity->get_billboard_at_camera()) billboarded_sprites.push_back(entity);
}
return entities;

}

std::vector<LabyrinthOfLore::Entity::Base*> SceneRenderer::select_sorted_billboard_sprites()
{
std::vector<LabyrinthOfLore::Entity::Base*> billboarded_sprites = {};
for (auto &entity : entities)
{
   if (entity->get_billboard_at_camera()) billboarded_sprites.push_back(entity);
}
std::sort(billboarded_sprites.begin(), billboarded_sprites.end(), dot_product_sorter);
return entities;

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
al_set_target_bitmap(rendering_surface);
al_clear_to_color(al_color_name("maroon"));

if (camera) camera->start_projection(rendering_surface);
else prep_render();

LabyrinthOfLore::Rendering::SpritesBillboarder billboarder(camera_view, entities);
billboarder.process();

 al_set_render_state(ALLEGRO_DEPTH_TEST, 0);
for (auto &entity : select_sorted_billboard_sprites())
{
   LabyrinthOfLore::Rendering::EntityRenderer(entity).render();
}
al_set_render_state(ALLEGRO_DEPTH_TEST, 1);
for (auto &entity : select_non_billboarded_sprites())
{
   LabyrinthOfLore::Rendering::EntityRenderer(entity).render();
}

return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


