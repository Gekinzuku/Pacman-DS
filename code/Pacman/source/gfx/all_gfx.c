//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "pacman.c"
#include "shot.c"

// Background files : 
#include "Pac1.c"
#include "Pac2.c"

// Palette files : 
#include "pacman.pal.c"
#include "shot.pal.c"
#include "Pac1.pal.c"
#include "Pac2.pal.c"

// Background Pointers :
PAGfx_struct Pac1 = {(void*)Pac1_Map, 768, (void*)Pac1_Tiles, 4800, (void*)Pac1_Pal, (int*)Pac1_Info };
PAGfx_struct Pac2 = {(void*)Pac2_Map, 864, (void*)Pac2_Tiles, 4672, (void*)Pac2_Pal, (int*)Pac2_Info };


#ifdef __cplusplus
}
#endif

