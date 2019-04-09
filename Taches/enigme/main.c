#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_getenv.h>
#include "SDL/SDL_ttf.h"
#include "enigme.h" 

int main(int argc, char *argv[])
{Enigme E[3];
	init_enigme(E); 

	SDL_Surface *ecran=NULL ;
	SDL_Surface *image;
	SDL_Event event;
	SDL_Rect positionimage;
	int continuer=1,s;
	SDL_Init(SDL_INIT_VIDEO);
	ecran=SDL_SetVideoMode(800,450,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
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
				do {s=enigme(E,ecran); if(s==0){continuer=0;} }while(s!=0);
			break;
		}

	}
	//freeEnigme(E);
	SDL_FreeSurface(image);
	SDL_Quit();
	return 0;
}


