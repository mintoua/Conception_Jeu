#include"entete.h"

int main(void){

	SDL_Init(SDL_INIT_VIDEO);
	if(SDL_Init(SDL_INIT_VIDEO)!=0){
		fprintf(stderr,"Unable to initialize SDL: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("TunCity",NULL);
	SDL_WM_SetIcon(IMG_Load("gamepad.png"),NULL);

	SDL_Surface *screen=NULL,*background=NULL,*play=NULL,*settings=NULL,*quit=NULL,*Sbackground=NULL,*Svolume=NULL,*Scharacters=NULL,*Sback=NULL,*Sdifficulty=NULL,*v1=NULL,*v2=NULL,*v3=NULL,*v4=NULL,*v5=NULL,*v6=NULL,*v7=NULL,*v8=NULL,*v9=NULL,*v10=NULL,*v11=NULL;

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
	Sdifficulty=IMG_Load("setDifficulty.png");
	play=IMG_Load("Play.png");
	settings=IMG_Load("Settings.png");
	quit=IMG_Load("Quit.png");
	v1=IMG_Load("v1.png");
	v2=IMG_Load("v2.png");
	v3=IMG_Load("v3.png");
	v4=IMG_Load("v4.png");
	v5=IMG_Load("v5.png");
	v6=IMG_Load("v6.png");
	v7=IMG_Load("v7.png");
	v8=IMG_Load("v8.png");
	v9=IMG_Load("v9.png");
	v10=IMG_Load("v10.png");
	v11=IMG_Load("v11.png");

	if( (background==NULL) || (Sbackground==NULL) || (Svolume==NULL) || (Sback==NULL) || (Scharacters==NULL) || (play==NULL) || (settings==NULL) || (quit==NULL) || (v1==NULL) || (v2==NULL) || (v3==NULL) || (v4==NULL) || (v5==NULL) || (v6==NULL) || (v7==NULL) || (v8==NULL) || (v9==NULL) || (v10==NULL) || (v11==NULL) || (Sdifficulty==NULL)){
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

	SDL_Rect pdifficulty,pbackground,psettings,pplay,pquit,pvolume,pback,pcharacters;
	
	pquit.x=pplay.x=psettings.x=145.83;
	psettings.w=pplay.w=pquit.w=478.49;
	psettings.h=pplay.h=pquit.h=114.76;
	pcharacters.h=pvolume.h=pback.h=pdifficulty.h=62;	

	pcharacters.x=465.5;
	pcharacters.y=414;
	pcharacters.w=474.8;

	pvolume.x=558.5;
	pvolume.y=276;
	pvolume.w=283.5;

	pdifficulty.x=464;
	pdifficulty.y=543;
	pdifficulty.w=pcharacters.w;

	pback.x=612.7;
	pback.y=660.7;
	pback.w=179.4;
	
	psettings.y=391.52;
	pplay.y=261.66;
	pquit.y=519.83;

	pbackground.x=0;
	pbackground.y=0;

	SDL_BlitSurface(background,NULL,screen,&pbackground);
	SDL_Flip(screen);

	int volume=128;
	int continuer=1;
	int etat=1;
	int S_etat=0;
	int Vetat=11;
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
					case SDLK_RIGHT:
						if( (S_etat==2) && Vetat<11 ){
							Mix_PlayChannel(-1, bouton_sclic, 0);
						 	Vetat++;
							Mix_VolumeMusic(volume+=11);
							Mix_VolumeChunk(bouton_sclic,volume);
							Mix_VolumeChunk(bouton_clic,volume);
						}
					break;
					case SDLK_LEFT:
						if( (S_etat==2) && Vetat>1 ){
							Mix_PlayChannel(-1, bouton_sclic, 0);
						 	Vetat--;
							Mix_VolumeMusic(volume-=11);
							Mix_VolumeChunk(bouton_sclic,volume);
							Mix_VolumeChunk(bouton_clic,volume);
							if(Vetat==1){
								Mix_VolumeMusic(-1);
								Mix_VolumeChunk(bouton_clic,0);
								Mix_VolumeChunk(bouton_sclic,0);
							}
						}
					break;
					case SDLK_BACKSPACE:
						if(S_etat==2){
							S_etat=1;
							etat=8;
						}
						else if(S_etat==1){
							S_etat=0;
							etat=1;
						}
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
							 	if(etat!=3){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=psettings.x;
							event.motion.y=psettings.y;
							etat=3;
						}

						else if( (S_etat==0) && (etat==3) ){
							if(etat!=4){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pquit.x;
							event.motion.y=pquit.y;
							etat=4;
						}

						else if( (S_etat==0) && (etat==4) ){
							if(etat!=2){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pplay.x;
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
							if(etat!=9){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pdifficulty.x;
							event.motion.y=pdifficulty.y;
							etat=9;
						}

						else if( (S_etat==1) && (etat==9) ){
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
							if(etat!=4){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pquit.x;
							event.motion.y=pquit.y;
							etat=4;
						}

						else if( (S_etat==0) && (etat==2) ){
							if(etat!=4){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pquit.x;
							event.motion.y=pquit.y;
							etat=4;
						}

						else if( (S_etat==0) && (etat==3) ){
							if(etat!=2){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pplay.x;
							event.motion.y=pplay.y;
							etat=2;
						}

						else if( (S_etat==0) && (etat==4) ){
							if(etat!=3){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=psettings.x;
							event.motion.y=psettings.y;
							etat=3;
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

						else if( (S_etat==1) && (etat==9) ){
							if(etat!=6){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pcharacters.x;
							event.motion.y=pcharacters.y;
							etat=6;
						}
						else if( (S_etat==1) && (etat==7) ){
							if(etat!=9){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pdifficulty.x;
							event.motion.y=pdifficulty.y;
							etat=9;
						}

					break;
					case SDLK_RETURN:
						if( (etat==3) && (S_etat==0)){
							Mix_PlayChannel(-1, bouton_clic, 0);
							S_etat=1;
							etat=8;	
						}
						else if( (etat==7) && (S_etat==1) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							S_etat=0;
							etat=1;	
						}
						else if( (etat==4) && (S_etat==0)){
							Mix_PlayChannel(-1, bouton_clic, 0);
							continuer=0;
						}
						else if( (etat==5) && (S_etat==1) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							S_etat=2;
						}
						else if( (etat==9) && (S_etat==1) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							S_etat=3;
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
					if(etat!=4){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=4;
				}

				else if( (event.motion.x>=psettings.x) && (event.motion.x<=(psettings.x+478.49) ) && (event.motion.y>=psettings.y) && (event.motion.y<=(psettings.y+114.76) ) && (S_etat==0) ){
					if(etat!=3){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=3;
				}
				else if( (event.motion.x>=pdifficulty.x) && (event.motion.x<=(pdifficulty.x+pdifficulty.w) ) && (event.motion.y>=pdifficulty.y) && (event.motion.y<=(pdifficulty.y+pdifficulty.h) ) && (S_etat==1) ){
					if(etat!=9){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=9;	
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

				else if( !( (event.motion.x>=pvolume.x) && (event.motion.x<=(pvolume.x+283.5) ) && (event.motion.y>=pvolume.y) && (event.motion.y<=(pvolume.y+62) ) ) && !( (event.motion.x>=pdifficulty.x) && (event.motion.x<=(pdifficulty.x+pdifficulty.w) ) && (event.motion.y>=pdifficulty.y) && (event.motion.y<=(pdifficulty.y+pdifficulty.h) )) && !( (event.motion.x>=pback.x) && (event.motion.x<=(pback.x+pback.w) ) && (event.motion.y>=pback.y) && (event.motion.y<=(pback.y+pcharacters.h) ) ) && !( (event.motion.x>=pcharacters.x) && (event.motion.x<=(pcharacters.x+pcharacters.w) ) && (event.motion.y>=pcharacters.y) && (event.motion.y<=(pcharacters.y+pcharacters.h) ) ) && (S_etat==1) ){
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
				else if( (event.button.x>=pdifficulty.x) && (event.button.x<=(pdifficulty.x+pdifficulty.w) ) && (event.button.y>=pdifficulty.y) && ( event.button.y<=(pdifficulty.y+pdifficulty.h) ) && (S_etat==1) && (event.button.button=SDL_BUTTON_LEFT)){
					Mix_PlayChannel(-1, bouton_sclic, 0);
					S_etat=3;
				}
				else if( (event.button.x>=pquit.x) && (event.button.x<=(pquit.x+pquit.w) ) && (event.button.y>=pquit.y) && (event.button.y<=(pquit.y+pquit.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==0)){
					Mix_PlayChannel(-1, bouton_clic, 0);{
					continuer=0;		
					}
				}
				else if( (event.button.x>=pvolume.x) && (event.button.x<=(pvolume.x+283.5) ) && (event.button.y>=pvolume.y) && (event.button.y<=(pvolume.y+62) ) && (S_etat==1) && (event.button.button=SDL_BUTTON_LEFT)){
					Mix_PlayChannel(-1, bouton_sclic, 0);
					S_etat=2;
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
		else if(etat==4 && S_etat==0){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(quit,NULL,screen,&pbackground);
			SDL_Flip(screen);
		}
		else if(etat==3 && S_etat==0){
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
		else if(etat==9 && S_etat==1){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(Sdifficulty,NULL,screen,&pbackground);
			SDL_Flip(screen);
		}
		if(Vetat==1 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,255,255));
			SDL_BlitSurface(v1,NULL,screen,&pbackground);
			SDL_Flip(screen);
			SDL_Flip(screen);
		}
		else if(Vetat==2 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v2,NULL,screen,&pbackground);
			SDL_Flip(screen);
			SDL_Flip(screen);	
		}
		else if(Vetat==3 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v3,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(Vetat==4 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v4,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(Vetat==5 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v5,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(Vetat==6 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v6,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(Vetat==7 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v7,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(Vetat==8 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v8,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(Vetat==9 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v9,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(Vetat==10 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v10,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(Vetat==11 && S_etat==2){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(v11,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
	}


	SDL_FreeSurface(v1);
	SDL_FreeSurface(v2);
	SDL_FreeSurface(v3);
	SDL_FreeSurface(v4);
	SDL_FreeSurface(v5);
	SDL_FreeSurface(v6);
	SDL_FreeSurface(v7);
	SDL_FreeSurface(v8);
	SDL_FreeSurface(v9);
	SDL_FreeSurface(v10);
	SDL_FreeSurface(v11);
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
