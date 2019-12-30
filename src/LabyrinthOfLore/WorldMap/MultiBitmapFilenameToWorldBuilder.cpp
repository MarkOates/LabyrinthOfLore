

#include <LabyrinthOfLore/WorldMap/MultiBitmapFilenameToWorldBuilder.hpp>
#include <sstream>
#include <LabyrinthOfLore/WorldMap/BitmapTileMapLoader.hpp>
#include <LabyrinthOfLore/WorldMap/MultiBitmapTileMapLoader.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


namespace LabyrinthOfLore
{
namespace WorldMap
{


MultiBitmapFilenameToWorldBuilder::MultiBitmapFilenameToWorldBuilder(std::string elevation_bitmap_source_filename, std::string tile_type_bitmap_source_filename, float top_height, float ground_height)
   : elevation_bitmap_source_filename(elevation_bitmap_source_filename)
   , tile_type_bitmap_source_filename(tile_type_bitmap_source_filename)
   , top_height(top_height)
   , ground_height(ground_height)
{
}


MultiBitmapFilenameToWorldBuilder::~MultiBitmapFilenameToWorldBuilder()
{
}


std::string MultiBitmapFilenameToWorldBuilder::get_elevation_bitmap_source_filename()
{
   return elevation_bitmap_source_filename;
}


std::string MultiBitmapFilenameToWorldBuilder::get_tile_type_bitmap_source_filename()
{
   return tile_type_bitmap_source_filename;
}


float MultiBitmapFilenameToWorldBuilder::get_top_height()
{
   return top_height;
}


float MultiBitmapFilenameToWorldBuilder::get_ground_height()
{
   return ground_height;
}


LabyrinthOfLore::WorldMap::TileMap MultiBitmapFilenameToWorldBuilder::build()
{
// could use a al_is_image_addon_installed() here
ALLEGRO_BITMAP *elevation_bitmap_source = al_load_bitmap(elevation_bitmap_source_filename.c_str());
ALLEGRO_BITMAP *tile_type_bitmap_source = al_load_bitmap(tile_type_bitmap_source_filename.c_str());
if (!elevation_bitmap_source)
{
  std::stringstream error_message;
  error_message << "was unable to load bitmap ";
  error_message << "\"" << elevation_bitmap_source_filename << "\" ";
  error_message << "when calling build.";
  throw std::runtime_error(error_message.str());
}
if (!tile_type_bitmap_source)
{
  std::stringstream error_message;
  error_message << "was unable to load bitmap ";
  error_message << "\"" << tile_type_bitmap_source_filename << "\" ";
  error_message << "when calling build.";
  throw std::runtime_error(error_message.str());
}

LabyrinthOfLore::WorldMap::TileMap result = LabyrinthOfLore::WorldMap::BitmapTileMapLoader(elevation_bitmap_source).load(top_height, ground_height);
LabyrinthOfLore::WorldMap::MultiBitmapTileMapLoader(&result, tile_type_bitmap_source).load_and_process();

return result;

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


