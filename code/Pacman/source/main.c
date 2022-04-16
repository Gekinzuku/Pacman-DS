/*****************************************************************************************
 *
 *
 *  Copyright 2008 by Gekinzuku
 *  All Rights Reserved.
 *
 *
 *  Version    Date          Author             Log
 *  --------------------------------------------------------------------------------------
 *  0.0.1      04/05/08      GeekyLink          First POS test
 * 
 ****************************************************************************************/

#include <PA9.h>  //PAlib include
#include "start.h" //

// Converted using PAGfxConverter
#include "gfx/all_gfx.c"
#include "gfx/all_gfx.h"

//defines
#define STOP  0
#define DOWN 1
#define UP  2
#define LEFT 3
#define RIGHT 4

//functions
void LoadSprites(); //loads all the sprites
void SwitchPac(); //switches pacman to the other screen
void MovePac(); //the moving engine of pacman

typedef struct//pac's struct
{
	s16 x, y; //x and y are for cordinates
	u8 screen, speed; //screen if 0 means bottom screen, 1 means top, speed is how fast pacman moves
	u8 dire; //pacman's direction, 0 = stopped, 1 = down, 2 = up, 3 = left, 4 = right
} player;

player pac;
//pac-man


/**************************************************************************************************/

int main(void)	
{
	//PAlib Inits
	PA_Init();
	PA_InitVBL();
	
	PA_InitSound();  // Init the sound system

	LoadSprites(); //loads all the sprites
	
	PA_InitComplete16c(1, (void*)shot_Pal);
	
	PA_EasyBgLoad(0, 3, Pac1);
	PA_EasyBgLoad(1, 3, Pac2);

	//sets pac-man to top right
	pac.x = 125;
	pac.y = 50;
	pac.speed = 1; //sets speed to 1
	pac.dire = 0; //sets direction to none
	pac.screen = 0; //sets screen to top just for the switch function to run right

	PA_PlaySimpleSound(0, start);
	
	
	while(1)
	{
	   	
		MovePac(); //does all the moving for pacman
		
		PA_WaitForVBL();
		
		PA_Dual16cErase();
		PA_16c8X8(0, 50, 50, (void*)shot_Sprite);				
	}
}

/**************************************************************************************************/

void SwitchPac()
{
	PA_SetSpriteXY(pac.screen, 0, -32, 32);
	if(pac.screen == 0) 	
	{
	   pac.y = 190;
	   PA_SetSpriteXY(1, 0, pac.x, pac.y);
	   pac.screen = 1;
   	PA_SetRotsetNoZoom(pac.screen, 0, 128); 
	}	
	else
	{
		pac.y = -8;
	   PA_SetSpriteXY(0, 0, pac.x, pac.y);
	   pac.screen = 0;
   	PA_SetRotsetNoZoom(pac.screen, 0, 384);
	}	
}

/**************************************************************************************************/

void LoadSprites()
{
   //pacman on the top screen
	PA_LoadSpritePal(0,0, (void*)pacman_Pal);
	PA_CreateSprite(0,0,(void*)pacman_Sprite, OBJ_SIZE_16X16, 1, 0, 30, 100);
	PA_SetSpriteRotEnable(0, 0, 0);
                         
   //pacman on the bottom screen
   PA_LoadSpritePal(1,0,(void*)pacman_Pal);
	PA_CreateSprite(1,0,(void*)pacman_Sprite, OBJ_SIZE_16X16, 1, 0, -32, -32);
	PA_SetSpriteRotEnable(1, 0, 0);
}

/**************************************************************************************************/

void MovePac()
{
   	//updates the moving thing
		if(Pad.Newpress.Anykey) 
		{
		   //starts animation back up if pacman had stopped for some reason
   		if(pac.dire == STOP) 
   		{
   		  	PA_StartSpriteAnim(0, 0, 0, 3, 6);
				PA_StartSpriteAnim(1, 0, 0, 3, 6);
  			} 		
  			
  			//gets the direction for pacman ready
		 	if (Pad.Newpress.Right)
			{
			   pac.dire = RIGHT;
  		   	PA_SetRotsetNoZoom(pac.screen, 0, 0);  
			}					
			else if (Pad.Newpress.Left)
			{
			   pac.dire = LEFT; 
  		   	PA_SetRotsetNoZoom(pac.screen, 0, 256);  
			}			
			else if (Pad.Newpress.Up)
			{
			   pac.dire = UP;
		   	PA_SetRotsetNoZoom(pac.screen, 0, 128); 
			}			
			else if (Pad.Newpress.Down)
			{
			   pac.dire = DOWN;
  		   	PA_SetRotsetNoZoom(pac.screen, 0, 384);
			}			
		}
		
		if(pac.dire == STOP) 
		{
		   PA_StartSpriteAnim(0, 0, 0, 0, 0);
			PA_StartSpriteAnim(1, 0, 0, 0, 0);
		}		
		
		
		int Pixel, i;//used for collision
		
		//actually moves pac-man
		if(pac.dire == RIGHT) 
		{
  		   pac.x += pac.speed;
		   //checks for collision
		   for (i = 1; i < 13; i++)
		   {
		   	Pixel =	PA_EasyBgGetPixel(pac.screen,3,pac.x + 16, pac.y + i);
		   	if (Pixel == 1 ) { pac.dire = STOP; pac.x -= pac.speed;	break; }
			}  
		}		
		else if(pac.dire == LEFT)
		{
  		   pac.x -= pac.speed;
		   //checks for collision
		   for (i = 1; i < 13; i++)
		   {
		   	Pixel =	PA_EasyBgGetPixel(pac.screen,3,pac.x -1, pac.y + i);
		   	if (Pixel == 1 ) { pac.dire = STOP; pac.x += pac.speed; break; }
			}   
		}   
		else if(pac.dire == UP)
		{
  		   pac.y -= pac.speed;
		   //checks for collision
		   for (i = 1; i < 13; i++)
		   {
		   	Pixel =	PA_EasyBgGetPixel(pac.screen,3,pac.x + i, pac.y);
		   	if (Pixel == 1 ) { pac.dire = STOP; pac.y += pac.speed; break; }
			}   
		}		
		else if(pac.dire == DOWN)
		{
		   pac.y += pac.speed;
		   //checks for collision
		   for (i = 1; i < 13; i++)
		   {
		   	Pixel =	PA_EasyBgGetPixel(pac.screen,3,pac.x + i, pac.y + 17);
		   	if (Pixel == 1 ) { pac.dire = STOP; pac.y -= pac.speed; break; }
			}
		}		
		
		if((pac.screen == 0) && (pac.y < -8)) SwitchPac();
		else if((pac.screen == 1) && (pac.y > 190)) SwitchPac();
		
		// Set the sprite's position
		PA_SetSpriteXY(pac.screen, 0, pac.x, pac.y);
}

