

#include <LabyrinthOfLoreGame/Classic.hpp>
#include <LabyrinthOfLore/WorldMap/MultiBitmapFilenameToWorldBuilder.hpp>
#include <LabyrinthOfLoreGame/LevelIdentifiers.hpp>


namespace LabyrinthOfLoreGame
{


Classic::Classic(AllegroFlare::BitmapBin* bitmap_bin)
   : bitmap_bin(bitmap_bin)
   , initialized(false)
   , clamped_color_shader({})
   , depth_darken_shader({})
   , item_tile_atlas({})
   , character_tile_atlas({})
   , world_texture_tile_atlas({})
   , levels({})
{
}


Classic::~Classic()
{
}


LabyrinthOfLore::Shader::ClampedColor &Classic::get_clamped_color_shader_ref()
{
   return clamped_color_shader;
}


LabyrinthOfLore::Shader::DepthDarken &Classic::get_depth_darken_shader_ref()
{
   return depth_darken_shader;
}


Tileo::TileAtlas &Classic::get_item_tile_atlas_ref()
{
   return item_tile_atlas;
}


Tileo::TileAtlas &Classic::get_character_tile_atlas_ref()
{
   return character_tile_atlas;
}


Tileo::TileAtlas &Classic::get_world_texture_tile_atlas_ref()
{
   return world_texture_tile_atlas;
}


std::map<std::string, LabyrinthOfLore::WorldMap::Level> &Classic::get_levels_ref()
{
   return levels;
}


void Classic::initialize()
{
if (initialized) return;
depth_darken_shader.initialize();
clamped_color_shader.initialize();
item_tile_atlas.load(bitmap_bin->operator[]("item_spritesheet_full.png"), 16, 16, 0);
character_tile_atlas.load(bitmap_bin->operator[]("item_spritesheet_full.png"), 32, 32, 0);
world_texture_tile_atlas.load(bitmap_bin->operator[]("world_texture_tile_atlas-02.png"), 48, 48, 0);
levels = {
   { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER,           LabyrinthOfLore::WorldMap::Level(
                                             "",
                                             "The Underworld",
                                             2.0f,
                                             LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder("data/bitmaps/the_underworld.png", "data/bitmaps/the_underworld-type.png", 3.0).build()
                                          )
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::THE_CAVE_IDENTIFIER,                 LabyrinthOfLore::WorldMap::Level(
                                             "Level 1",
                                             "The Cave",
                                             3.0f,
                                             LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder("data/bitmaps/the_cave.png", "data/bitmaps/the_cave-type.png", 3.0).build()
                                          )
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::AN_ABANDONED_TEMPLE_IDENTIFIER,      LabyrinthOfLore::WorldMap::Level(
                                             "Level 3",
                                             "An Abandoned Temple",
                                             3.0f,
                                             LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder("data/bitmaps/an_abandoned_temple.png", "data/bitmaps/an_abandoned_temple-type.png", 3.0, 1.0).build()
                                          )
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::DUNGEON_OF_THE_CURSED_IDENTIFIER,    LabyrinthOfLore::WorldMap::Level(
                                             "Level 2",
                                             "Dungeon of the Cursed",
                                             2.0f,
                                             LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder("data/bitmaps/dungeon_of_the_cursed.png", "data/bitmaps/dungeon_of_the_cursed-type.png").build()
                                          )
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::TEMPLE_OF_WATER_IDENTIFIER,          LabyrinthOfLore::WorldMap::Level(
                                             "Level 4",
                                             "Temple of Water",
                                             2.0f,
                                             LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder("data/bitmaps/temple_of_water.png", "data/bitmaps/temple_of_water-type.png", 6.0, 1.25).build()
                                          )
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::WORLD_OF_FIRE_IDENTIFIER,            LabyrinthOfLore::WorldMap::Level(
                                             "Level 5",
                                             "World of Fire",
                                             5.0f,
                                             LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder("data/bitmaps/world_of_fire.png", "data/bitmaps/world_of_fire-type.png", 5.0).build()
                                          )
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::FINAL_TEMPLE_IDENTIFIER,             LabyrinthOfLore::WorldMap::Level(
                                             "",
                                             "Final Temple",
                                             3.0f,
                                             LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder("data/bitmaps/final_temple.png", "data/bitmaps/final_temple-type.png", 3.0).build()
                                          )
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, LabyrinthOfLore::WorldMap::Level(
                                             "",
                                             "Village of the Forgotten",
                                             2.0f,
                                             LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder("data/bitmaps/village_of_the_forgotten.png", "data/bitmaps/village_of_the_forgotten-type.png").build()
                                          )
   },
};

}
} // namespace LabyrinthOfLoreGame


