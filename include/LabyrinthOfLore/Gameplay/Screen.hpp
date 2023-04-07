#pragma once


#include <AllegroFlare/BitmapBin.hpp>
#include <AllegroFlare/EventEmitter.hpp>
#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/ModelBin.hpp>
#include <AllegroFlare/Player.hpp>
#include <AllegroFlare/Screens/Base.hpp>
#include <AllegroFlare/VirtualControllers/Base.hpp>
#include <LabyrinthOfLore/Gameplay/Gameplay.hpp>
#include <allegro5/allegro.h>


namespace LabyrinthOfLore
{
   namespace Gameplay
   {
      class Screen : public AllegroFlare::Screens::Base
      {
      public:
         static constexpr char* TYPE = (char*)"LabyrinthOfLore/Gameplay/Screen";

      private:
         AllegroFlare::EventEmitter* event_emitter;
         AllegroFlare::BitmapBin* bitmap_bin;
         AllegroFlare::FontBin* font_bin;
         AllegroFlare::ModelBin* model_bin;
         int render_surface_width;
         int render_surface_height;
         ALLEGRO_DISPLAY* render_surface_display;
         LabyrinthOfLore::Gameplay::Gameplay gameplay_element;
         bool initialized;

      protected:


      public:
         Screen(AllegroFlare::EventEmitter* event_emitter=nullptr, AllegroFlare::BitmapBin* bitmap_bin=nullptr, AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::ModelBin* model_bin=nullptr, int render_surface_width=1920, int render_surface_height=1920, ALLEGRO_DISPLAY* render_surface_display=nullptr);
         virtual ~Screen();

         LabyrinthOfLore::Gameplay::Gameplay &get_gameplay_element_ref();
         void set_event_emitter(AllegroFlare::EventEmitter* event_emitter=nullptr);
         void set_bitmap_bin(AllegroFlare::BitmapBin* bitmap_bin=nullptr);
         void set_font_bin(AllegroFlare::FontBin* font_bin=nullptr);
         void set_model_bin(AllegroFlare::ModelBin* model_bin=nullptr);
         void set_render_surface_width(int render_surface_width=0);
         void set_render_surface_height(int render_surface_height=0);
         void set_render_surface_display(ALLEGRO_DISPLAY* render_surface_display=nullptr);
         void initialize();
         virtual void on_activate() override;
         virtual void on_deactivate() override;
         void update();
         void render();
         virtual void primary_timer_func() override;
         virtual void virtual_control_button_up_func(AllegroFlare::Player* player=nullptr, AllegroFlare::VirtualControllers::Base* virtual_controller=nullptr, int virtual_controller_button_num=0, bool is_repeat=false) override;
         virtual void virtual_control_button_down_func(AllegroFlare::Player* player=nullptr, AllegroFlare::VirtualControllers::Base* virtual_controller=nullptr, int virtual_controller_button_num=0, bool is_repeat=false) override;
         virtual void virtual_control_axis_change_func(ALLEGRO_EVENT* ev=nullptr) override;
         virtual void mouse_axes_func(ALLEGRO_EVENT* ev=nullptr) override;
         virtual void mouse_down_func(ALLEGRO_EVENT* ev=nullptr) override;
         virtual void key_char_func(ALLEGRO_EVENT* ev=nullptr) override;
         virtual void key_up_func(ALLEGRO_EVENT* ev=nullptr) override;
      };
   }
}



