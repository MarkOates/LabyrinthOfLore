

#include <LabyrinthOfLore/WorldMap/MultiBitmapTileMapLoader.hpp>
#include <sstream>


namespace LabyrinthOfLore
{
namespace WorldMap
{


MultiBitmapTileMapLoader::MultiBitmapTileMapLoader(LabyrinthOfLore::WorldMap::TileMap* tile_map, ALLEGRO_BITMAP* source_bitmap)
   : tile_map(tile_map)
   , source_bitmap(source_bitmap)
{
}


MultiBitmapTileMapLoader::~MultiBitmapTileMapLoader()
{
}


bool MultiBitmapTileMapLoader::colors_are_equal(ALLEGRO_COLOR c1, ALLEGRO_COLOR c2)
{
if (c1.r != c2.r) return false; if (c1.g != c2.g) return false; if (c1.b != c2.b) return false; if (c1.a != c2.a) return false; return true;
}

int MultiBitmapTileMapLoader::get_index_column_x()
{
return al_get_bitmap_width(source_bitmap) - 1;

}

int MultiBitmapTileMapLoader::infer_tile_map_width()
{
return al_get_bitmap_width(source_bitmap) - 2;

}

int MultiBitmapTileMapLoader::infer_tile_map_height()
{
return al_get_bitmap_height(source_bitmap);

}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_color(int x, int y)
{
if (!source_bitmap) throw std::runtime_error("cannot pick_color with nullptr source_bitmap.");
int w = al_get_bitmap_width(source_bitmap);
if (w <= 1) throw std::runtime_error("cannot pick_color with source_bitmap less than 2 columns width");
int h = al_get_bitmap_height(source_bitmap);
if (y >= h) throw std::runtime_error("cannot pick_color at a coordinate beyond the height of the source_bitmap.");
return al_get_pixel(source_bitmap, x, y);

}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_null_color()
{
return pick_color(get_index_column_x(), 0);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_top_color()
{
return pick_color(get_index_column_x(), 1);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_ground_color()
{
return pick_color(get_index_column_x(), 2);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_gp_color()
{
return pick_color(get_index_column_x(), 5);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_gpp_color()
{
return pick_color(get_index_column_x(), 6);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_gppp_color()
{
return pick_color(get_index_column_x(), 7);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_g1_color()
{
return pick_color(get_index_column_x(), 8);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_gm_color()
{
return pick_color(get_index_column_x(), 9);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_gmm_color()
{
return pick_color(get_index_column_x(), 10);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_gmmm_color()
{
return pick_color(get_index_column_x(), 11);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_gm1_color()
{
return pick_color(get_index_column_x(), 12);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_g1p_color()
{
return pick_color(get_index_column_x(), 13);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_g1pp_color()
{
return pick_color(get_index_column_x(), 14);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_g1ppp_color()
{
return pick_color(get_index_column_x(), 15);
}

ALLEGRO_COLOR MultiBitmapTileMapLoader::pick_index_g2_color()
{
return pick_color(get_index_column_x(), 16);
}

bool MultiBitmapTileMapLoader::validate()
{
return true;

}

LabyrinthOfLore::WorldMap::TileMap MultiBitmapTileMapLoader::load_and_process(float top_height, float ground_height)
{
if (!tile_map) throw std::runtime_error("could not WorldBitmap::MultiBitmapTileMapLoader.load with a nullptr tile_map.");
if (!source_bitmap) throw std::runtime_error("could not WorldBitmap::MultiBitmapTileMapLoader.load with a nullptr source_bitmap.");

if ((al_get_bitmap_width(source_bitmap)-2) != tile_map->get_width())
{
   std::stringstream error_message;
   error_message << "Could not WorldBitmap::MultiBitmapTileMapLoader.load with a tile_map and source_bitmap that are of different dimensions. "
      << "The bitmap is (" << al_get_bitmap_width(source_bitmap) << "," << al_get_bitmap_height(source_bitmap) << ") (-2 width, btw) and the tile_map is (" << tile_map->get_width() << "," << tile_map->get_height() << ")";
   throw std::runtime_error(error_message.str());
}

al_lock_bitmap(source_bitmap, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);

int final_tile_map_width = infer_tile_map_width();
int final_tile_map_height = infer_tile_map_height();

LabyrinthOfLore::WorldMap::TileMap result;
result.resize(final_tile_map_width, final_tile_map_height);

//float map_height = 4.0f;
//float ground_height = 2.0f;
float floor_height = 0.0f;

for (unsigned y=0; y<final_tile_map_height; y++)
   for (unsigned x=0; x<final_tile_map_width; x++)
   {
      ALLEGRO_COLOR this_pixel_color = al_get_pixel(source_bitmap, x, y);
      if (colors_are_equal(this_pixel_color, pick_index_null_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(0, floor_height));
      else if (colors_are_equal(this_pixel_color, pick_index_top_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, top_height));
      else if (colors_are_equal(this_pixel_color, pick_index_ground_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height));

      else if (colors_are_equal(this_pixel_color, pick_index_gp_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height+0.25));
      else if (colors_are_equal(this_pixel_color, pick_index_gpp_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height+0.5));
      else if (colors_are_equal(this_pixel_color, pick_index_gppp_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height+0.75));
      else if (colors_are_equal(this_pixel_color, pick_index_g1_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height+1.0));

      else if (colors_are_equal(this_pixel_color, pick_index_gm_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height-0.25));
      else if (colors_are_equal(this_pixel_color, pick_index_gmm_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height-0.5));
      else if (colors_are_equal(this_pixel_color, pick_index_gmmm_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height-0.75));
      else if (colors_are_equal(this_pixel_color, pick_index_gm1_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height-1.0));

      else if (colors_are_equal(this_pixel_color, pick_index_g1p_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height+1.25));
      else if (colors_are_equal(this_pixel_color, pick_index_g1pp_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height+1.5));
      else if (colors_are_equal(this_pixel_color, pick_index_g1ppp_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height+1.75));
      else if (colors_are_equal(this_pixel_color, pick_index_g2_color())) result.set_tile(x, y, LabyrinthOfLore::WorldMap::Tile(1, ground_height+2.0));

      else
      {
         std::stringstream error_message;
         error_message << "Unexpected color at pixel (" << x << ", " << y << ")";
         throw std::runtime_error(error_message.str());
      }
   }

al_unlock_bitmap(source_bitmap);

return result;

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


