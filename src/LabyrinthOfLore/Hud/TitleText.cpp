

#include <LabyrinthOfLore/Hud/TitleText.hpp>



namespace LabyrinthOfLore
{
namespace Hud
{


TitleText::TitleText()
   : above_text("Level N")
   , headline_text("The Undefined Level")
   , time_changed_at(0)
{
}


TitleText::~TitleText()
{
}


std::string TitleText::get_above_text()
{
   return above_text;
}


std::string TitleText::get_headline_text()
{
   return headline_text;
}


float TitleText::get_time_changed_at()
{
   return time_changed_at;
}


void TitleText::set(std::string above_text, std::string headline_text, float time_now)
{
   this->above_text = above_text;
   this->headline_text = headline_text;
   time_changed_at = time_now;
}
} // namespace Hud
} // namespace LabyrinthOfLore


