
#include <gtest/gtest.h>

#include <LabyrinthOfLore/WorldMap/BitmapTileMapLoader.hpp>

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader;
}

TEST(LabyrinthOfLore_WorldMap_BitmapTileMapLoaderTest, load__accepts_default_arguments_without_blowing_up)
{
   ALLEGRO_BITMAP *source_bitmap = nullptr;

   LabyrinthOfLore::WorldMap::BitmapTileMapLoader bitmap_tile_map_loader(source_bitmap);
   bitmap_tile_map_loader.load();
   SUCCEED();
}
