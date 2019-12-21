

#include <LabyrinthOfLore/Shader/DepthDarken.hpp>



namespace LabyrinthOfLore
{
namespace Shader
{


DepthDarken::DepthDarken()
   : LabyrinthOfLore::Shader::Base(obtain_vertex_source(), obtain_fragment_source())
   , initialized(false)
{
}


DepthDarken::~DepthDarken()
{
}


void DepthDarken::initialize()
{
if (!initialized) LabyrinthOfLore::Shader::Base::initialize();
initialized = true;

}

void DepthDarken::activate()
{
if (!initialized) throw std::runtime_error("[LabyrinthOfLore::Shader::ClampedColor] Attempting to activate() shader before it has been initialized");
LabyrinthOfLore::Shader::Base::activate();

}

void DepthDarken::deactivate()
{
LabyrinthOfLore::Shader::Base::deactivate();

}

std::string DepthDarken::obtain_vertex_source()
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

std::string DepthDarken::obtain_fragment_source()
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

     float depth_value = gl_FragCoord.a;
     //float inverse_tint_intensity = 1.0 - tint_intensity;
     tmp.r = tmp.r * depth_value;
     //tmp.g = (tmp.g * inverse_tint_intensity + tint.g * tint_intensity) * tmp.a;
     //tmp.b = (tmp.b * inverse_tint_intensity + tint.b * tint_intensity) * tmp.a;
     //tmp.a = tmp.a;

     gl_FragColor = tmp;
  }
)DELIM";
return source;

}
} // namespace Shader
} // namespace LabyrinthOfLore


