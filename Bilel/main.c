#include"entete.h"

int main()
{
	//Init Detective
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER );

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER )!=0){
                fprintf(stderr,"Unable to initialize SDL: %s\n",SDL_GetError());
                exit(EXIT_FAILURE);
        }

	SDL_WM_SetCaption("Meilleur fenêtre au monde",NULL);
	SDL_WM_SetIcon(IMG_Load("detective.png"),NULL);

	SDL_Surface *image=NULL,*image2=NULL;
	screen=NULL;

	screen=SDL_SetVideoMode(1366,768,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN );

	detective.frameTimer=0;

	if(!screen){
		fprintf(stderr,"Unable to set 600x400 video: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
		fprintf(stderr,"%s",Mix_GetError());
		exit(EXIT_FAILURE);
	}

	Mix_Music *music;
	music=Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music,-1);
	SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
	SDL_Flip(screen);

	initPerso(&detective,screen,1200,500);

	//loading image
	image=SDL_LoadBMP("background.bmp");
	image2=SDL_LoadBMP("backgroundCOLL.bmp");

	//Localisation Detective
	SDL_Rect positionecran;

	positionecran.x=0;
	positionecran.y=0;
	
	detective.perso[0]=IMG_Load("run_right.png");
	detective.perso[1]=IMG_Load("run_left.png");

    if(image==NULL){
        fprintf(stderr,"Unable to load bitmap: %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

	if(detective.perso[0]==NULL){
                fprintf(stderr,"Unable to load png: %s\n",SDL_GetError());
                exit(EXIT_FAILURE);
        }

	if(detective.perso[1]==NULL){
                fprintf(stderr,"Unable to load png: %s\n",SDL_GetError());
                exit(EXIT_FAILURE);
        }

	SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
	SDL_BlitSurface(image2,NULL,screen,&positionecran);
	SDL_BlitSurface(image,NULL,screen,&positionecran);
	affPerso(&detective,screen,0);
	SDL_Flip(screen);

	int continuer=1;
	SDL_Event event;

	while(continuer){
		SDL_PollEvent(&event);
		SDL_BlitSurface(image2,NULL,screen,&positionecran);
		switch(event.type){
			case SDL_QUIT:
				continuer=0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						continuer=0;
						break;
					case SDLK_UP:

						if(collision_Parfaite(image2,detective.C[0].X,detective.C[0].Y))
						{
							detective.frameNumber=0;
							detective.frameTimer=0;
							SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
							SDL_BlitSurface(image,NULL,screen,&positionecran);
							animerHero(0);
							SDL_Flip(screen);
						}
						else{
							detective.positionInit.y-=3;
							SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
							SDL_BlitSurface(image,NULL,screen,&positionecran);
							animerHero(0);
							SDL_Flip(screen);
						}
						break;

					case SDLK_DOWN:

						if(collision_Parfaite(image2,detective.C[1].X,detective.C[1].Y))
						{
							detective.frameNumber=0;
							detective.frameTimer=0;
							SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
							SDL_BlitSurface(image,NULL,screen,&positionecran);
							animerHero(0);
							SDL_Flip(screen);
						}
						else{
							detective.positionInit.y+=3;
							SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
							SDL_BlitSurface(image,NULL,screen,&positionecran);
							animerHero(0);
							SDL_Flip(screen);
						}
						break;

					case SDLK_RIGHT:

						if(collision_Parfaite(image2,detective.C[3].X,detective.C[3].Y))
						{
							detective.frameNumber=0;
							detective.frameTimer=0;
							SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
							SDL_BlitSurface(image,NULL,screen,&positionecran);
							animerHero(0);
							SDL_Flip(screen);
						}
						else{
							detective.positionInit.x+=3;
							SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
							SDL_BlitSurface(image,NULL,screen,&positionecran);
							animerHero(0);
							SDL_Flip(screen);
						}
						break;

					case SDLK_LEFT:

						if(collision_Parfaite(image2,detective.C[2].X,detective.C[2].Y))
						{
							detective.frameNumber=0;
							detective.frameTimer=0;
							SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
							SDL_BlitSurface(image,NULL,screen,&positionecran);
							animerHero(1);
							SDL_Flip(screen);
						}
						else
						{
							detective.positionInit.x-=3;
							SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
							SDL_BlitSurface(image,NULL,screen,&positionecran);
							animerHero(1);
							SDL_Flip(screen);
						}
						break;

				}
				break;
			/*case SDL_MOUSEMOTION:
            			detective.positionInit.x = event.motion.x;
            			detective.positionInit.y = event.motion.y;
            			break;*/
		}

		//SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
		//SDL_BlitSurface(image,NULL,screen,&positionecran);
		//affPerso(&detective,screen);
		//SDL_Flip(screen);
		
		
	}

	freePerso(&detective);
	SDL_FreeSurface(image);
	SDL_FreeSurface(image2);
	Mix_FreeMusic(music);

	SDL_Quit();
	return EXIT_SUCCESS;
}
