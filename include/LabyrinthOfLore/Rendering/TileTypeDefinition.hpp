#pragma once




namespace LabyrinthOfLore
{
   namespace Rendering
   {
      class TileTypeDefinition
      {
      private:
         int tile_index_for_front_and_back_texture;
         int tile_index_for_right_and_left_texture;
         int tile_index_for_top_texture;

      protected:


      public:
         TileTypeDefinition(int tile_index_for_front_and_back_texture=0, int tile_index_for_right_and_left_texture=0, int tile_index_for_top_texture=0);
         ~TileTypeDefinition();

         int get_tile_index_for_front_and_back_texture() const;
         int get_tile_index_for_right_and_left_texture() const;
         int get_tile_index_for_top_texture() const;
      };
   }
}



