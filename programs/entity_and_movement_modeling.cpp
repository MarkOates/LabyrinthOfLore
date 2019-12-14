#include <allegro5/allegro.h>

#include <allegro_flare/placement2d.h>


bool active = false;

int main(int argc, char **argv)
{
   if (active)
   {
      al_init();

      ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);



      al_flip_display();

      sleep(2);
   }

   return 0;
}


