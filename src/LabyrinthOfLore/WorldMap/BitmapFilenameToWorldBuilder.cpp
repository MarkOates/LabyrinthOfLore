

#include <LabyrinthOfLore/WorldMap/BitmapFilenameToWorldBuilder.hpp>

#include <LabyrinthOfLore/WorldMap/BitmapTileMapLoader.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <sstream>


namespace LabyrinthOfLore
{
namespace WorldMap
{


BitmapFilenameToWorldBuilder::BitmapFilenameToWorldBuilder(std::string bitmap_source_filename, float top_height, float ground_height)
   : bitmap_source_filename(bitmap_source_filename)
   , top_height(top_height)
   , ground_height(ground_height)
{
}


BitmapFilenameToWorldBuilder::~BitmapFilenameToWorldBuilder()
{
}


std::string BitmapFilenameToWorldBuilder::get_bitmap_source_filename() const
{
   return bitmap_source_filename;
}


float BitmapFilenameToWorldBuilder::get_top_height() const
{
   return top_height;
}


float BitmapFilenameToWorldBuilder::get_ground_height() const
{
   return ground_height;
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
   return loader.load(top_height, ground_height);
}


} // namespace WorldMap
} // namespace LabyrinthOfLore


