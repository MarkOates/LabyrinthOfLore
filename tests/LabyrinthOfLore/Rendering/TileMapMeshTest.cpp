
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
#include <Tileo/TileAtlas.hpp>
#include <LabyrinthOfLore/WorldMap/TileMapLoader.hpp>

TEST(LabyrinthOfLore_Rendering_TileMapMeshTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh;
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshTest, can_be_constructed_with_reasonable_arguments)
{
   Tileo::TileAtlas tile_atlas;
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = { { LabyrinthOfLore::WorldMap::Tile(1, 1.0) } };
   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh(&tile_atlas, tile_type_dictionary, tile_map);
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshTest, build__with_a_single_cube__returns_the_expected_number_of_vertexes)
{
   al_init();
   al_init_image_addon();

   Tileo::TileAtlas tile_atlas;
   ALLEGRO_BITMAP *tile_atlas_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/grid-texture-128.png");
   ASSERT_NE(nullptr, tile_atlas_bitmap);
   tile_atlas.load(tile_atlas_bitmap, 128/3, 128/3, 0);

   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = { { LabyrinthOfLore::WorldMap::Tile(1, 1.0) } };
   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh(&tile_atlas, tile_type_dictionary, tile_map);
   tile_map_mesh.build();
   ASSERT_EQ(30, tile_map_mesh.get_vertexes().size());
   al_destroy_bitmap(tile_atlas_bitmap);
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshTest, build__on_tile_types_of_0__does_not_create_verticies)
{
   al_init();
   al_init_image_addon();

   Tileo::TileAtlas tile_atlas;
   ALLEGRO_BITMAP *tile_atlas_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/grid-texture-128.png");
   ASSERT_NE(nullptr, tile_atlas_bitmap);
   tile_atlas.load(tile_atlas_bitmap, 128/3, 128/3, 0);

   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = { { LabyrinthOfLore::WorldMap::Tile(0, 0.0) } };
   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh(&tile_atlas, tile_type_dictionary, tile_map);
   tile_map_mesh.build();
   ASSERT_EQ(0, tile_map_mesh.get_vertexes().size());
   al_destroy_bitmap(tile_atlas_bitmap);
}

TEST(DISABLED_LabyrinthOfLore_Rendering_TileMapMeshTest, build__when_building_two_tiles_of_equal_height_next_to_each_other_vertically__skips_adding_their_ajacent_faces)
{
   al_init();
   al_init_image_addon();

   Tileo::TileAtlas tile_atlas;
   ALLEGRO_BITMAP *tile_atlas_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/grid-texture-128.png");
   ASSERT_NE(nullptr, tile_atlas_bitmap);
   tile_atlas.load(tile_atlas_bitmap, 128/3, 128/3, 0);

   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = { { LabyrinthOfLore::WorldMap::Tile(1, 1.0) }, { LabyrinthOfLore::WorldMap::Tile(1, 1.0) } };
   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh(&tile_atlas, tile_type_dictionary, tile_map);
   tile_map_mesh.build();
   ASSERT_EQ(60-12, tile_map_mesh.get_vertexes().size());
   al_destroy_bitmap(tile_atlas_bitmap);
}


TEST(DISABLED_LabyrinthOfLore_Rendering_TileMapMeshTest, build__when_building_two_tiles_of_inequal_height_next_to_each_other_vertically__skips_adding_the_shorter_pillars_ajacent_face)
{
   al_init();
   al_init_image_addon();

   Tileo::TileAtlas tile_atlas;
   ALLEGRO_BITMAP *tile_atlas_bitmap = al_load_bitmap("/Users/markoates/Repos/LabyrinthOfLore/bin/programs/data/bitmaps/grid-texture-128.png");
   ASSERT_NE(nullptr, tile_atlas_bitmap);
   tile_atlas.load(tile_atlas_bitmap, 128/3, 128/3, 0);

   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = { { LabyrinthOfLore::WorldMap::Tile(1, 1.0) } , { LabyrinthOfLore::WorldMap::Tile(1, 2.0) } };
   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh(&tile_atlas, tile_type_dictionary, tile_map);
   tile_map_mesh.build();
   ASSERT_EQ(30+30+24-6, tile_map_mesh.get_vertexes().size());
   al_destroy_bitmap(tile_atlas_bitmap);
}

