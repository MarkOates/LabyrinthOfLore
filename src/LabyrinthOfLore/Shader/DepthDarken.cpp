

#include <LabyrinthOfLore/Shader/DepthDarken.hpp>



namespace LabyrinthOfLore
{
namespace Shader
{


DepthDarken::DepthDarken()
   : LabyrinthOfLore::Shader::Base(obtain_vertex_source(), obtain_fragment_source())
   , torch_on(false)
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

void DepthDarken::toggle_torch()
{
if (!torch_on) set_torch_on();
else set_torch_off();

}

void DepthDarken::set_torch_on()
{
torch_on = true;
}

void DepthDarken::set_torch_off()
{
torch_on = false;
}

void DepthDarken::activate()
{
if (!initialized) throw std::runtime_error("[LabyrinthOfLore::Shader::ClampedColor] Attempting to activate() shader before it has been initialized");
LabyrinthOfLore::Shader::Base::activate();
Shader::set_bool("torch_on", torch_on);

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
  uniform bool torch_on;
  varying vec4 varying_color;
  varying vec2 varying_texcoord;

  void main()
  {
     vec4 tmp = texture2D(al_tex, varying_texcoord);
     vec4 torch_color = (vec4(0.96, 0.804, 0.2941, 1.0) + vec4(1., 1., 1., 1.)) * 0.5;
     float noise = 1.0; //noise1(3)* 0.1 + 0.9;

     //bool torch_on = false;
     if (torch_on)
     {
        float depth_value = gl_FragCoord.a;
        //float inverse_tint_intensity = 1.0 - tint_intensity;
        tmp.r = tmp.r * depth_value * torch_color.r * noise;
        tmp.g = tmp.g * depth_value * torch_color.g * noise;
        tmp.b = tmp.b * depth_value * torch_color.b * noise;
        //tmp.a = tmp.a;
     }
     else
     {
        //float depth_value = (gl_FragCoord.a < 0.2) ? 0.0 : gl_FragCoord.a;
        float depth_value = smoothstep(0.05, 0.3, (gl_FragCoord.a * 0.5)) * 0.2; // ? 0.0 : gl_FragCoord.a;
        //float inverse_tint_intensity = 1.0 - tint_intensity;
        tmp.r = tmp.r * depth_value;
        tmp.g = tmp.g * (depth_value + 0.004);
        tmp.b = tmp.b * (depth_value + 0.02);
        //tmp.a = tmp.a;
     }

     gl_FragColor = tmp;
  }
)DELIM";
return source;

}
} // namespace Shader
} // namespace LabyrinthOfLore


