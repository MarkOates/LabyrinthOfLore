
#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeTexturer.hpp>

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer;
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, apply_textures__without_a_tile_atlas_raises_an_exception)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer;
   std::string expected_error_message = "cannot apply_textures with a nullptr tile_atlas";
   ASSERT_THROW_WITH_MESSAGE(tile_map_mesh_cube_texturer.apply_textures(), std::runtime_error, expected_error_message);
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, apply_textures__with_minimum_parameters__works_without_blowing_up)
{
   Tileo::TileAtlas tile_atlas;
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer(&tile_atlas);
   tile_map_mesh_cube_texturer.apply_textures();
}

