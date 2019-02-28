#include "entete.h"


int main(void){
	SDL_Init(SDL_INIT_VIDEO);
	if(SDL_Init(SDL_INIT_VIDEO)!=0){
		fprintf(stderr,"Unable to initialize SDL: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("TunCity",NULL);
	SDL_WM_SetIcon(IMG_Load("gamepad.png"),NULL);

	SDL_Surface *screen=NULL,*background=NULL,*play=NULL,*settings=NULL,*quit=NULL;
	screen=SDL_SetVideoMode(1366,768,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

	if(!screen){
		fprintf(stderr,"Unable to set 1366x768 video: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
		fprintf(stderr,"%s",Mix_GetError());
		exit(EXIT_FAILURE);
	}
	Mix_Music *mbackground;
	mbackground=Mix_LoadMUS("MBackground.mp3");
	Mix_PlayMusic(mbackground,-1);


	SDL_FillRect(screen,0,SDL_MapRGB(screen->format,255,255,0));

	SDL_Flip(screen);

	background=IMG_Load("Tuncity_menu_3.png");
	play=IMG_Load("Play.png");
	settings=IMG_Load("Settings.png");
	quit=IMG_Load("Quit.png");

	SDL_Rect pbackground,psettings,pplay,pquit;

	psettings.x=145.83;
	psettings.y=391.52;

	pplay.x=145.83;
	pplay.y=261.66;

	pquit.x=145.83;
	pquit.y=519.83;

	psettings.w=478.49;
	pplay.w=478.49;
	pquit.w=478.49;

	psettings.h=114.76;
	pplay.h=114.76;
	pquit.h=114.76;

	pbackground.x=0;
	pbackground.y=0;


	if(background==NULL){
		fprintf(stderr,"Unable to load png: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_BlitSurface(background,NULL,screen,&pbackground);
	SDL_Flip(screen);

	int continuer=1;
	SDL_Event event;

	while(continuer){
		SDL_PollEvent(&event);
		switch(event.type){
			case SDL_QUIT:
				continuer=0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						continuer=0;
						break;
				}
			case SDL_MOUSEMOTION:
				if(event.motion.x>=pplay.x && event.motion.x<=(pplay.x+478.49) && event.motion.y>=pplay.y && event.motion.y<=(pplay.y+114.76)){
					SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
					SDL_BlitSurface(play,NULL,screen,&pbackground);
					SDL_Flip(screen);
					//BUG A REGLER "fct Xkill pour fermer le prog quand il plante"
				}
				else if(event.motion.x>=pquit.x && event.motion.x<=(pquit.x+478.49) && event.motion.y>=pquit.y && event.motion.y<=(pquit.y+114.76)){
					SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
					SDL_BlitSurface(quit,NULL,screen,&pbackground);
					SDL_Flip(screen);
					//BUG A REGLER "fct Xkill pour fermer le prog quand il plante"
				}
				else if(event.motion.x>=psettings.x && event.motion.x<=(psettings.x+478.49) && event.motion.y>=psettings.y && event.motion.y<=(psettings.y+114.76)){
					SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
					SDL_BlitSurface(settings,NULL,screen,&pbackground);
					SDL_Flip(screen);
					//BUG A REGLER "fct Xkill pour fermer le prog quand il plante"
				}
				break;
		}
		SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
		SDL_BlitSurface(background,NULL,screen,&pbackground);
		SDL_Flip(screen);
	}


	SDL_FreeSurface(play);
	SDL_FreeSurface(settings);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(background);
	SDL_FreeSurface(screen);
	Mix_FreeMusic(mbackground);

	SDL_Quit();
	return EXIT_SUCCESS;
}
