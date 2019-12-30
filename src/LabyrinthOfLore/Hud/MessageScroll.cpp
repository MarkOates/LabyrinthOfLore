

#include <LabyrinthOfLore/Hud/MessageScroll.hpp>



namespace LabyrinthOfLore
{
namespace Hud
{


MessageScroll::MessageScroll(std::string text)
   : text(text)
   , messages({})
{
}


MessageScroll::~MessageScroll()
{
}


std::string MessageScroll::get_text()
{
   return text;
}


std::vector<std::pair<float, std::string>> MessageScroll::get_last_3_messages()
{
if (messages.empty()) return {};
if (messages.size() == 1) return { messages[messages.size()-1] };
if (messages.size() == 2) return { messages[messages.size()-1], messages[messages.size()-2] };
if (messages.size() >= 3) return { messages[messages.size()-1], messages[messages.size()-2], messages[messages.size()-3] };
return {};

}

void MessageScroll::append_text(std::string text_to_append)
{
text += std::string("\n") + text_to_append;
return;

}

void MessageScroll::append_message(float time_of_message, std::string text_to_append)
{
messages.push_back({ time_of_message, text_to_append });
return;

}

void MessageScroll::clear_text()
{
text.clear();
}
} // namespace Hud
} // namespace LabyrinthOfLore


