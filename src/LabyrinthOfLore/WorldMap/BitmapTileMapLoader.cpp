

#include <LabyrinthOfLore/WorldMap/BitmapTileMapLoader.hpp>



namespace LabyrinthOfLore
{
namespace WorldMap
{


BitmapTileMapLoader::BitmapTileMapLoader(ALLEGRO_BITMAP* source_bitmap)
   : source_bitmap(source_bitmap)
{
}


BitmapTileMapLoader::~BitmapTileMapLoader()
{
}


int BitmapTileMapLoader::get_index_column_x()
{
return al_get_bitmap_width(source_bitmap) - 1;

}

ALLEGRO_COLOR BitmapTileMapLoader::pick_color(int x, int y)
{
if (!source_bitmap) throw std::runtime_error("cannot pick_color with nullptr source_bitmap.");
int w = al_get_bitmap_width(source_bitmap);
if (w <= 1) throw std::runtime_error("cannot pick_color with source_bitmap less than 2 columns width");
int h = al_get_bitmap_height(source_bitmap);
if (y >= h) throw std::runtime_error("cannot pick_color at a coordinate beyond the height of the source_bitmap.");
return al_get_pixel(source_bitmap, x, y);

}

bool BitmapTileMapLoader::validate()
{
return true;

}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_null_color()
{
return pick_color(get_index_column_x(), 0);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_top_color()
{
return pick_color(get_index_column_x(), 1);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_ground_color()
{
return pick_color(get_index_column_x(), 2);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_gp_color()
{
return pick_color(get_index_column_x(), 5);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_gpp_color()
{
return pick_color(get_index_column_x(), 6);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_gppp_color()
{
return pick_color(get_index_column_x(), 7);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_g1_color()
{
return pick_color(get_index_column_x(), 8);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_gm_color()
{
return pick_color(get_index_column_x(), 9);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_gmm_color()
{
return pick_color(get_index_column_x(), 10);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_gmmm_color()
{
return pick_color(get_index_column_x(), 11);
}

ALLEGRO_COLOR BitmapTileMapLoader::pick_index_gm1_color()
{
return pick_color(get_index_column_x(), 12);
}

LabyrinthOfLore::WorldMap::TileMap BitmapTileMapLoader::load()
{
if (!source_bitmap) throw std::runtime_error("could WorldBitmap::BitmapTileMapLoader.load with a nullptr source_bitmap");
return {};

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


