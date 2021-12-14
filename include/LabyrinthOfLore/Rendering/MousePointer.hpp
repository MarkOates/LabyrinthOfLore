#pragma once




namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class MousePointer
      {
      private:
         float x;
         float y;

      public:
         MousePointer(float x=1, float y=1);
         ~MousePointer();

         void render();
      };
   }
}



