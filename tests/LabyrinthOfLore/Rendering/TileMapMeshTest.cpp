
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMesh.hpp>

TEST(LabyrinthOfLore_Rendering_TileMapMeshTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh;
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Rendering::TileMapMesh tile_map_mesh;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, tile_map_mesh.run());
}
