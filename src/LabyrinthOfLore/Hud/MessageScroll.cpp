

#include <LabyrinthOfLore/Hud/MessageScroll.hpp>



namespace LabyrinthOfLore
{
namespace Hud
{


MessageScroll::MessageScroll(std::string text)
   : text(text)
{
}


MessageScroll::~MessageScroll()
{
}


std::string MessageScroll::get_text()
{
   return text;
}


void MessageScroll::append_text(std::string text_to_append)
{
text += std::string("\n") + text_to_append;
return;

}

void MessageScroll::clear_text()
{
text.clear();
}
} // namespace Hud
} // namespace LabyrinthOfLore


