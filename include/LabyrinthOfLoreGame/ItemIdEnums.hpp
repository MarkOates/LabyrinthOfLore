#pragma once


enum thing_type_t
{
   THING_TYPE_UNDEFINED = 0,
   THING_TYPE_DOES_NOT_MATTER,
   THING_TYPE_UNKNOWN,
   THING_TYPE_TORCH,
   THING_TYPE_TORCH_FUEL,
};


enum item_id_t
{
   ITEM_NO_ID = 0,
   ITEM_TORCH_ID,
   ITEM_RING_OF_LOFT_ID,
   ITEM_INFINITY_TORCH_ID,
   ITEM_TORCH_FUEL_ID,
   ITEM_TORCH_OF_TRUTH,

   // characters
   MAN_AT_THE_ENTRANCE_TO_THE_CAVE,
   CATALINA_IN_THE_VILLAGE,
   HARCOURT_IN_THE_VILLAGE,

   RAT = 100,

   CREATED_THINGS_START = 10000
};