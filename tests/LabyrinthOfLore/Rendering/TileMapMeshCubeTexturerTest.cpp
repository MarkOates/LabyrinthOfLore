
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Rendering/TileMapMeshCubeTexturer.hpp>

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer;
}

TEST(LabyrinthOfLore_Rendering_TileMapMeshCubeTexturerTest, apply_textures__works_without_blowing_up)
{
   LabyrinthOfLore::Rendering::TileMapMeshCubeTexturer tile_map_mesh_cube_texturer;
   tile_map_mesh_cube_texturer.apply_textures();
}

