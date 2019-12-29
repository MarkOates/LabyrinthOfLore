

#include <LabyrinthOfLore/WorldMap/BitmapFilenameToWorldBuilder.hpp>
#include <sstream>
#include <LabyrinthOfLore/WorldMap/BitmapTileMapLoader.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


namespace LabyrinthOfLore
{
namespace WorldMap
{


BitmapFilenameToWorldBuilder::BitmapFilenameToWorldBuilder(std::string bitmap_source_filename)
   : bitmap_source_filename(bitmap_source_filename)
{
}


BitmapFilenameToWorldBuilder::~BitmapFilenameToWorldBuilder()
{
}


std::string BitmapFilenameToWorldBuilder::get_bitmap_source_filename()
{
   return bitmap_source_filename;
}


LabyrinthOfLore::WorldMap::TileMap BitmapFilenameToWorldBuilder::build()
{
// could use a al_is_image_addon_installed() here
ALLEGRO_BITMAP *bitmap_source = al_load_bitmap(bitmap_source_filename.c_str());
if (!bitmap_source)
{
  std::stringstream error_message;
  error_message << "was unable to load bitmap ";
  error_message << "\"" << bitmap_source_filename << "\" ";
  error_message << "when calling build.";
  throw std::runtime_error(error_message.str());
}
LabyrinthOfLore::WorldMap::BitmapTileMapLoader loader(bitmap_source);
return loader.load(2.0, 1.0);

}
} // namespace WorldMap
} // namespace LabyrinthOfLore


