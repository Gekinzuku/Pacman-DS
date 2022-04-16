//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char pacman_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : pacman_Pal
extern const unsigned char shot_Sprite[32] __attribute__ ((aligned (4))) ;  // Pal : shot_Pal

// Background files : 
extern const int Pac1_Info[3]; // BgMode, Width, Height
extern const unsigned short Pac1_Map[768] __attribute__ ((aligned (4))) ;  // Pal : Pac1_Pal
extern const unsigned char Pac1_Tiles[4800] __attribute__ ((aligned (4))) ;  // Pal : Pac1_Pal
extern PAGfx_struct Pac1; // background pointer

extern const int Pac2_Info[3]; // BgMode, Width, Height
extern const unsigned short Pac2_Map[864] __attribute__ ((aligned (4))) ;  // Pal : Pac2_Pal
extern const unsigned char Pac2_Tiles[4672] __attribute__ ((aligned (4))) ;  // Pal : Pac2_Pal
extern PAGfx_struct Pac2; // background pointer


// Palette files : 
extern const unsigned short pacman_Pal[2] __attribute__ ((aligned (4))) ;
extern const unsigned short shot_Pal[3] __attribute__ ((aligned (4))) ;
extern const unsigned short Pac1_Pal[3] __attribute__ ((aligned (4))) ;
extern const unsigned short Pac2_Pal[3] __attribute__ ((aligned (4))) ;


#endif

