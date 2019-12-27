

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


LabyrinthOfLore::WorldMap::TileMap BitmapTileMapLoader::load()
{
if (!source_bitmap) throw std::runtime_error("could WorldBitmap::BitmapTileMapLoader.load with a nullptr source_bitmap");
return {};

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


