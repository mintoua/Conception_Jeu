#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL_ttf.h>

#include "enigme_dynamique.h"
int main()
{
	SDL_Surface *ecran=NULL ;
	SDL_Surface *image;
	SDL_Event event;
	SDL_Rect positionimage;
	int continuer=1,h;
	int s=0;
	SDL_Init(SDL_INIT_VIDEO);
	ecran=SDL_SetVideoMode(1000,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
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
				/*bre_aleatoire(100,-100);
				s=nbre_aleatoire(50,-50);
				printf(" %d %d",h,s);*/
				s=equation_enigme(ecran);
				continuer=0;
			break;
			default:;
		}
	}
	SDL_FreeSurface(image);
	SDL_FreeSurface(ecran);
	return 0;
}

