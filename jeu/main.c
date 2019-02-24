#include"entete.h"

int main(void){

	SDL_Init(SDL_INIT_VIDEO);
	if(SDL_Init(SDL_INIT_VIDEO)!=0){
		fprintf(stderr,"Unable to initialize SDL: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("TunCity",NULL);
	SDL_WM_SetIcon(IMG_Load("gamepad.png"),NULL);

	SDL_Surface *screen=NULL,*background=NULL,*play=NULL,*settings=NULL,*quit=NULL,*Sbackground=NULL,*Svolume=NULL,*Scharacters=NULL,*Sback=NULL;
	screen=SDL_SetVideoMode(1365,768,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);

	if(!screen){
		fprintf(stderr,"Unable to set 1366x768 video: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
		fprintf(stderr,"%s",Mix_GetError());
		exit(EXIT_FAILURE);
	}

	Sbackground=IMG_Load("setMenu.png");
	Svolume=IMG_Load("setVolume.png");
	Sback=IMG_Load("setBack.png");
	Scharacters=IMG_Load("setCharacters.png");
	background=IMG_Load("Tuncity_menu_3.png");
	play=IMG_Load("Play.png");
	settings=IMG_Load("Settings.png");
	quit=IMG_Load("Quit.png");

	if( (background==NULL) || (Sbackground==NULL) || (Svolume==NULL) || (Sback==NULL) || (Scharacters==NULL) || (play==NULL) || (settings==NULL) || (quit==NULL) ){
		fprintf(stderr,"Unable to load png: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Mix_Music *mbackground;
	Mix_Chunk *bouton_sclic,*bouton_clic;
	mbackground=Mix_LoadMUS("MBackground.mp3");
	bouton_sclic=Mix_LoadWAV("Menu - Passage souris.wav");
	bouton_clic=Mix_LoadWAV("Menu - entrée.wav");

	if( (bouton_sclic== NULL ) || (bouton_clic== NULL ) || (mbackground==NULL) ){
		fprintf(stderr,"%s",Mix_GetError());
	        exit(EXIT_FAILURE);    
    	}

	
	Mix_FadeInMusic(mbackground, -1, 120000);

	SDL_FillRect(screen,0,SDL_MapRGB(screen->format,255,255,0));

	SDL_Flip(screen);

	SDL_Rect pbackground,psettings,pplay,pquit,pvolume,pback,pcharacters;
	
	pquit.x=pplay.x=psettings.x=145.83;
	psettings.w=pplay.w=pquit.w=478.49;
	psettings.h=pplay.h=pquit.h=114.76;
	pcharacters.h=pvolume.h=pback.h=62;	

	pcharacters.x=465.5;
	pcharacters.y=414;
	pcharacters.w=474.8;

	pvolume.x=558.5;
	pvolume.y=276;
	pvolume.w=283.5;

	pback.x=613;
	pback.y=542;
	pback.w=180;
	
	psettings.y=391.52;
	pplay.y=261.66;
	pquit.y=519.83;

	pbackground.x=0;
	pbackground.y=0;


	SDL_BlitSurface(background,NULL,screen,&pbackground);
	SDL_Flip(screen);

	int continuer=1;
	int etat=1;
	int S_etat=0;
	SDL_Event event;
	
	while(continuer){
		SDL_WaitEvent(&event);
		switch(event.type){
			case SDL_QUIT:
				continuer=0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						continuer=0;
						break;
					case SDLK_DOWN:
						if( (S_etat==0) && (etat==1) ){
							if(etat!=2){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pplay.x;
							event.motion.y=pplay.y;
							etat=2;
						}

						else if( (S_etat==0) && (etat==2) ){
							if(etat!=4){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=psettings.x;
							event.motion.y=psettings.y;
							etat=4;
						}

						else if( (S_etat==0) && (etat==4) ){
							if(etat!=3){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pquit.x;
							event.motion.y=pquit.y;
							etat=3;
						}

						else if( (S_etat==0) && (etat==3) ){
							if(etat!=2){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pplay.x;s
							event.motion.y=pplay.y;
							etat=2;
						}
						
						else if( (S_etat==1) && (etat==8) ){
							if(etat!=5){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pvolume.x;
							event.motion.y=pvolume.y;
							etat=5;
						}

						else if( (S_etat==1) && (etat==5) ){
							if(etat!=6){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pcharacters.x;
							event.motion.y=pcharacters.y;
							etat=6;
						}

						else if( (S_etat==1) && (etat==6) ){
							if(etat!=7){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pback.x;
							event.motion.y=pback.y;
							etat=7;
						}

						else if( (S_etat==1) && (etat==7) ){
							if(etat!=5){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pvolume.x;
							event.motion.y=pvolume.y;
							etat=5;
						}
					break;
					case SDLK_UP:
						if( (S_etat==0) && (etat==1) ){
							if(etat!=3){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pquit.x;
							event.motion.y=pquit.y;
							etat=3;
						}

						else if( (S_etat==0) && (etat==2) ){
							if(etat!=3){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pquit.x;
							event.motion.y=pquit.y;
							etat=3;
						}

						else if( (S_etat==0) && (etat==4) ){
							if(etat!=2){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pplay.x;
							event.motion.y=pplay.y;
							etat=2;
						}

						else if( (S_etat==0) && (etat==3) ){
							if(etat!=4){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=psettings.x;
							event.motion.y=psettings.y;
							etat=4;
						}
						
						else if( (S_etat==1) && (etat==8) ){
							if(etat!=7){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pback.x;
							event.motion.y=pback.y;
							etat=7;
						}

						else if( (S_etat==1) && (etat==5) ){
							if(etat!=7){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pback.x;
							event.motion.y=pback.y;
							etat=7;
						}

						else if( (S_etat==1) && (etat==6) ){
							if(etat!=5){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							etat=5;
							event.motion.x=pvolume.x;
							event.motion.y=pvolume.y;
						}

						else if( (S_etat==1) && (etat==7) ){
							if(etat!=6){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pcharacters.x;
							event.motion.y=pcharacters.y;
							etat=6;
						}
					break;
					case SDLK_RETURN:
						if( (etat==4) && (S_etat==0)){
							Mix_PlayChannel(-1, bouton_clic, 0);
							S_etat=1;
							etat=8;	
						}
						else if( (etat==7) && (S_etat==1) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							S_etat=0;
							etat=1;	
						}
						else if( (etat==3) && (S_etat==0)){
							Mix_PlayChannel(-1, bouton_clic, 0);
							continuer=0;
						}

					break;
				}




			case SDL_MOUSEMOTION:
				if( (event.motion.x>=pplay.x) && (event.motion.x<=(pplay.x+478.49) ) && (event.motion.y>=pplay.y) && (event.motion.y<=(pplay.y+114.76) ) && (S_etat==0) ){
					if(etat!=2){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=2;
				}

				else if( (event.motion.x>=pquit.x) && (event.motion.x<=(pquit.x+478.49) ) && (event.motion.y>=pquit.y) && (event.motion.y<=(pquit.y+114.76) ) && (S_etat==0) ){
					if(etat!=3){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=3;
				}

				else if( (event.motion.x>=psettings.x) && (event.motion.x<=(psettings.x+478.49) ) && (event.motion.y>=psettings.y) && (event.motion.y<=(psettings.y+114.76) ) && (S_etat==0) ){
					if(etat!=4){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=4;
				}

				else if(!( (event.motion.x>=pquit.x) && (event.motion.x<=(pquit.x+478.49) ) && (event.motion.y>=pquit.y) && (event.motion.y<=(pquit.y+114.76) ) ) && !( (event.motion.x>=pquit.x) && (event.motion.x<=(pquit.x+478.49) ) && (event.motion.y>=pquit.y) && (event.motion.y<=(pquit.y+114.76) ) ) && !( (event.motion.x>=pplay.x) && (event.motion.x<=(pplay.x+478.49) ) && (event.motion.y>=pplay.y) && (event.motion.y<=(pplay.y+114.76) ) ) && (S_etat==0) )
					etat=1;
				
				else if( (event.motion.x>=pvolume.x) && (event.motion.x<=(pvolume.x+283.5) ) && (event.motion.y>=pvolume.y) && (event.motion.y<=(pvolume.y+62) ) && (S_etat==1) ){
					if(etat!=5){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=5;
				}		

				else if( (event.motion.x>=pcharacters.x) && (event.motion.x<=(pcharacters.x+pcharacters.w) ) && (event.motion.y>=pcharacters.y) && (event.motion.y<=(pcharacters.y+pcharacters.h) ) && (S_etat==1) ){
					if(etat!=6){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=6;
				}		

				else if( (event.motion.x>=pback.x) && (event.motion.x<=(pback.x+pback.w) ) && (event.motion.y>=pback.y) && (event.motion.y<=(pback.y+pcharacters.h) ) && (S_etat==1) ){
					if(etat!=7){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=7;
				}		

				else if( !( (event.motion.x>=pvolume.x) && (event.motion.x<=(pvolume.x+283.5) ) && (event.motion.y>=pvolume.y) && (event.motion.y<=(pvolume.y+62) ) ) && !( (event.motion.x>=pback.x) && (event.motion.x<=(pback.x+pback.w) ) && (event.motion.y>=pback.y) && (event.motion.y<=(pback.y+pcharacters.h) ) ) && !( (event.motion.x>=pcharacters.x) && (event.motion.x<=(pcharacters.x+pcharacters.w) ) && (event.motion.y>=pcharacters.y) && (event.motion.y<=(pcharacters.y+pcharacters.h) ) ) && (S_etat==1) ){
					etat=8;
				}		
				break;
				




			case SDL_MOUSEBUTTONUP:
				if( (event.button.x>=psettings.x) && (event.button.x<=(psettings.x+478.49) ) && (event.button.y>=psettings.y) && (event.button.y<=(psettings.y+114.76) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==0)){
					Mix_PlayChannel(-1, bouton_clic, 0);
					S_etat=1;
					etat=8;	
				}
				else if( (event.button.x>=pback.x) && (event.button.x<=(pback.x+pback.w) ) && (event.button.y>=pback.y) && (event.button.y<=(pback.y+pback.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==1)){
					Mix_PlayChannel(-1, bouton_clic, 0);{
					S_etat=0;
					etat=1;			
					}
				}
				else if( (event.button.x>=pquit.x) && (event.button.x<=(pquit.x+pquit.w) ) && (event.button.y>=pquit.y) && (event.button.y<=(pquit.y+pquit.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==0)){
					Mix_PlayChannel(-1, bouton_clic, 0);{
					continuer=0;		
					}
				}

				break;
		}



		if(etat==1 && S_etat==0){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(background,NULL,screen,&pbackground);
			SDL_Flip(screen);
		}
		else if(etat==2 && S_etat==0){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(play,NULL,screen,&pbackground);
			SDL_Flip(screen);
		}
		else if(etat==3 && S_etat==0){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(quit,NULL,screen,&pbackground);
			SDL_Flip(screen);
		}
		else if(etat==4 && S_etat==0){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(settings,NULL,screen,&pbackground);
			SDL_Flip(screen);
		}

		else if(etat==5 && S_etat==1){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(Svolume,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(etat==6 && S_etat==1){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(Scharacters,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(etat==7 && S_etat==1){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(Sback,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(etat==8 && S_etat==1){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(Sbackground,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
	}


	SDL_FreeSurface(play);
	SDL_FreeSurface(settings);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(background);
	SDL_FreeSurface(screen);
	SDL_FreeSurface(Sback);
	SDL_FreeSurface(Sbackground);
	SDL_FreeSurface(Svolume);
	SDL_FreeSurface(Scharacters);
	Mix_FreeMusic(mbackground);
	Mix_FreeChunk(bouton_clic);
   	Mix_FreeChunk(bouton_sclic);

	Mix_CloseAudio();
	SDL_Quit();
	return EXIT_SUCCESS;
}
