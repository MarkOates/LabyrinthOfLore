

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


std::string MessageScroll::append_text(std::string text_to_append)
{
text += text_to_append;

}

void MessageScroll::clear_text()
{
text.clear();
}
} // namespace Hud
} // namespace LabyrinthOfLore


