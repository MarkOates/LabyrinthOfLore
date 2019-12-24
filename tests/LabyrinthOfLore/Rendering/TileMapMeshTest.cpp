
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>
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
   Tileo::TileAtlas tile_atlas;
   LabyrinthOfLore::Rendering::TileTypeDictionary tile_type_dictionary;

   std::vector<std::vector<LabyrinthOfLore::WorldMap::Tile>> tile_map_data = { { LabyrinthOfLore::WorldMap::Tile(1, 1.0) } };
   LabyrinthOfLore::WorldMap::TileMap tile_map = LabyrinthOfLore::WorldMap::TileMapLoader(tile_map_data).build_tile_map();

   LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh(&tile_atlas, tile_type_dictionary, tile_map);
   tile_map_mesh.build();
   ASSERT_EQ(30, tile_map_mesh.get_vertexes().size());
}
