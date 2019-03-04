#include"entete.h"

int main(void){

	SDL_Init(SDL_INIT_VIDEO);
	if(SDL_Init(SDL_INIT_VIDEO)!=0){
		fprintf(stderr,"Unable to initialize SDL: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("TunCity",NULL);
	SDL_WM_SetIcon(IMG_Load("gamepad.png"),NULL);

	SDL_Surface *screen=NULL,*background=NULL,*play=NULL,*settings=NULL,*quit=NULL,*Sbackground=NULL,*Svolume=NULL,*Scharacters=NULL,*Sback=NULL,*Sdifficulty=NULL,*v1=NULL,*v2=NULL,*v3=NULL,*v4=NULL,*v5=NULL,*v6=NULL,*v7=NULL,*v8=NULL,*v9=NULL,*v10=NULL,*v11=NULL,*mDiff=NULL,*mDiffB=NULL,*mDiffE=NULL,*mDiffM=NULL,*mDiffH=NULL,*mJ=NULL,*mJB=NULL,*mJC=NULL,*mJNG=NULL;

	screen=SDL_SetVideoMode(1365,768,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);

	if(!screen){
		fprintf(stderr,"Unable to set 1366x768 video: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
		fprintf(stderr,"%s",Mix_GetError());
		exit(EXIT_FAILURE);
	}

	FILE *f=NULL;

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
	mDiff=IMG_Load("mDifficulty.png");
	mDiffB=IMG_Load("mDifficultyB.png");
	mDiffE=IMG_Load("mDifficultyE.png");
	mDiffM=IMG_Load("mDifficultyM.png");
	mDiffH=IMG_Load("mDifficultyH.png");
	mJ=IMG_Load("mJouer.png");
	mJB=IMG_Load("mJouerB.png");
	mJC=IMG_Load("mJouerC.png");
	mJNG=IMG_Load("mJouerNG.png");



	if( (background==NULL) || (Sbackground==NULL) || (Svolume==NULL) || (Sback==NULL) || (Scharacters==NULL) || (play==NULL) || (settings==NULL) || (quit==NULL) || (v1==NULL) || (v2==NULL) || (v3==NULL) || (v4==NULL) || (v5==NULL) || (v6==NULL) || (v7==NULL) || (v8==NULL) || (v9==NULL) || (v10==NULL) || (v11==NULL) || (mDiff==NULL) || (mDiffB==NULL) || (mDiffE==NULL) || (mDiffM==NULL) || (mDiffH==NULL) || (mJB==NULL) || (mJC==NULL) || (mJNG==NULL) || (mJ==NULL) || (Sdifficulty==NULL)){
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

	SDL_Rect pdifficulty,pbackground,psettings,pplay,pquit,pvolume,pback,pcharacters,peasy,pmedium,phard,pnewgame,pcontinue,pJback;
	
	//*mDiff=NULL,*mDiffB=NULL,*mDiffE=NULL,*mDiffM=NULL,*mDiffH=NULL,*mJ=NULL,*mJB=NULL,*mJC=NULL,*mJNG=NULL

	pquit.x=pplay.x=psettings.x=145.83;
	psettings.w=pplay.w=pquit.w=478.49;
	psettings.h=pplay.h=pquit.h=114.76;
	pcharacters.h=pvolume.h=pback.h=pdifficulty.h=peasy.h=pmedium.h=phard.h=pnewgame.h=pJback.h=pcontinue.h=62;	

	pcharacters.x=465.5;
	pcharacters.y=414;
	pcharacters.w=474.8;

	peasy.x=569.2;
	peasy.y=274.7;
	peasy.w=337;

	pnewgame.x=336.5;
	pnewgame.y=274.5;
	pnewgame.w=376.9;

	pcontinue.x=336.5;
	pcontinue.y=419.7;
	pcontinue.w=376.9;

	pJback.x=336.5;
	pJback.y=550.8;
	pJback.w=179.6;

	pmedium.x=514.6;
	pmedium.y=415.1;
	pmedium.w=440.6;

	phard.x=540.9;
	phard.y=541.8;
	phard.w=398.9;

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
						if(S_etat==1)
							S_etat--;
						else if(S_etat==2)
							S_etat--;
						else if(S_etat==3)
							S_etat=0;
						else if(S_etat==4)
							S_etat=1;
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

						else if( (S_etat==3) && (etat==10) ){
							if(etat!=11){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pnewgame.x;
							event.motion.y=pnewgame.y;
							etat=11;
						}

						else if( (S_etat==3) && (etat==11) ){
							 	if(etat!=12){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pcontinue.x;
							event.motion.y=pcontinue.y;
							etat=12;
						}

						else if( (S_etat==3) && (etat==12) ){
							if(etat!=13){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pJback.x;
							event.motion.y=pJback.y;
							etat=13;
						}
						
						else if( (S_etat==3) && (etat==13) ){
							if(etat!=11){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pnewgame.x;
							event.motion.y=pnewgame.y;
							etat=11;
						}

						else if( (S_etat==4) && (etat==14) ){
							if(etat!=15){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=peasy.x;
							event.motion.y=peasy.y;
							etat=15;
						}

						else if( (S_etat==4) && (etat==18) ){
							if(etat!=15){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=peasy.x;
							event.motion.y=peasy.y;
							etat=15;
						}

						else if( (S_etat==4) && (etat==15) ){
							 	if(etat!=16){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pmedium.x;
							event.motion.y=pmedium.y;
							etat=16;
						}

						else if( (S_etat==4) && (etat==16) ){
							if(etat!=17){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=phard.x;
							event.motion.y=phard.y;
							etat=17;
						}

						else if( (S_etat==4) && (etat==17) ){
							if(etat!=18){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pback.x;
							event.motion.y=pback.y;
							etat=18;
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

						else if( (S_etat==3) && (etat==10) ){
							if(etat!=13){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pJback.x;
							event.motion.y=pJback.y;
							etat=13;
						}

						else if( (S_etat==3) && (etat==11) ){
							if(etat!=13){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pJback.x;
							event.motion.y=pJback.y;
							etat=13;
						}

						else if( (S_etat==3) && (etat==12) ){
							if(etat!=11){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pnewgame.x;
							event.motion.y=pnewgame.y;
							etat=11;
						}

						else if( (S_etat==3) && (etat==13) ){
							if(etat!=12){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pcontinue.x;
							event.motion.y=pcontinue.y;
							etat=12;
						}

						else if( (S_etat==4) && (etat==14) ){
							if(etat!=18){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pback.x;
							event.motion.y=pback.y;
							etat=18;
						}

						else if( (S_etat==4) && (etat==15) ){
							if(etat!=18){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pback.x;
							event.motion.y=pback.y;
							etat=18;
						}

						else if( (S_etat==4) && (etat==18) ){
							if(etat!=17){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=phard.x;
							event.motion.y=phard.y;
							etat=17;
						}

						else if( (S_etat==4) && (etat==17) ){
							if(etat!=16){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=pmedium.x;
							event.motion.y=pmedium.y;
							etat=16;
						}

						else if( (S_etat==4) && (etat==16) ){
							if(etat!=15){
								Mix_PlayChannel(-1, bouton_sclic, 0);
							}
							event.motion.x=peasy.x;
							event.motion.y=peasy.y;
							etat=15;
						}
					break;
					case SDLK_RETURN:
						if( (etat==3) && (S_etat==0) || ( (etat==18) && (S_etat==4) ) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							S_etat=1;
							etat=8;	
						}
						else if( ( (etat==7) && (S_etat==1) ) || ( (etat==13) && (S_etat==3) ) ){
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
						else if( (etat==2) && (S_etat==0) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							S_etat=3;
							etat=10;
						}
						else if( (etat==9) && (S_etat==1) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							S_etat=4;
							etat=14;
						}
						else if( (etat==15) && (S_etat==4) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							f=fopen("difficulty.txt","w");
							if(f!=NULL){
								fprintf(f,"easy");
							}
							else
								printf("\nLe fichier ne s'est pas ouvert correctement.\n");
							fclose(f);
						}
						else if( (etat==16) && (S_etat==4) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							f=fopen("difficulty.txt","w");
							if(f!=NULL){
								fprintf(f,"medium");
							}
							else
								printf("\nLe fichier ne s'est pas ouvert correctement.\n");
							fclose(f);
						}
						else if( (etat==15) && (S_etat==4) ){
							Mix_PlayChannel(-1, bouton_clic, 0);
							f=fopen("difficulty.txt","w");
							if(f!=NULL){
								fprintf(f,"hard");
							}
							else
								printf("\nLe fichier ne s'est pas ouvert correctement.\n");
							fclose(f);
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
				else if( (event.motion.x>=pnewgame.x) && (event.motion.x<=(pnewgame.x+pnewgame.w) ) && (event.motion.y>=pnewgame.y) && (event.motion.y<=(pnewgame.y+pnewgame.h) ) && (S_etat==3) ){
					if(etat!=11){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=11;
				}
				else if( (event.motion.x>=pcontinue.x) && (event.motion.x<=(pcontinue.x+pcontinue.w) ) && (event.motion.y>=pcontinue.y) && (event.motion.y<=(pcontinue.y+pcontinue.h) ) && (S_etat==3) ){
					if(etat!=12){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=12;
				}
				else if( (event.motion.x>=pJback.x) && (event.motion.x<=(pJback.x+pJback.w) ) && (event.motion.y>=pJback.y) && (event.motion.y<=(pJback.y+pJback.h) ) && (S_etat==3) ){
					if(etat!=13){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=13;
				}
				else if( !((event.motion.x>=pnewgame.x) && (event.motion.x<=(pnewgame.x+pnewgame.w) ) && (event.motion.y>=pnewgame.y) && (event.motion.y<=(pnewgame.y+pnewgame.h) )) && !( (event.motion.x>=pcontinue.x) && (event.motion.x<=(pcontinue.x+pcontinue.w) ) && (event.motion.y>=pcontinue.y) && (event.motion.y<=(pcontinue.y+pcontinue.h) )) && !( (event.motion.x>=pJback.x) && (event.motion.x<=(pJback.x+pJback.w) ) && (event.motion.y>=pJback.y) && (event.motion.y<=(pJback.y+pJback.h) )) && (S_etat==3) ){
					etat=10;
				}

				else if( (event.motion.x>=peasy.x) && (event.motion.x<=(peasy.x+peasy.w) ) && (event.motion.y>=peasy.y) && (event.motion.y<=(peasy.y+peasy.h) ) && (S_etat==4) ){
					if(etat!=15){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=15;
				}

				else if( (event.motion.x>=pmedium.x) && (event.motion.x<=(pmedium.x+pmedium.w) ) && (event.motion.y>=pmedium.y) && (event.motion.y<=(pmedium.y+pmedium.h) ) && (S_etat==4) ){
					if(etat!=16){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=16;
				}
				else if( (event.motion.x>=phard.x) && (event.motion.x<=(phard.x+phard.w) ) && (event.motion.y>=phard.y) && (event.motion.y<=(phard.y+phard.h) ) && (S_etat==4) ){
					if(etat!=17){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=17;
				}
				else if( (event.motion.x>=pback.x) && (event.motion.x<=(pback.x+pback.w) ) && (event.motion.y>=pback.y) && (event.motion.y<=(pback.y+pback.h) ) && (S_etat==4) ){
					if(etat!=18){
						Mix_PlayChannel(-1, bouton_sclic, 0);
					}
					etat=18;
				}
				else if( !((event.motion.x>=peasy.x) && (event.motion.x<=(peasy.x+peasy.w) ) && (event.motion.y>=peasy.y) && (event.motion.y<=(peasy.y+peasy.h) )) && !( (event.motion.x>=pmedium.x) && (event.motion.x<=(pmedium.x+pmedium.w) ) && (event.motion.y>=pmedium.y) && (event.motion.y<=(pmedium.y+pmedium.h) )) && !( (event.motion.x>=pback.x) && (event.motion.x<=(pback.x+pback.w) ) && (event.motion.y>=pback.y) && (event.motion.y<=(pback.y+pback.h) )) && !( (event.motion.x>=pback.x) && (event.motion.x<=(pback.x+pback.w) ) && (event.motion.y>=pback.y) && (event.motion.y<=(pback.y+pback.h) ) ) && (S_etat==3) ){
					etat=14;
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

				else if( (event.button.x>=pvolume.x) && (event.button.x<=(pvolume.x+283.5) ) && (event.button.y>=pvolume.y) && (event.button.y<=(pvolume.y+62) ) && (S_etat==1) && (event.button.button=SDL_BUTTON_LEFT)){
					Mix_PlayChannel(-1, bouton_sclic, 0);
					S_etat=2;
				}

				else if( (event.button.x>=pplay.x) && (event.button.x<=(pplay.x+pplay.w) ) && (event.button.y>=pplay.y) && (event.button.y<=(pplay.y+62) ) && (S_etat==0) && (event.button.button=SDL_BUTTON_LEFT)){
					Mix_PlayChannel(-1, bouton_sclic, 0);
					S_etat=3;
				}

				else if( (event.button.x>=pdifficulty.x) && (event.button.x<=(pdifficulty.x+pdifficulty.y) ) && (event.button.y>=pdifficulty.y) && (event.button.y<=(pdifficulty.y+62) ) && (S_etat==1) && (event.button.button=SDL_BUTTON_LEFT)){
					Mix_PlayChannel(-1, bouton_sclic, 0);
					S_etat=4;
				}

				else if( (event.button.x>=pJback.x) && (event.button.x<=(pJback.x+pJback.w) ) && (event.button.y>=pJback.y) && (event.button.y<=(pJback.y+pJback.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==3)){
					Mix_PlayChannel(-1, bouton_clic, 0);{
					S_etat=0;
					etat=1;			
					}
				}

				else if( (event.button.x>=pback.x) && (event.button.x<=(pback.x+pback.w) ) && (event.button.y>=pback.y) && (event.button.y<=(pback.y+pback.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==4)){
					Mix_PlayChannel(-1, bouton_clic, 0);
					S_etat=1;
					etat=8;	
				}
///
				else if( (event.button.x>=peasy.x) && (event.button.x<=(peasy.x+peasy.w) ) && (event.button.y>=peasy.y) && (event.button.y<=(peasy.y+peasy.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==4)){
					Mix_PlayChannel(-1, bouton_clic, 0);
					f=fopen("difficulty.txt","w");
					if(f!=NULL){
						fprintf(f,"easy");
					}
					else
						printf("\nLe fichier ne s'est pas ouvert correctement.\n");
					fclose(f);
				}
				else if( (event.button.x>=pmedium.x) && (event.button.x<=(pmedium.x+pmedium.w) ) && (event.button.y>=pmedium.y) && (event.button.y<=(pmedium.y+pmedium.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==4)){
					Mix_PlayChannel(-1, bouton_clic, 0);
					f=fopen("difficulty.txt","w");
					if(f!=NULL){
						fprintf(f,"medium");
					}
					else
						printf("\nLe fichier ne s'est pas ouvert correctement.\n");
					fclose(f);
				}
				else if( (event.button.x>=phard.x) && (event.button.x<=(phard.x+phard.w) ) && (event.button.y>=phard.y) && (event.button.y<=(phard.y+phard.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==4)){
					Mix_PlayChannel(-1, bouton_clic, 0);
					f=fopen("difficulty.txt","w");
					if(f!=NULL){
						fprintf(f,"hard");
					}
					else
						printf("\nLe fichier ne s'est pas ouvert correctement.\n");
					fclose(f);
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

	//*mDiff=NULL,*mDiffB=NULL,*mDiffE=NULL,*mDiffM=NULL,*mDiffH=NULL,*mJ=NULL,*mJB=NULL,*mJC=NULL,*mJNG=NULL

		else if(S_etat==3 && etat==10){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(mJ,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(S_etat==3 && etat==11){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(mJNG,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(S_etat==3 && etat==12){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(mJC,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(S_etat==3 && etat==13){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(mJB,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(S_etat==4 && etat==14){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(mDiff,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(S_etat==4 && etat==15){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(mDiffE,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(S_etat==4 && etat==16){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(mDiffM,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(S_etat==4 && etat==17){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(mDiffH,NULL,screen,&pbackground);
			SDL_Flip(screen);	
		}
		else if(S_etat==4 && etat==18){
			SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
			SDL_BlitSurface(mDiffB,NULL,screen,&pbackground);
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
	SDL_FreeSurface(mJ);
	SDL_FreeSurface(mJNG);
	SDL_FreeSurface(mJC);
	SDL_FreeSurface(mJB);
	SDL_FreeSurface(mDiff);
	SDL_FreeSurface(mDiffE);
	SDL_FreeSurface(mDiffM);
	SDL_FreeSurface(mDiffH);
	SDL_FreeSurface(mDiffB);
	
	Mix_FreeMusic(mbackground);
	Mix_FreeChunk(bouton_clic);
   	Mix_FreeChunk(bouton_sclic);

	Mix_CloseAudio();
	SDL_Quit();
	return EXIT_SUCCESS;
}
