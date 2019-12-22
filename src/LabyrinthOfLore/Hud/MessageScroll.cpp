

#include <LabyrinthOfLore/Hud/MessageScroll.hpp>



namespace LabyrinthOfLore
{
namespace Hud
{


MessageScroll::MessageScroll()
   : text("Hello, brave soul. Adventure awaits you.")
{
}


MessageScroll::~MessageScroll()
{
}


void MessageScroll::set_text(std::string text)
{
   this->text = text;
}


std::string MessageScroll::get_text()
{
   return text;
}


} // namespace Hud
} // namespace LabyrinthOfLore


