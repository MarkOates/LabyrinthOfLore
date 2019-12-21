
#include <gtest/gtest.h>

#include <LabyrinthOfLore/Shader/DepthDarken.hpp>

TEST(LabyrinthOfLore_Shader_DepthDarkenTest, can_be_created_without_blowing_up)
{
   LabyrinthOfLore::Shader::DepthDarken depth_darken;
}

TEST(LabyrinthOfLore_Shader_DepthDarkenTest, run__returns_the_expected_response)
{
   LabyrinthOfLore::Shader::DepthDarken depth_darken;
   //std::string expected_string = "Hello World!";
   //EXPECT_EQ(expected_string, depth_darken.run());
}
