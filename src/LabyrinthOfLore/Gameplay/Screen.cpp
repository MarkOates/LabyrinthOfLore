

#include <LabyrinthOfLore/Gameplay/Screen.hpp>

#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <sstream>
#include <stdexcept>


namespace LabyrinthOfLore
{
namespace Gameplay
{


Screen::Screen(AllegroFlare::EventEmitter* event_emitter, AllegroFlare::BitmapBin* bitmap_bin, AllegroFlare::FontBin* font_bin, AllegroFlare::ModelBin* model_bin, AllegroFlare::Profiler* profiler, int render_surface_width, int render_surface_height, ALLEGRO_DISPLAY* render_surface_display)
   : AllegroFlare::Screens::Base(LabyrinthOfLore::Gameplay::Screen::TYPE)
   , event_emitter(event_emitter)
   , bitmap_bin(bitmap_bin)
   , font_bin(font_bin)
   , model_bin(model_bin)
   , profiler(profiler)
   , render_surface_width(render_surface_width)
   , render_surface_height(render_surface_height)
   , render_surface_display(render_surface_display)
   , gameplay_element({})
   , initialized(false)
{
}


Screen::~Screen()
{
}


LabyrinthOfLore::Gameplay::Gameplay &Screen::get_gameplay_element_ref()
{
   return gameplay_element;
}


void Screen::set_event_emitter(AllegroFlare::EventEmitter* event_emitter)
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::set_event_emitter]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::set_event_emitter]: error: guard \"(!initialized)\" not met");
   }
   this->event_emitter = event_emitter;
   return;
}

void Screen::set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin)
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::set_bitmap_bin]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::set_bitmap_bin]: error: guard \"(!initialized)\" not met");
   }
   this->bitmap_bin = bitmap_bin;
   return;
}

void Screen::set_font_bin(AllegroFlare::FontBin* font_bin)
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::set_font_bin]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::set_font_bin]: error: guard \"(!initialized)\" not met");
   }
   this->font_bin = font_bin;
   return;
}

void Screen::set_model_bin(AllegroFlare::ModelBin* model_bin)
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::set_model_bin]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::set_model_bin]: error: guard \"(!initialized)\" not met");
   }
   this->model_bin = model_bin;
   return;
}

void Screen::set_profiler(AllegroFlare::Profiler* profiler)
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::set_profiler]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::set_profiler]: error: guard \"(!initialized)\" not met");
   }
   this->profiler = profiler;
   return;
}

void Screen::set_render_surface_width(int render_surface_width)
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::set_render_surface_width]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::set_render_surface_width]: error: guard \"(!initialized)\" not met");
   }
   this->render_surface_width = render_surface_width;
   return;
}

void Screen::set_render_surface_height(int render_surface_height)
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::set_render_surface_height]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::set_render_surface_height]: error: guard \"(!initialized)\" not met");
   }
   this->render_surface_height = render_surface_height;
   return;
}

void Screen::set_render_surface_display(ALLEGRO_DISPLAY* render_surface_display)
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::set_render_surface_display]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::set_render_surface_display]: error: guard \"(!initialized)\" not met");
   }
   this->render_surface_display = render_surface_display;
   return;
}

void Screen::initialize()
{
   if (!((!initialized)))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"(!initialized)\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"(!initialized)\" not met");
   }
   if (!(al_is_system_installed()))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"al_is_system_installed()\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"al_is_system_installed()\" not met");
   }
   if (!(al_is_primitives_addon_initialized()))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"al_is_primitives_addon_initialized()\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"al_is_primitives_addon_initialized()\" not met");
   }
   if (!(al_is_font_addon_initialized()))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"al_is_font_addon_initialized()\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"al_is_font_addon_initialized()\" not met");
   }
   if (!(event_emitter))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"event_emitter\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"event_emitter\" not met");
   }
   if (!(bitmap_bin))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"bitmap_bin\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"bitmap_bin\" not met");
   }
   if (!(font_bin))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"font_bin\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"font_bin\" not met");
   }
   if (!(model_bin))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"model_bin\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"model_bin\" not met");
   }
   if (!(profiler))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"profiler\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::initialize]: error: guard \"profiler\" not met");
   }

   gameplay_element.set_bitmap_bin(bitmap_bin);
   gameplay_element.set_font_bin(font_bin);
   gameplay_element.set_profiler(profiler);
   gameplay_element.set_render_surface_width(render_surface_width);
   gameplay_element.set_render_surface_height(render_surface_height);
   gameplay_element.set__display(render_surface_display);
   gameplay_element.initialize();

   gameplay_element.start_game(); // TODO: Move this to a better spot

   initialized = true;
   return;
}

void Screen::on_activate()
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::on_activate]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::on_activate]: error: guard \"initialized\" not met");
   }
   //emit_event_to_update_input_hints_bar();
   //emit_show_and_size_input_hints_bar_event();
   return;
}

void Screen::on_deactivate()
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::on_deactivate]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::on_deactivate]: error: guard \"initialized\" not met");
   }
   //emit_hide_and_restore_size_input_hints_bar_event();
   return;
}

void Screen::update()
{
   return;
}

void Screen::render()
{
   return;
}

void Screen::primary_timer_func()
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::primary_timer_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::primary_timer_func]: error: guard \"initialized\" not met");
   }
   //update();
   //render();
   gameplay_element.process_timer_event();
   return;
}

void Screen::virtual_control_button_up_func(AllegroFlare::Player* player, AllegroFlare::VirtualControllers::Base* virtual_controller, int virtual_controller_button_num, bool is_repeat)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::virtual_control_button_up_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::virtual_control_button_up_func]: error: guard \"initialized\" not met");
   }
   // TODO: this function
   return;
}

void Screen::virtual_control_button_down_func(AllegroFlare::Player* player, AllegroFlare::VirtualControllers::Base* virtual_controller, int virtual_controller_button_num, bool is_repeat)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::virtual_control_button_down_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::virtual_control_button_down_func]: error: guard \"initialized\" not met");
   }
   // TODO: this function
   return;
}

void Screen::virtual_control_axis_change_func(ALLEGRO_EVENT* ev)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::virtual_control_axis_change_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::virtual_control_axis_change_func]: error: guard \"initialized\" not met");
   }
   // TODO: this function
   return;
}

void Screen::mouse_axes_func(ALLEGRO_EVENT* ev)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::mouse_axes_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::mouse_axes_func]: error: guard \"initialized\" not met");
   }
   if (!(ev))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::mouse_axes_func]: error: guard \"ev\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::mouse_axes_func]: error: guard \"ev\" not met");
   }
   gameplay_element.process_mouse_axes_event(*ev);
   return;
}

void Screen::mouse_down_func(ALLEGRO_EVENT* ev)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::mouse_down_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::mouse_down_func]: error: guard \"initialized\" not met");
   }
   if (!(ev))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::mouse_down_func]: error: guard \"ev\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::mouse_down_func]: error: guard \"ev\" not met");
   }
   gameplay_element.process_mouse_button_down_event(*ev);
   return;
}

void Screen::key_char_func(ALLEGRO_EVENT* ev)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::key_char_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::key_char_func]: error: guard \"initialized\" not met");
   }
   bool unused_bool;
   gameplay_element.process_key_char_event(*ev, unused_bool);
   return;
}

void Screen::key_up_func(ALLEGRO_EVENT* ev)
{
   if (!(initialized))
   {
      std::stringstream error_message;
      error_message << "[LabyrinthOfLore::Gameplay::Screen::key_up_func]: error: guard \"initialized\" not met.";
      std::cerr << "\033[1;31m" << error_message.str() << " An exception will be thrown to halt the program.\033[0m" << std::endl;
      throw std::runtime_error("[LabyrinthOfLore::Gameplay::Screen::key_up_func]: error: guard \"initialized\" not met");
   }
   gameplay_element.process_key_up_event(*ev);
   return;
}


} // namespace Gameplay
} // namespace LabyrinthOfLore


