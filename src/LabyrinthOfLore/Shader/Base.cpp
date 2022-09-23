

#include <LabyrinthOfLore/Shader/Base.hpp>




namespace LabyrinthOfLore
{
namespace Shader
{


Base::Base(std::string vertex_source_code, std::string fragment_source_code)
   : AllegroFlare::Shader(vertex_source_code, fragment_source_code)
   , vertex_source_code(vertex_source_code)
   , fragment_source_code(fragment_source_code)
{
}


Base::~Base()
{
}




} // namespace Shader
} // namespace LabyrinthOfLore


