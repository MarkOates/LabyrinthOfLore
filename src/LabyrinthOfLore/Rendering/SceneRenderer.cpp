

#include <LabyrinthOfLore/Rendering/SceneRenderer.hpp>
#include <LabyrinthOfLore/Rendering/EntityRenderer.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
namespace Rendering
{


SceneRenderer::SceneRenderer(ALLEGRO_BITMAP* rendering_surface, LabyrinthOfLore::Rendering::Camera* camera, LabyrinthOfLore::Rendering::TileMapMesh* tile_map_mesh, LabyrinthOfLore::Rendering::TileMapWaterMesh* tile_map_water_mesh, std::vector<LabyrinthOfLore::Entity::Base*> entities, LabyrinthOfLore::Shader::DepthDarken* depth_darken_shader)
   : rendering_surface(rendering_surface)
   , camera(camera)
   , tile_map_mesh(tile_map_mesh)
   , tile_map_water_mesh(tile_map_water_mesh)
   , entities(entities)
   , depth_darken_shader(depth_darken_shader)
{
}


SceneRenderer::~SceneRenderer()
{
}


void SceneRenderer::render()
{
if (!tile_map_mesh) throw std::runtime_error("cannot render with null tile_map_mesh");
if (!tile_map_water_mesh) throw std::runtime_error("cannot render with null tile_map_water_mesh");
if (!rendering_surface) throw std::runtime_error("cannot render with null rendering_surface");
if (!camera) throw std::runtime_error("cannot render with null camera");
//if (!depth_darken_shader) throw std::runtime_error("cannot render with null depth_darken_shader");

ALLEGRO_STATE previous_render_state;
al_store_state(&previous_render_state, ALLEGRO_STATE_TARGET_BITMAP);
al_set_target_bitmap(rendering_surface);

al_clear_to_color(al_color_name("black"));

camera->start_projection(rendering_surface);

if (depth_darken_shader) depth_darken_shader->activate();

tile_map_mesh->draw();
tile_map_water_mesh->draw();

for (auto &entity : entities)
{
   LabyrinthOfLore::Rendering::EntityRenderer(entity).render();
}

if (depth_darken_shader) depth_darken_shader->deactivate();

al_restore_state(&previous_render_state);
return;

}
} // namespace Rendering
} // namespace LabyrinthOfLore


