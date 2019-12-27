

#include <LabyrinthOfLoreGame/Maps/TheUnderworld.hpp>
#include <sstream>
#include <LabyrinthOfLore/WorldMap/BitmapTileMapLoader.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


namespace LabyrinthOfLoreGame
{
namespace Maps
{


TheUnderworld::TheUnderworld(std::string bitmap_source_filename)
   : bitmap_source_filename(bitmap_source_filename)
{
}


TheUnderworld::~TheUnderworld()
{
}


std::string TheUnderworld::get_bitmap_source_filename()
{
   return bitmap_source_filename;
}


LabyrinthOfLore::WorldMap::TileMap TheUnderworld::build_the_underworld()
{
// could use a al_is_image_addon_installed() here
ALLEGRO_BITMAP *bitmap_source = al_load_bitmap(bitmap_source_filename.c_str());
if (!bitmap_source)
{
  std::stringstream error_message;
  error_message << "was unable to load bitmap ";
  error_message << "\"" << bitmap_source_filename << "\" ";
  error_message << "when calling build_the_underworld.";
  throw std::runtime_error(error_message.str());
}
LabyrinthOfLore::WorldMap::BitmapTileMapLoader loader(bitmap_source);
return loader.load();

}
} // namespace Maps
} // namespace LabyrinthOfLoreGame


