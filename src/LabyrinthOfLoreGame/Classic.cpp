

#include <LabyrinthOfLoreGame/Classic.hpp>

#include <LabyrinthOfLore/Entity/ThingDictionary.hpp>
#include <LabyrinthOfLore/Rendering/TileTypeDictionary.hpp>
#include <LabyrinthOfLore/WorldMap/MultiBitmapFilenameToWorldBuilder.hpp>
#include <LabyrinthOfLore/WorldMap/TileTypeEnum.hpp>
#include <LabyrinthOfLoreGame/ItemIdEnums.hpp>
#include <LabyrinthOfLoreGame/LevelIdentifiers.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>


namespace LabyrinthOfLoreGame
{


Classic::Classic(AllegroFlare::BitmapBin* bitmap_bin)
   : bitmap_bin(bitmap_bin)
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
   , all_entities({})
   , initialized(false)
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


std::vector<LabyrinthOfLore::Entity::Base*> &Classic::get_all_entities_ref()
{
   return all_entities;
}


void Classic::set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin)
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLoreGame::Classic::set_bitmap_bin]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLoreGame::Classic::set_bitmap_bin]: error: guard \"(!initialized)\" not met");
   }
   this->bitmap_bin = bitmap_bin;
   return;
}

void Classic::add_thing_to_world(std::vector<LabyrinthOfLore::Entity::Base*>* all_entities, LabyrinthOfLore::Entity::ThingDictionary* thing_dictionary, int thing_id, std::string level_identifier, AllegroFlare::vec3d position, bool billboard_at_camera, bool can_be_picked_up, bool must_be_picked_up_to_be_used)
{
   const std::string THING_ID_ATTRIBUTE = ("thing_id");
   const std::string CAN_BE_PICKED_UP_ATTRIBUTE = ("can_be_picked_up");
   const std::string MUST_BE_PICKED_UP_TO_BE_USED = ("must_be_picked_up_to_be_used");
   const std::string DESTROY_THIS_ITEM_AT_CLEANUP = ("destroy_this_item_at_cleanup");

   //if (!all_entities) throw std::runtime_error("cannot add_thing_to_world with a nullptr all_entities");

   LabyrinthOfLore::Entity::ThingDefinition thing_definition = thing_dictionary->find_definition(thing_id);
   Tileo::TileAtlas *this_things_tile_atlas = thing_definition.get_tile_atlas();
   if (!this_things_tile_atlas) throw std::runtime_error("cannot add_thing_to_world with a nullptr this_things_tile_atlas on the thing_definition"); 

   ALLEGRO_BITMAP *bitmap = this_things_tile_atlas->get_bitmap(thing_definition.get_tile_atlas_index_id());
   LabyrinthOfLore::Entity::Base* entity = new LabyrinthOfLore::Entity::Base;

   entity->set_billboard_at_camera(billboard_at_camera);
   entity->set_bitmap(bitmap);
   entity->set_identifier_for_level_within(level_identifier);

   entity->set(THING_ID_ATTRIBUTE, thing_id);
   if (can_be_picked_up) entity->set(CAN_BE_PICKED_UP_ATTRIBUTE);
   if (must_be_picked_up_to_be_used) entity->set(MUST_BE_PICKED_UP_TO_BE_USED);

   entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 0.0);
   entity->get_placement_ref().size = AllegroFlare::vec3d(al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 0.0);
   entity->get_placement_ref().scale = AllegroFlare::vec3d(0.005*4, 0.005*4, 0.005*4);
   entity->get_placement_ref().align = AllegroFlare::vec3d(0.5, 1.0, 0.0);
   entity->get_placement_ref().position = position; //AllegroFlare::vec3d(x + 0.5, y + 0.5, 3.01);
   ////entity->get_placement_ref().rotation = AllegroFlare::vec3d(0, random.get_random_float(-1, 1), 0);

   all_entities->push_back(entity);
}

void Classic::initialize()
{
   if (!(bitmap_bin))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLoreGame::Classic::initialize]: error: guard \"bitmap_bin\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLoreGame::Classic::initialize]: error: guard \"bitmap_bin\" not met");
   }
   if (initialized) return;

   std::string path = "/Users/markoates/Repos/LabyrinthOfLore/bin/"; // TODO: Remove this in preference for
                                                                     // deployment_environment paths

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
                                                LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder(
                                                      path + "data/bitmaps/the_underworld.png",
                                                      path + "data/bitmaps/the_underworld-type.png",
                                                      3.0).build()
                                             )
      },
      { LabyrinthOfLoreGame::LevelIdentifiers::THE_CAVE_IDENTIFIER,                 LabyrinthOfLore::WorldMap::Level(
                                                "Level 1",
                                                "The Cave",
                                                3.0f,
                                                LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder(
                                                      path + "data/bitmaps/the_cave.png",
                                                      path + "data/bitmaps/the_cave-type.png",
                                                      3.0).build()
                                             )
      },
      { LabyrinthOfLoreGame::LevelIdentifiers::AN_ABANDONED_TEMPLE_IDENTIFIER,      LabyrinthOfLore::WorldMap::Level(
                                                "Level 3",
                                                "An Abandoned Temple",
                                                3.0f,
                                                LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder(
                                                      path + "data/bitmaps/an_abandoned_temple.png",
                                                      path + "data/bitmaps/an_abandoned_temple-type.png",
                                                      3.0, 1.0).build()
                                             )
      },
      { LabyrinthOfLoreGame::LevelIdentifiers::DUNGEON_OF_THE_CURSED_IDENTIFIER,    LabyrinthOfLore::WorldMap::Level(
                                                "Level 2",
                                                "Dungeon of the Cursed",
                                                2.0f,
                                                LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder(
                                                      path + "data/bitmaps/dungeon_of_the_cursed.png",
                                                      path + "data/bitmaps/dungeon_of_the_cursed-type.png"
                                                      ).build()
                                             )
      },
      { LabyrinthOfLoreGame::LevelIdentifiers::TEMPLE_OF_WATER_IDENTIFIER,          LabyrinthOfLore::WorldMap::Level(
                                                "Level 4",
                                                "Temple of Water",
                                                2.0f,
                                                LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder(
                                                      path + "data/bitmaps/temple_of_water.png",
                                                      path + "data/bitmaps/temple_of_water-type.png",
                                                      6.0, 1.25
                                                      ).build()
                                             )
      },
      { LabyrinthOfLoreGame::LevelIdentifiers::WORLD_OF_FIRE_IDENTIFIER,            LabyrinthOfLore::WorldMap::Level(
                                                "Level 5",
                                                "World of Fire",
                                                5.0f,
                                                LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder(
                                                      path + "data/bitmaps/world_of_fire.png",
                                                      path + "data/bitmaps/world_of_fire-type.png",
                                                      5.0).build()
                                             )
      },
      { LabyrinthOfLoreGame::LevelIdentifiers::FINAL_TEMPLE_IDENTIFIER,             LabyrinthOfLore::WorldMap::Level(
                                                "",
                                                "Final Temple",
                                                3.0f,
                                                LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder(
                                                      path + "data/bitmaps/final_temple.png",
                                                      path + "data/bitmaps/final_temple-type.png",
                                                      3.0).build()
                                             )
      },
      { LabyrinthOfLoreGame::LevelIdentifiers::VILLAGE_OF_THE_FORGOTTEN_IDENTIFIER, LabyrinthOfLore::WorldMap::Level(
                                                "",
                                                "Village of the Forgotten",
                                                2.0f,
                                                LabyrinthOfLore::WorldMap::MultiBitmapFilenameToWorldBuilder(
                                                      path + "data/bitmaps/village_of_the_forgotten.png",
                                                      path + "data/bitmaps/village_of_the_forgotten-type.png"
                                                      ).build()
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

   thing_dictionary = LabyrinthOfLore::Entity::ThingDictionary({                                                                          // tile atlas and index            // weight  // health  // mood
       { ITEM_TORCH_ID,                         LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH,           "a",   "torch",                                 &get_item_tile_atlas_ref(),      6 + 9*14,  1,         1)  },
       { ITEM_RING_OF_LOFT_ID,                  LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH,           "the", "ring of loft",                          &get_item_tile_atlas_ref(),      10+13*14,  1,         1)  },
       { ITEM_INFINITY_TORCH_ID,                LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH,           "the", "infinity torch",                        &get_item_tile_atlas_ref(),      6 + 9*14,  1,         1)  },
       { ITEM_TORCH_FUEL_ID,                    LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH,           "some","torch fuel",                            &get_item_tile_atlas_ref(),      27 + 5*14, 1,         1)  },
       { MAN_AT_THE_ENTRANCE_TO_THE_CAVE,       LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_DOES_NOT_MATTER, "a",   "goblin at the entrance of the cave",  &get_character_tile_atlas_ref(), 4 + 11*7,    1,         10,        "friendly")  },

       { RAT+1,                                 LabyrinthOfLore::Entity::ThingDefinition(THING_TYPE_TORCH, "",       "rat",                                 &get_character_tile_atlas_ref(), 4 + 12*7,    1,         3)  },
   });

   //

   add_thing_to_world(&get_all_entities_ref(), &get_thing_dictionary_ref(), ITEM_TORCH_ID,                   LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, {  42.5,  77.5, 3.0 }, true, true,  false);
   add_thing_to_world(&get_all_entities_ref(), &get_thing_dictionary_ref(), MAN_AT_THE_ENTRANCE_TO_THE_CAVE, LabyrinthOfLoreGame::LevelIdentifiers::THE_CAVE_IDENTIFIER,       {  31.5,  9.5, 1.0 },  true, false, false);
   add_thing_to_world(&get_all_entities_ref(), &get_thing_dictionary_ref(), RAT+1,                           LabyrinthOfLoreGame::LevelIdentifiers::THE_UNDERWORLD_IDENTIFIER, {  40.5,  101.5, 1.0 },  true, false, false);

   initialized = true;
   return;
}


} // namespace LabyrinthOfLoreGame


