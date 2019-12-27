

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


ALLEGRO_COLOR BitmapTileMapLoader::pick_color(int x, int y)
{
if (!source_bitmap) throw std::runtime_error("cannot pick_color with nullptr source_bitmap.");
int w = al_get_bitmap_width(source_bitmap);
if (w <= 1) throw std::runtime_error("cannot pick_color with source_bitmap less than 2 columns width");
int h = al_get_bitmap_height(source_bitmap);
if (y >= h) throw std::runtime_error("cannot pick_color with source_bitmap more than the columns width of the bitmap");
return al_get_pixel(source_bitmap, x, y);

}

LabyrinthOfLore::WorldMap::TileMap BitmapTileMapLoader::load()
{
if (!source_bitmap) throw std::runtime_error("could WorldBitmap::BitmapTileMapLoader.load with a nullptr source_bitmap");
return {};

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


