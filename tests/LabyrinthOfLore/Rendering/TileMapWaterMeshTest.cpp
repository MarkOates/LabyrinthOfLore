
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapWaterMesh.hpp>
#include <Tileo/TileAtlas.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>
#include <LabyrinthOfLore/WorldMap/TileTypeEnum.hpp>

TEST(LabyrinthOfLore_Rendering_TileMapWaterMeshTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapWaterMesh tile_map_mesh;
}

TEST(LabyrinthOfLore_Rendering_TileMapWaterMeshTest, can_be_constructed_with_reasonable_arguments)
{
   Tileo::TileAtlas tile_atlas;
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = { { LabyrinthOfLore::WorldMap::Tile(1, 1.0) } };
   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::Rendering::TileMapWaterMesh tile_map_mesh(&tile_atlas, tile_type_dictionary, tile_map);
}

TEST(LabyrinthOfLore_Rendering_TileMapWaterMeshTest, build__with_a_single_cube__returns_the_expected_number_of_vertexes)
{
   al_init();
   al_init_image_addon();

   Tileo::TileAtlas tile_atlas;
   ALLEGRO_BITMAP *tile_atlas_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/grid-texture-128.png");
   ASSERT_NE(nullptr, tile_atlas_bitmap);
   tile_atlas.load(tile_atlas_bitmap, 128/3, 128/3, 0);

   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = { { LabyrinthOfLore::WorldMap::Tile(LabyrinthOfLore::WorldMap::WATER_TILE
, 1.0) } };
   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::Rendering::TileMapWaterMesh tile_map_mesh(&tile_atlas, tile_type_dictionary, tile_map);
   tile_map_mesh.build();
   ASSERT_EQ(6, tile_map_mesh.get_vertexes().size());
   al_destroy_bitmap(tile_atlas_bitmap);
}


TEST(LabyrinthOfLore_Rendering_TileMapWaterMeshTest, build__with_a_non_water_tile__does_not_create_any_vertexes)
{
   al_init();
   al_init_image_addon();

   Tileo::TileAtlas tile_atlas;
   ALLEGRO_BITMAP *tile_atlas_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/grid-texture-128.png");
   ASSERT_NE(nullptr, tile_atlas_bitmap);
   tile_atlas.load(tile_atlas_bitmap, 128/3, 128/3, 0);

   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   int non_water_tile = 0;
   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = { { LabyrinthOfLore::WorldMap::Tile(non_water_tile, 1.0) } };
   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::Rendering::TileMapWaterMesh tile_map_mesh(&tile_atlas, tile_type_dictionary, tile_map);
   tile_map_mesh.build();
   ASSERT_EQ(0, tile_map_mesh.get_vertexes().size());
   al_destroy_bitmap(tile_atlas_bitmap);
}

