

#include <LabyrinthOfLoreGame/Classic.hpp>
#include <LabyrinthOfLore/WorldMap/MultiBitmapFilenameToWorldBuilder.hpp>
#include <LabyrinthOfLoreGame/LevelIdentifiers.hpp>
#include <LabyrinthOfLore/WorldMap/TileTypeEnum.hpp>
#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>


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
   , meshes({})
   , water_meshes({})
   , doors({})
   , thing_dictionary()
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


std::map<std::string, LabyrinthOfLore::Rendering::TileMapMesh> &Classic::get_meshes_ref()
{
   return meshes;
}


std::map<std::string, LabyrinthOfLore::Rendering::TileMapWaterMesh> &Classic::get_water_meshes_ref()
{
   return water_meshes;
}


std::map<char, LabyrinthOfLore::WorldMap::Door> &Classic::get_doors_ref()
{
   return doors;
}


LabyrinthOfLore::Entity::ThingDictionary &Classic::get_thing_dictionary_ref()
{
   return thing_dictionary;
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

LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary({
    { LabyrinthOfLore::WorldMap::NORMAL_GROUND_TILE, LabyrinthOfLore::Rendering::TileTypeDefinition(1,      1,    0) },
    { LabyrinthOfLore::WorldMap::DOOR_TILE,          LabyrinthOfLore::Rendering::TileTypeDefinition(2,      2,    0) },
    { LabyrinthOfLore::WorldMap::WATER_TILE,         LabyrinthOfLore::Rendering::TileTypeDefinition(1,      1,    0 + 9*10) },
    { LabyrinthOfLore::WorldMap::LAVA_TILE,          LabyrinthOfLore::Rendering::TileTypeDefinition(1,      1,    1 + 9*10) },
    { LabyrinthOfLore::WorldMap::GLOW_WATER_TILE,    LabyrinthOfLore::Rendering::TileTypeDefinition(1,      1,    2 + 9*10) },
});

meshes = {
   { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER,           LabyrinthOfLore::Rendering::TileMapMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             0
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::THE_CAVE_IDENTIFIER,                 LabyrinthOfLore::Rendering::TileMapMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::THE_CAVE_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             10
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::AN_ABANDONED_TEMPLE_IDENTIFIER,      LabyrinthOfLore::Rendering::TileMapMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::AN_ABANDONED_TEMPLE_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             20
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::DUNGEON_OF_THE_CURSED_IDENTIFIER,    LabyrinthOfLore::Rendering::TileMapMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::DUNGEON_OF_THE_CURSED_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             30
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::TEMPLE_OF_WATER_IDENTIFIER,          LabyrinthOfLore::Rendering::TileMapMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::TEMPLE_OF_WATER_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             40
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::WORLD_OF_FIRE_IDENTIFIER,            LabyrinthOfLore::Rendering::TileMapMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::WORLD_OF_FIRE_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             50
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::FINAL_TEMPLE_IDENTIFIER,             LabyrinthOfLore::Rendering::TileMapMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::FINAL_TEMPLE_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             60
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, LabyrinthOfLore::Rendering::TileMapMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             70
                                          ),
   },
};

water_meshes = {
   { LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER,           LabyrinthOfLore::Rendering::TileMapWaterMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             0
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::THE_CAVE_IDENTIFIER,                 LabyrinthOfLore::Rendering::TileMapWaterMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::THE_CAVE_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             10
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::AN_ABANDONED_TEMPLE_IDENTIFIER,      LabyrinthOfLore::Rendering::TileMapWaterMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::AN_ABANDONED_TEMPLE_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             20
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::DUNGEON_OF_THE_CURSED_IDENTIFIER,    LabyrinthOfLore::Rendering::TileMapWaterMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::DUNGEON_OF_THE_CURSED_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             30
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::TEMPLE_OF_WATER_IDENTIFIER,          LabyrinthOfLore::Rendering::TileMapWaterMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::TEMPLE_OF_WATER_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             40
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::WORLD_OF_FIRE_IDENTIFIER,            LabyrinthOfLore::Rendering::TileMapWaterMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::WORLD_OF_FIRE_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             50
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::FINAL_TEMPLE_IDENTIFIER,             LabyrinthOfLore::Rendering::TileMapWaterMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::FINAL_TEMPLE_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             60
                                          ),
   },
   { LabyrinthOfLoreGame::LevelIdentifiers::VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, LabyrinthOfLore::Rendering::TileMapWaterMesh(
                                             &get_world_texture_tile_atlas_ref(),
                                             tile_type_dictionary,
                                             get_levels_ref()[LabyrinthOfLoreGame::LevelIdentifiers::VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER].get_tile_map(),
                                             get_world_texture_tile_atlas_ref().get_bitmap(),
                                             70
                                          ),
   },
};

for (auto &mesh : meshes) { mesh.second.build(); }
for (auto &water_mesh : water_meshes) { water_mesh.second.build(); }

doors = {
   { 1, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::THE_CAVE_IDENTIFIER, 32.5, 13.5, -5.0, 0.5) },
   { 2, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::AN_ABANDONED_TEMPLE_IDENTIFIER, 19.5, 42.5, -5.0, 0.5) },
   { 3, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::DUNGEON_OF_THE_CURSED_IDENTIFIER, 2.5, 24.5, -5.0, -0.25) },
   { 4, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::TEMPLE_OF_WATER_IDENTIFIER, 55.5, 57.5, -5.0, 0.5) },
   { 5, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::WORLD_OF_FIRE_IDENTIFIER, 19.5, 57.5, -5.0, 0.5) },
   { 6, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::FINAL_TEMPLE_IDENTIFIER, 39.5, 56.5, -5.0, 0.5) },
   { 7, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, 28.5, 30.5, -5.0, 0.25) },

   { 10, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 40.5, 88.5+18, -5.0, 0.5 ), }, // this is the primary spawn point, the game start

   { 11, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 56.5, 25.5, -5.0, 0.0 ), },
   { 12, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 42.5, 45.5, -5.0, 0.25 ), },
   { 13, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 71.5, 92.5, -5.0, 0.25 ), },
   { 14, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 25.5, 21.5, -5.0, 0.0 ), },
   { 15, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 103.5, 2.5, -5.0, 0.0 ), },
   { 16, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 40.5, 31.5, -5.0, 0.0 ), },
   { 17, LabyrinthOfLore::WorldMap::Door(LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, 24.5, 55.5, -5.0, -0.25 ), },
};

}
} // namespace LabyrinthOfLoreGame


