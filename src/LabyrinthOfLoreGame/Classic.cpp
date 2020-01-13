

#include <LabyrinthOfLoreGame/Classic.hpp>



namespace LabyrinthOfLoreGame
{


Classic::Classic()
   : initialized(false)
   , clamped_color_shader({})
{
}


Classic::~Classic()
{
}


LabyrinthOfLore::Shader::ClampedColor &Classic::get_clamped_color_shader_ref()
{
   return clamped_color_shader;
}


void Classic::initialize()
{
if (initialized) return;
clamped_color_shader.initialize();

}
} // namespace LabyrinthOfLoreGame


