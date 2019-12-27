

#include <LabyrinthOfLore/WorldMap/PixelRenderer.hpp>
#include <allegro5/allegro_primitives.h>
#include <AllegroFlare/Color.hpp>
#include <LabyrinthOfLore/WorldMap/Tile.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


namespace LabyrinthOfLore
{
namespace WorldMap
{


PixelRenderer::PixelRenderer(LabyrinthOfLore::WorldMap::TileMap tile_map, LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary, float ground_level)
   : tile_map(tile_map)
   , tile_type_dictionary(tile_type_dictionary)
   , ground_level(ground_level)
{
}


PixelRenderer::~PixelRenderer()
{
}


void PixelRenderer::initialize()
{
al_init_primitives_addon();

}

ALLEGRO_BITMAP* PixelRenderer::create_render()
{
ALLEGRO_BITMAP *result = al_create_bitmap(tile_map.get_width(), tile_map.get_height());
ALLEGRO_STATE previous_state;
al_store_state(&previous_state, ALLEGRO_STATE_TARGET_BITMAP);

al_set_target_bitmap(result);
al_clear_to_color(al_map_rgba_f(0, 0, 0, 0));

int tile_width = 1;
int tile_height = 1;

float bottom_height = 0.0;
float top_height = 2.0;
ALLEGRO_COLOR tile_color = al_color_name("white");

for (unsigned y=0; y<tile_map.get_height(); y++)
  for (unsigned x=0; x<tile_map.get_width(); x++)
   {
      LabyrinthOfLore::WorldMap::Tile tile = tile_map.get_tile(x, y);
      float height_float = tile.get_height() / top_height;

      ALLEGRO_COLOR this_tile_color = AllegroFlare::color::color(tile_color, height_float);

      al_draw_filled_rectangle(
         x * tile_width,
         y * tile_height,
         x * tile_width + tile_width,
         y * tile_height + tile_height,
         this_tile_color
      );
   }

al_restore_state(&previous_state);

return result;

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


