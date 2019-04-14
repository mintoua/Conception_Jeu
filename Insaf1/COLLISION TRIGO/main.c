#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <math.h>

static int collision_trigo(SDL_Surface *perso, SDL_Surface *enemie, SDL_Rect posp, SDL_Rect pose)
{
	int ra,rb,xb,xa,ya,yb,distance;

	printf("%d.%d.%d.%d\n", posp.x, posp.y, perso->w, perso->h);
	printf("%d.%d.%d.%d\n", pose.x, pose.y, pose.w, pose.h);
	
	ra = (perso->w)/2;
	xa = (posp.x+(perso->w/2));
	ya = (posp.y+(perso->h/2));
	
	rb = (pose.w)/2;
	xb = (pose.x+(pose.w/2));
	yb = (pose.y+(pose.h/2));
	
	distance = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
	
	printf("distance=%d ra+rb=%d\n", distance, ra+rb);
	
	if(distance<=ra+rb)
	{
		return 1 ;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	SDL_Event event;
	int done= 1;
	int step = 10;

	//Declare a SDL_Surface type
	SDL_Surface * screen = NULL;
	SDL_Surface * image=NULL;
	SDL_Surface * perso=NULL;
	SDL_Rect pos_perso;
	SDL_Rect positionEcran;
	SDL_Rect obs;

	/* obstact */
	obs.x = 643;
	obs.y = 252;
	obs.w = 195;
	obs.h = 37;

	//construct the source rectangle for out blit
	positionEcran.x = 0;
	positionEcran.y = 0;

	pos_perso.x = 300;
	pos_perso.y = 200;

	image = IMG_Load("image.png"); // use IMG_Load
	if(image == NULL)
	{
		printf("Unable to load the image: %s\n",SDL_GetError());
		return 1;
	}

	perso = IMG_Load("detective.png");
	if(perso == NULL)
	{
		printf("Unable to load the image: %s\n",SDL_GetError());
	}
	SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 255,255, 255));

	//initialize SDL video
	SDL_Init(SDL_INIT_VIDEO);
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{ printf("Unable to initialize SDL : %s\n", SDL_GetError());
		return 1 ;
	}
	//Creation de la fenêtre 800 par 600 à 32 bit
	screen = SDL_SetVideoMode(1600,400,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(screen == NULL ) 
	{ printf("Unable to set video mode: %s\n",SDL_GetError());
		return 1;
	}

	//nom de la fenêtre	
	SDL_WM_SetCaption("Mon premier jeux",NULL);

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) ==-1)
		//API Mixer Initialization
	{
		printf("%s",Mix_GetError());
	}
	Mix_Music * music; 
	music =Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music, -1);


	while(done)
	{ 
		SDL_PollEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				done = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_UP:
						//if (pos_perso.y > 180)
							pos_perso.y -= step;
						break;
					case SDLK_DOWN:
						//if (pos_perso.y < 255)
							pos_perso.y += step;
						break;
					case SDLK_RIGHT:
						pos_perso.x += step;

						break;
					case SDLK_LEFT:
						pos_perso.x -= step;
						break;
					default:
						break;
				}
				break;
		}

		if (collision_trigo(perso, NULL, pos_perso, obs))
			pos_perso.x -= step;

		//blit the image to the backbuffer
		SDL_BlitSurface(image,NULL, screen, &positionEcran);
		SDL_BlitSurface(perso,NULL, screen, &pos_perso); 
		//mise a jour écran
		SDL_Flip(screen);
	}


	SDL_FreeSurface(image);
	SDL_FreeSurface(perso);
	Mix_FreeMusic(music);

	SDL_Quit;
	//Return success
	return 0;
}
