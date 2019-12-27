

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
return {};

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


