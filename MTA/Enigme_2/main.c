/**
 * @file main.c
 * @brief Testing Program.
 * @author Mintoua T Level-Up
 * @version 0.1
 * @date Apr 21, 2019
 *
 *Testing program for enigme
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "enigme_clavier.h"
int main()
{
	SDL_Surface *ecran=NULL ;
	SDL_Surface *image;
	SDL_Event event;
	SDL_Rect positionimage;
	int continuer=1,k;
	SDL_Init(SDL_INIT_VIDEO);
	ecran=SDL_SetVideoMode(1000,667,32,SDL_HWSURFACE);
	image=IMG_Load("fond.jpg");
	positionimage.x=0;
	positionimage.y=0;
	SDL_BlitSurface(image,NULL,ecran,&positionimage);
	SDL_Flip(ecran);
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer=0;
			break;
			case SDL_KEYDOWN:
                        	switch(event.key.keysym.sym)
                                {
	case SDLK_ESCAPE:
	continuer = 0;
	break;}
				do
				{
				k=enigme_clavier(ecran);
				SDL_BlitSurface(image,NULL,ecran,&positionimage);
				SDL_Flip(ecran);
				}while(k!=1);
				continuer=0;
			break;
			default:;
		}
	}
	SDL_FreeSurface(image);
	SDL_Quit();
	return 0;
}

