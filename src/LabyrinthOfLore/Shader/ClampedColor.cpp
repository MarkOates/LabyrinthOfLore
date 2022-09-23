

#include <LabyrinthOfLore/Shader/ClampedColor.hpp>




namespace LabyrinthOfLore
{
namespace Shader
{


ClampedColor::ClampedColor()
   : LabyrinthOfLore::Shader::Base(obtain_vertex_source(), obtain_fragment_source())
   , initialized(false)
{
}


ClampedColor::~ClampedColor()
{
}


void ClampedColor::initialize()
{
   if (!initialized) LabyrinthOfLore::Shader::Base::initialize();
   initialized = true;
}

void ClampedColor::activate()
{
   if (!initialized) throw std::runtime_error("[LabyrinthOfLore::Shader::ClampedColor] Attempting to activate() shader before it has been initialized");
   LabyrinthOfLore::Shader::Base::activate();
}

void ClampedColor::deactivate()
{
   LabyrinthOfLore::Shader::Base::deactivate();
}

void ClampedColor::set_clamped_color(ALLEGRO_COLOR clamped_color)
{
   Shader::set_vec3("tint", clamped_color.r, clamped_color.g, clamped_color.b);
   Shader::set_float("tint_intensity", 1.0);
}

std::string ClampedColor::obtain_vertex_source()
{
   static const std::string source = R"DELIM(
     attribute vec4 al_pos;
     attribute vec4 al_color;
     attribute vec2 al_texcoord;
     uniform mat4 al_projview_matrix;
     varying vec4 varying_color;
     varying vec2 varying_texcoord;

     void main()
     {
        varying_color = al_color;
        varying_texcoord = al_texcoord;
        gl_Position = al_projview_matrix * al_pos;
     }
   )DELIM";
   return source;
}

std::string ClampedColor::obtain_fragment_source()
{
   static const std::string source = R"DELIM(
     uniform sampler2D al_tex;
     uniform float tint_intensity;
     uniform vec3 tint;
     varying vec4 varying_color;
     varying vec2 varying_texcoord;

     void main()
     {
        vec4 tmp = texture2D(al_tex, varying_texcoord);
        gl_FragColor = (tmp.a < 0.0001) ? vec4(0.0, 0.0, 0.0, 0.0) : vec4(tint, 1.0);
     }
   )DELIM";
   return source;
}


} // namespace Shader
} // namespace LabyrinthOfLore


