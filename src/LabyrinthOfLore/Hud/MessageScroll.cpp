

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


std::string MessageScroll::get_text() const
{
   return text;
}


std::string MessageScroll::get_last_message_text()
{
   if (messages.empty()) return {};
   return std::get<1>(messages[messages.size()-1]);
}

std::vector<std::tuple<float, std::string, int>> MessageScroll::get_messages_ref()
{
   return messages;
}

std::vector<std::tuple<float, std::string, int>> MessageScroll::get_last_3_messages()
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
   if (!messages.empty() && text_to_append == std::get<1>(messages.back())) //.second)
   {
      // update the time of the newest message so it flashes
      std::get<0>(messages.back()) = time_of_message;
   }
   else
   {
      // append the message normally
      messages.push_back({ time_of_message, text_to_append, 0 });
   }
   return;
}

void MessageScroll::append_character_dialog(float time_of_message, std::string text_to_append)
{
   if (!messages.empty() && text_to_append == std::get<1>(messages.back())) //.second)
   {
      // update the time of the newest message so it flashes
      std::get<0>(messages.back()) = time_of_message;
   }
   else
   {
      // append the message normally
      messages.push_back({ time_of_message, text_to_append, 1 });
   }
   return;
}

void MessageScroll::clear_text()
{
   text.clear();
}


} // namespace Hud
} // namespace LabyrinthOfLore


