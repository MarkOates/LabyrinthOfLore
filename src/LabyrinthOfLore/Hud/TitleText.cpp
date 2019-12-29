

#include <LabyrinthOfLore/Hud/TitleText.hpp>



namespace LabyrinthOfLore
{
namespace Hud
{


TitleText::TitleText()
   : above_text("Level N")
   , headline_text("The Undefined Level")
{
}


TitleText::~TitleText()
{
}


void TitleText::set_above_text(std::string above_text)
{
   this->above_text = above_text;
}


void TitleText::set_headline_text(std::string headline_text)
{
   this->headline_text = headline_text;
}


std::string TitleText::get_above_text()
{
   return above_text;
}


std::string TitleText::get_headline_text()
{
   return headline_text;
}


} // namespace Hud
} // namespace LabyrinthOfLore


