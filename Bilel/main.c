/**
* @file main.c
* @date Apr 28, 2019
* @brief yes
* @version 0.1
* @author Bilel Taktak
*/
#include"entete.h"

int main(void){

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_WM_SetCaption("TunCity",NULL);
	SDL_WM_SetIcon(IMG_Load("detective.png"),NULL);

	/***********************************/

	if(SDL_Init(SDL_INIT_VIDEO)!=0){
		fprintf(stderr,"Unable to initialize SDL: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
		fprintf(stderr,"%s",Mix_GetError());
		exit(EXIT_FAILURE);
	}

	/***********************************/

	int save,volume,continuer,etat,S_etat,Vetat;
	FILE *f=NULL;
	SDL_Surface *image=NULL,*image2=NULL;
	SDL_Rect pbackground,positionecran;
	SDL_Event event,ing,event2;
    Mix_Music *mbackground;
	Mix_Chunk *bouton_sclic,*bouton_clic;

	/***********************************/

	screen=SDL_SetVideoMode(1366,760,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);

	volume=128;
	continuer=1;
	etat=1;
	S_etat=0;
	Vetat=11;
	Game=0;
	save=0;

	save=numberSave("sauvegarde.txt",save);

	image=SDL_LoadBMP("Maison.bmp");
	image2=SDL_LoadBMP("MaisonCOLL.bmp");


	initButton(&Backgrounds[0],0,0,1366,768,"setMenu.png");
	initButton(&Backgrounds[1],0,0,1366,768,"Tuncity_menu_3.png");
	initButton(&Backgrounds[2],0,0,1366,768,"mDifficulty.png");
	initButton(&Backgrounds[3],0,0,1366,768,"mJouer.png");
	initButton(&Backgrounds[4],0,0,1366,768,"mJouerB.png");
	initButton(&Backgrounds[5],0,0,1366,768,"SG.png");
	initButton(&Backgrounds[6],0,0,1366,768,"SM.png");
    
	initButton(&Buttons[0],145.83,261.66,478.49,114.76,"Play.png");
	initButton(&Buttons[1],145.83,391.52,478.49,114.76,"Settings.png");
	initButton(&Buttons[2],145.83,519.83,478.49,114.76,"Quit.png");
	initButton(&Buttons[3],611,275,181,62,"SGzqsd.png");
	initButton(&Buttons[4],458,477,482,62,"SGarrow.png");
	initButton(&Buttons[5],611,660,181,62,"SGback.png");
	initButton(&Buttons[6],613,542,180,62,"SMquit.png");
	initButton(&Buttons[7],491,414,428,62,"SMsave.png");
	initButton(&Buttons[8],558.5,276,283.5,62,"SMvolume.png");
	initButton(&Buttons[9],514,543,378,62,"SMgameplay.png");
	initButton(&Buttons[10],569.2,274.7,337,62,"mDifficultyE.png");
	initButton(&Buttons[11],514.6,415.1,440.6,62,"mDifficultyM.png");
	initButton(&Buttons[12],540.9,541.8,398.9,62,"mDifficultyH.png");
	initButton(&Buttons[13],336.5,550.8,179.6,62,"mDifficultyB.png");
	initButton(&Buttons[14],336.5,274.5,376.9,62,"mJouerNG.png");
	initButton(&Buttons[15],336.5,419.7,376.9,62,"mJouerC.png");
	initButton(&Buttons[16],558.5,276,283.5,62,"setVolume.png");
	initButton(&Buttons[17],464,543,474.8,62,"setDifficulty.png");
	initButton(&Buttons[18],612.7,660.7,179.4,62,"setBack.png");
	initButton(&Buttons[19],465.5,414,474.8,62,"setCharacters.png");

	initButton(&Volumes[0],0,0,0,0,"v1.png");
	initButton(&Volumes[1],0,0,0,0,"v2.png");
	initButton(&Volumes[2],0,0,0,0,"v3.png");
	initButton(&Volumes[3],0,0,0,0,"v4.png");
	initButton(&Volumes[4],0,0,0,0,"v5.png");
	initButton(&Volumes[5],0,0,0,0,"v6.png");
	initButton(&Volumes[6],0,0,0,0,"v7.png");
	initButton(&Volumes[7],0,0,0,0,"v8.png");
	initButton(&Volumes[8],0,0,0,0,"v9.png");
	initButton(&Volumes[9],0,0,0,0,"v10.png");
	initButton(&Volumes[10],0,0,0,0,"v11.png");

	detective.perso[0]=IMG_Load("run_right.png");
	detective.perso[1]=IMG_Load("run_left.png");

	positionecran.x=0;
	positionecran.y=0;
	pbackground.x=0;
	pbackground.y=0;
	scroll.posback.x=634;
	scroll.posback.y=1232;
	scroll.posback.w=1366;
	scroll.posback.h=768;

	detective.frameTimer=0;

	mbackground=Mix_LoadMUS("MBackground.mp3");
	bouton_sclic=Mix_LoadWAV("Menu - Passage souris.wav");
	bouton_clic=Mix_LoadWAV("Menu - entrée.wav");
	Mix_FadeInMusic(mbackground, -1, 120000);

	/***********************************/

	if( (detective.perso[0]==NULL) || (detective.perso[1]==NULL)  || (image==NULL) || (image2==NULL) ){
		fprintf(stderr,"Unable to load png: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if( (bouton_sclic== NULL ) || (bouton_clic== NULL ) || (mbackground==NULL) ){
		fprintf(stderr,"%s",Mix_GetError());
	        exit(EXIT_FAILURE);    
    }

	if(!screen){
		fprintf(stderr,"Unable to set 1366x768 video: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/***********************************/

	SDL_FillRect(screen,0,SDL_MapRGB(screen->format,255,255,0));
	SDL_BlitSurface(Backgrounds[1].buttonimage,NULL,screen,&pbackground);
	SDL_Flip(screen);

	/***********************************/
	
	while(continuer){

		if(Game==0)
		{
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
						if(!Game)
						{
							if( (S_etat==2) && Vetat<11 ){
								Mix_PlayChannel(-1, bouton_sclic, 0);
						 		Vetat++;
								Mix_VolumeMusic(volume+=11);
								Mix_VolumeChunk(bouton_sclic,volume);
								Mix_VolumeChunk(bouton_clic,volume);
							}
						}
					break;

					case SDLK_LEFT:
						if(!Game)
						{
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
						}
					break;

					case SDLK_BACKSPACE:

						if(!Game){

							if(S_etat==1)
								S_etat--;
							else if(S_etat==2)
								S_etat--;
							else if(S_etat==3)
								S_etat=0;
							else if(S_etat==4)
								S_etat=1;
						}
						break;

					case SDLK_DOWN:

						if(!Game){
							Mix_PlayChannel(-1, bouton_sclic, 0);

							/*******************************/
							
							if( (S_etat==0) && (etat==1) ){
								event.motion.x=Buttons[0].buttonpos.x;
								event.motion.y=Buttons[0].buttonpos.y;
								etat=2;
							}

							else if( (S_etat==0) && (etat==2) ){
								event.motion.x=Buttons[1].buttonpos.x;
								event.motion.y=Buttons[1].buttonpos.y;
								etat=3;
							}

							else if( (S_etat==0) && (etat==3) ){
								event.motion.x=Buttons[2].buttonpos.x;
								event.motion.y=Buttons[2].buttonpos.y;
								etat=4;
							}

							else if( (S_etat==0) && (etat==4) ){
								event.motion.x=Buttons[0].buttonpos.x;
								event.motion.y=Buttons[0].buttonpos.y;
								etat=2;
							}

							/*******************************/

							else if( (S_etat==1) && (etat==8) ){
								event.motion.x=Buttons[16].buttonpos.x;
								event.motion.y=Buttons[16].buttonpos.y;
								etat=5;
							}

							else if( (S_etat==1) && (etat==5) ){
								event.motion.x=Buttons[19].buttonpos.x;
								event.motion.y=Buttons[19].buttonpos.y;
								etat=6;
							}

							else if( (S_etat==1) && (etat==6) ){
								event.motion.x=Buttons[17].buttonpos.x;
								event.motion.y=Buttons[17].buttonpos.y;
								etat=9;
							}

							else if( (S_etat==1) && (etat==9) ){
								event.motion.x=Buttons[18].buttonpos.x;
								event.motion.y=Buttons[18].buttonpos.y;
								etat=7;
							}

							else if( (S_etat==1) && (etat==7) ){
								event.motion.x=Buttons[16].buttonpos.x;
								event.motion.y=Buttons[16].buttonpos.y;
								etat=5;
							}

							/*******************************/

							else if( (S_etat==3) && (etat==10) ){
								event.motion.x=Buttons[14].buttonpos.x;
								event.motion.y=Buttons[14].buttonpos.y;
								etat=11;
							}

							else if( (S_etat==3) && (etat==11) ){
								event.motion.x=Buttons[15].buttonpos.x;
								event.motion.y=Buttons[15].buttonpos.y;
								etat=12;
							}

							else if( (S_etat==3) && (etat==12) ){
								event.motion.x=Buttons[13].buttonpos.x;
								event.motion.y=Buttons[13].buttonpos.y;
								etat=13;
							}
							
							else if( (S_etat==3) && (etat==13) ){
								event.motion.x=Buttons[14].buttonpos.x;
								event.motion.y=Buttons[14].buttonpos.y;
								etat=11;
							}

							/*******************************/

							else if( (S_etat==4) && (etat==14) ){
								event.motion.x=Buttons[10].buttonpos.x;
								event.motion.y=Buttons[10].buttonpos.y;
								etat=15;
							}

							else if( (S_etat==4) && (etat==18) ){
								event.motion.x=Buttons[10].buttonpos.x;
								event.motion.y=Buttons[10].buttonpos.y;
								etat=15;
							}

							else if( (S_etat==4) && (etat==15) ){
								event.motion.x=Buttons[11].buttonpos.x;
								event.motion.y=Buttons[11].buttonpos.y;
								etat=16;
							}

							else if( (S_etat==4) && (etat==16) ){
								event.motion.x=Buttons[12].buttonpos.x;
								event.motion.y=Buttons[12].buttonpos.y;
								etat=17;
							}

							else if( (S_etat==4) && (etat==17) ){
								event.motion.x=Buttons[18].buttonpos.x;
								event.motion.y=Buttons[18].buttonpos.y;
								etat=18;
							}

						}
						
					break;

					case SDLK_UP:
						if(!Game){
							Mix_PlayChannel(-1, bouton_sclic, 0);

							/***************************/

							if( (S_etat==0) && (etat==1) ){
								event.motion.x=Buttons[2].buttonpos.x;
								event.motion.y=Buttons[2].buttonpos.y;
								etat=4;
							}

							else if( (S_etat==0) && (etat==2) ){
								event.motion.x=Buttons[2].buttonpos.x;
								event.motion.y=Buttons[2].buttonpos.y;
								etat=4;
							}

							else if( (S_etat==0) && (etat==3) ){
								if(etat!=2){
								}
								event.motion.x=Buttons[0].buttonpos.x;
								event.motion.y=Buttons[0].buttonpos.y;
								etat=2;
							}

							else if( (S_etat==0) && (etat==4) ){
								event.motion.x=Buttons[1].buttonpos.x;
								event.motion.y=Buttons[1].buttonpos.y;
								etat=3;
							}

							/***************************/

							
							else if( (S_etat==1) && (etat==8) ){
								event.motion.x=Buttons[18].buttonpos.x;
								event.motion.y=Buttons[18].buttonpos.y;
								etat=7;
							}

							else if( (S_etat==1) && (etat==5) ){
								event.motion.x=Buttons[18].buttonpos.x;
								event.motion.y=Buttons[18].buttonpos.y;
								etat=7;
							}

							else if( (S_etat==1) && (etat==6) ){
								etat=5;
								event.motion.x=Buttons[16].buttonpos.x;
								event.motion.y=Buttons[16].buttonpos.y;
							}

							else if( (S_etat==1) && (etat==9) ){
								event.motion.x=Buttons[19].buttonpos.x;
								event.motion.y=Buttons[19].buttonpos.y;
								etat=6;
							}
							else if( (S_etat==1) && (etat==7) ){
								event.motion.x=Buttons[17].buttonpos.x;
								event.motion.y=Buttons[17].buttonpos.y;
								etat=9;
							}

							/***************************/


							else if( (S_etat==3) && (etat==10) ){
								event.motion.x=Buttons[13].buttonpos.x;
								event.motion.y=Buttons[13].buttonpos.y;
								etat=13;
							}

							else if( (S_etat==3) && (etat==11) ){
								event.motion.x=Buttons[13].buttonpos.x;
								event.motion.y=Buttons[13].buttonpos.y;
								etat=13;
							}

							else if( (S_etat==3) && (etat==12) ){
								event.motion.x=Buttons[14].buttonpos.x;
								event.motion.y=Buttons[14].buttonpos.y;
								etat=11;
							}

							else if( (S_etat==3) && (etat==13) ){
								event.motion.x=Buttons[15].buttonpos.x;
								event.motion.y=Buttons[15].buttonpos.y;
								etat=12;
							}

							/***************************/


							else if( (S_etat==4) && (etat==14) ){
								event.motion.x=Buttons[18].buttonpos.x;
								event.motion.y=Buttons[18].buttonpos.y;
								etat=18;
							}	

							else if( (S_etat==4) && (etat==15) ){
								event.motion.x=Buttons[18].buttonpos.x;
								event.motion.y=Buttons[18].buttonpos.y;
								etat=18;
							}

							else if( (S_etat==4) && (etat==18) ){
								event.motion.x=Buttons[12].buttonpos.x;
								event.motion.y=Buttons[12].buttonpos.y;
								etat=17;
							}

							else if( (S_etat==4) && (etat==17) ){
								event.motion.x=Buttons[11].buttonpos.x;
								event.motion.y=Buttons[11].buttonpos.y;
								etat=16;
							}

							else if( (S_etat==4) && (etat==16) ){
								event.motion.x=Buttons[10].buttonpos.x;
								event.motion.y=Buttons[10].buttonpos.y;
								etat=15;
							}
						}
					break;

					case SDLK_RETURN:
								Mix_PlayChannel(-1, bouton_clic, 0);
						if(!Game)
						{	
							if( (etat==3) && (S_etat==0) || ( (etat==18) && (S_etat==4) ) ){
								S_etat=1;
								etat=8;	
							}
							else if( ( (etat==7) && (S_etat==1) ) || ( (etat==13) && (S_etat==3) ) ){
								S_etat=0;
								etat=1;	
							}
							else if( (etat==4) && (S_etat==0)){
								continuer=0;
							}
							else if( (etat==5) && (S_etat==1) ){
								S_etat=2;
							}
							else if( (etat==2) && (S_etat==0) ){
								S_etat=3;
								etat=10;
							}
							else if( (etat==9) && (S_etat==1) ){
								S_etat=4;
								etat=14;
							}
							else if( (etat==15) && (S_etat==4) ){
								f=fopen("difficulty.txt","w");
								if(f!=NULL){
									fprintf(f,"easy");
								}
								else
									printf("\nLe fichier ne s'est pas ouvert correctement.\n");
								fclose(f);
							}
							else if( (etat==16) && (S_etat==4) ){
								f=fopen("difficulty.txt","w");
								if(f!=NULL){
								fprintf(f,"medium");
								}
								else
									printf("\nLe fichier ne s'est pas ouvert correctement.\n");
								fclose(f);
							}
							else if( (etat==15) && (S_etat==4) ){
								f=fopen("difficulty.txt","w");
								if(f!=NULL){
									fprintf(f,"hard");
								}
								else
									printf("\nLe fichier ne s'est pas ouvert correctement.\n");
								fclose(f);
							}
							else if( S_etat==3 && etat==11 ){
								//Première ligne pour sauvegarde.txt: 1200 500 62 178 0 0 4 180
								initPerso(&detective,"sauvegarde.txt",0);
								Game=1;
								SDL_BlitSurface(image2,&scroll.posback,screen,&positionecran);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								detective.frameTimer=0;
								detective.frameNumber=0;
								affPerso(&detective,screen,0);
								SDL_Flip(screen);
								SDL_Delay(500);
							}
							else if( S_etat==3 && etat==12 ){
								//Première ligne pour sauvegarde.txt: 1200 500 62 178 0 0 4 180
								initPerso(&detective,"sauvegarde.txt",save);
								Game=1;
								SDL_BlitSurface(image2,&scroll.posback,screen,&positionecran);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								detective.frameTimer=0;
								detective.frameNumber=0;
								affPerso(&detective,screen,0);
								SDL_Flip(screen);
								SDL_Delay(500);
							}
						}

					break;
				}

			case SDL_MOUSEMOTION:
						if(!Game){
							if( (event.motion.x>=Buttons[0].buttonpos.x) && (event.motion.x<=(Buttons[0].buttonpos.x+478.49) ) && (event.motion.y>=Buttons[0].buttonpos.y) && (event.motion.y<=(Buttons[0].buttonpos.y+114.76) ) && (S_etat==0) ){
								if(etat!=2){
								Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=2;
							}

							else if( (event.motion.x>=Buttons[2].buttonpos.x) && (event.motion.x<=(Buttons[2].buttonpos.x+478.49) ) && (event.motion.y>=Buttons[2].buttonpos.y) && (event.motion.y<=(Buttons[2].buttonpos.y+114.76) ) && (S_etat==0) ){
								if(etat!=4){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=4;
							}

							else if( (event.motion.x>=Buttons[1].buttonpos.x) && (event.motion.x<=(Buttons[1].buttonpos.x+478.49) ) && (event.motion.y>=Buttons[1].buttonpos.y) && (event.motion.y<=(Buttons[1].buttonpos.y+114.76) ) && (S_etat==0) ){
								if(etat!=3){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=3;
							}
							else if( (event.motion.x>=Buttons[17].buttonpos.x) && (event.motion.x<=(Buttons[17].buttonpos.x+Buttons[17].buttonpos.w) ) && (event.motion.y>=Buttons[17].buttonpos.y) && (event.motion.y<=(Buttons[17].buttonpos.y+Buttons[17].buttonpos.h) ) && (S_etat==1) ){
								if(etat!=9){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=9;	
							}

							else if(!( (event.motion.x>=Buttons[2].buttonpos.x) && (event.motion.x<=(Buttons[2].buttonpos.x+478.49) ) && (event.motion.y>=Buttons[2].buttonpos.y) && (event.motion.y<=(Buttons[2].buttonpos.y+114.76) ) ) && !( (event.motion.x>=Buttons[2].buttonpos.x) && (event.motion.x<=(Buttons[2].buttonpos.x+478.49) ) && (event.motion.y>=Buttons[2].buttonpos.y) && (event.motion.y<=(Buttons[2].buttonpos.y+114.76) ) ) && !( (event.motion.x>=Buttons[0].buttonpos.x) && (event.motion.x<=(Buttons[0].buttonpos.x+478.49) ) && (event.motion.y>=Buttons[0].buttonpos.y) && (event.motion.y<=(Buttons[0].buttonpos.y+114.76) ) ) && (S_etat==0) )
								etat=1;
				
							else if( (event.motion.x>=Buttons[16].buttonpos.x) && (event.motion.x<=(Buttons[16].buttonpos.x+283.5) ) && (event.motion.y>=Buttons[16].buttonpos.y) && (event.motion.y<=(Buttons[16].buttonpos.y+62) ) && (S_etat==1) ){
								if(etat!=5){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=5;
							}		

							else if( (event.motion.x>=Buttons[19].buttonpos.x) && (event.motion.x<=(Buttons[19].buttonpos.x+Buttons[19].buttonpos.w) ) && (event.motion.y>=Buttons[19].buttonpos.y) && (event.motion.y<=(Buttons[19].buttonpos.y+Buttons[19].buttonpos.h) ) && (S_etat==1) ){
								if(etat!=6){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=6;
							}		

							else if( (event.motion.x>=Buttons[18].buttonpos.x) && (event.motion.x<=(Buttons[18].buttonpos.x+Buttons[18].buttonpos.w) ) && (event.motion.y>=Buttons[18].buttonpos.y) && (event.motion.y<=(Buttons[18].buttonpos.y+Buttons[19].buttonpos.h) ) && (S_etat==1) ){
								if(etat!=7){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=7;
							}	

							else if( !( (event.motion.x>=Buttons[16].buttonpos.x) && (event.motion.x<=(Buttons[16].buttonpos.x+283.5) ) && (event.motion.y>=Buttons[16].buttonpos.y) && (event.motion.y<=(Buttons[16].buttonpos.y+62) ) ) && !( (event.motion.x>=Buttons[17].buttonpos.x) && (event.motion.x<=(Buttons[17].buttonpos.x+Buttons[17].buttonpos.w) ) && (event.motion.y>=Buttons[17].buttonpos.y) && (event.motion.y<=(Buttons[17].buttonpos.y+Buttons[17].buttonpos.h) )) && !( (event.motion.x>=Buttons[18].buttonpos.x) && (event.motion.x<=(Buttons[18].buttonpos.x+Buttons[18].buttonpos.w) ) && (event.motion.y>=Buttons[18].buttonpos.y) && (event.motion.y<=(Buttons[18].buttonpos.y+Buttons[19].buttonpos.h) ) ) && !( (event.motion.x>=Buttons[19].buttonpos.x) && (event.motion.x<=(Buttons[19].buttonpos.x+Buttons[19].buttonpos.w) ) && (event.motion.y>=Buttons[19].buttonpos.y) && (event.motion.y<=(Buttons[19].buttonpos.y+Buttons[19].buttonpos.h) ) ) && (S_etat==1) ){
								etat=8;
							}
							else if( (event.motion.x>=Buttons[14].buttonpos.x) && (event.motion.x<=(Buttons[14].buttonpos.x+Buttons[14].buttonpos.w) ) && (event.motion.y>=Buttons[14].buttonpos.y) && (event.motion.y<=(Buttons[14].buttonpos.y+Buttons[14].buttonpos.h) ) && (S_etat==3) ){
								if(etat!=11){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=11;
							}
							else if( (event.motion.x>=Buttons[15].buttonpos.x) && (event.motion.x<=(Buttons[15].buttonpos.x+Buttons[15].buttonpos.w) ) && (event.motion.y>=Buttons[15].buttonpos.y) && (event.motion.y<=(Buttons[15].buttonpos.y+Buttons[15].buttonpos.h) ) && (S_etat==3) ){
								if(etat!=12){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=12;
							}
							else if( (event.motion.x>=Buttons[13].buttonpos.x) && (event.motion.x<=(Buttons[13].buttonpos.x+Buttons[13].buttonpos.w) ) && (event.motion.y>=Buttons[13].buttonpos.y) && (event.motion.y<=(Buttons[13].buttonpos.y+Buttons[13].buttonpos.h) ) && (S_etat==3) ){
								if(etat!=13){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=13;
							}
							else if( !((event.motion.x>=Buttons[14].buttonpos.x) && (event.motion.x<=(Buttons[14].buttonpos.x+Buttons[14].buttonpos.w) ) && (event.motion.y>=Buttons[14].buttonpos.y) && (event.motion.y<=(Buttons[14].buttonpos.y+Buttons[14].buttonpos.h) )) && !( (event.motion.x>=Buttons[15].buttonpos.x) && (event.motion.x<=(Buttons[15].buttonpos.x+Buttons[15].buttonpos.w) ) && (event.motion.y>=Buttons[15].buttonpos.y) && (event.motion.y<=(Buttons[15].buttonpos.y+Buttons[15].buttonpos.h) )) && !( (event.motion.x>=Buttons[13].buttonpos.x) && (event.motion.x<=(Buttons[13].buttonpos.x+Buttons[13].buttonpos.w) ) && (event.motion.y>=Buttons[13].buttonpos.y) && (event.motion.y<=(Buttons[13].buttonpos.y+Buttons[13].buttonpos.h) )) && (S_etat==3) ){
								etat=10;
							}

							else if( (event.motion.x>=Buttons[10].buttonpos.x) && (event.motion.x<=(Buttons[10].buttonpos.x+Buttons[10].buttonpos.w) ) && (event.motion.y>=Buttons[10].buttonpos.y) && (event.motion.y<=(Buttons[10].buttonpos.y+Buttons[10].buttonpos.h) ) && (S_etat==4) ){
								if(etat!=15){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=15;
							}

							else if( (event.motion.x>=Buttons[11].buttonpos.x) && (event.motion.x<=(Buttons[11].buttonpos.x+Buttons[11].buttonpos.w) ) && (event.motion.y>=Buttons[11].buttonpos.y) && (event.motion.y<=(Buttons[11].buttonpos.y+Buttons[11].buttonpos.h) ) && (S_etat==4) ){
								if(etat!=16){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=16;
							}
							else if( (event.motion.x>=Buttons[12].buttonpos.x) && (event.motion.x<=(Buttons[12].buttonpos.x+Buttons[12].buttonpos.w) ) && (event.motion.y>=Buttons[12].buttonpos.y) && (event.motion.y<=(Buttons[12].buttonpos.y+Buttons[12].buttonpos.h) ) && (S_etat==4) ){
								if(etat!=17){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=17;
							}
							else if( (event.motion.x>=Buttons[18].buttonpos.x) && (event.motion.x<=(Buttons[18].buttonpos.x+Buttons[18].buttonpos.w) ) && (event.motion.y>=Buttons[18].buttonpos.y) && (event.motion.y<=(Buttons[18].buttonpos.y+Buttons[18].buttonpos.h) ) && (S_etat==4) ){
								if(etat!=18){
									Mix_PlayChannel(-1, bouton_sclic, 0);
								}
								etat=18;
							}
							else if( !((event.motion.x>=Buttons[10].buttonpos.x) && (event.motion.x<=(Buttons[10].buttonpos.x+Buttons[10].buttonpos.w) ) && (event.motion.y>=Buttons[10].buttonpos.y) && (event.motion.y<=(Buttons[10].buttonpos.y+Buttons[10].buttonpos.h) )) && !( (event.motion.x>=Buttons[11].buttonpos.x) && (event.motion.x<=(Buttons[11].buttonpos.x+Buttons[11].buttonpos.w) ) && (event.motion.y>=Buttons[11].buttonpos.y) && (event.motion.y<=(Buttons[11].buttonpos.y+Buttons[11].buttonpos.h) )) && !( (event.motion.x>=Buttons[18].buttonpos.x) && (event.motion.x<=(Buttons[18].buttonpos.x+Buttons[18].buttonpos.w) ) && (event.motion.y>=Buttons[18].buttonpos.y) && (event.motion.y<=(Buttons[18].buttonpos.y+Buttons[18].buttonpos.h) )) && !( (event.motion.x>=Buttons[18].buttonpos.x) && (event.motion.x<=(Buttons[18].buttonpos.x+Buttons[18].buttonpos.w) ) && (event.motion.y>=Buttons[18].buttonpos.y) && (event.motion.y<=(Buttons[18].buttonpos.y+Buttons[18].buttonpos.h) ) ) && (S_etat==3) ){
								etat=14;
							}
						}
				break;
				




			case SDL_MOUSEBUTTONUP:
						if(!Game){
							Mix_PlayChannel(-1, bouton_clic, 0);
							if( (event.button.x>=Buttons[1].buttonpos.x) && (event.button.x<=(Buttons[1].buttonpos.x+478.49) ) && (event.button.y>=Buttons[1].buttonpos.y) && (event.button.y<=(Buttons[1].buttonpos.y+114.76) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==0)){
								S_etat=1;
								etat=8;	
							}

							else if( (event.button.x>=Buttons[18].buttonpos.x) && (event.button.x<=(Buttons[18].buttonpos.x+Buttons[18].buttonpos.w) ) && (event.button.y>=Buttons[18].buttonpos.y) && (event.button.y<=(Buttons[18].buttonpos.y+Buttons[18].buttonpos.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==1)){
								S_etat=0;
								etat=1;	
							}

							else if( (event.button.x>=Buttons[2].buttonpos.x) && (event.button.x<=(Buttons[2].buttonpos.x+Buttons[2].buttonpos.w) ) && (event.button.y>=Buttons[2].buttonpos.y) && (event.button.y<=(Buttons[2].buttonpos.y+Buttons[2].buttonpos.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==0)){
								continuer=0;	
							}

							else if( (event.button.x>=Buttons[16].buttonpos.x) && (event.button.x<=(Buttons[16].buttonpos.x+283.5) ) && (event.button.y>=Buttons[16].buttonpos.y) && (event.button.y<=(Buttons[16].buttonpos.y+62) ) && (S_etat==1) && (event.button.button=SDL_BUTTON_LEFT)){
								S_etat=2;
							}

							else if( (event.button.x>=Buttons[0].buttonpos.x) && (event.button.x<=(Buttons[0].buttonpos.x+Buttons[0].buttonpos.w) ) && (event.button.y>=Buttons[0].buttonpos.y) && (event.button.y<=(Buttons[0].buttonpos.y+62) ) && (S_etat==0) && (event.button.button=SDL_BUTTON_LEFT)){
								S_etat=3;
							}

							else if( (event.button.x>=Buttons[17].buttonpos.x) && (event.button.x<=(Buttons[17].buttonpos.x+Buttons[17].buttonpos.y) ) && (event.button.y>=Buttons[17].buttonpos.y) && (event.button.y<=(Buttons[17].buttonpos.y+62) ) && (S_etat==1) && (event.button.button=SDL_BUTTON_LEFT)){
								S_etat=4;
							}

							else if( (event.button.x>=Buttons[13].buttonpos.x) && (event.button.x<=(Buttons[13].buttonpos.x+Buttons[13].buttonpos.w) ) && (event.button.y>=Buttons[13].buttonpos.y) && (event.button.y<=(Buttons[13].buttonpos.y+Buttons[13].buttonpos.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==3)){
								S_etat=0;
								etat=1;			
							}

							else if( (event.button.x>=Buttons[18].buttonpos.x) && (event.button.x<=(Buttons[18].buttonpos.x+Buttons[18].buttonpos.w) ) && (event.button.y>=Buttons[18].buttonpos.y) && (event.button.y<=(Buttons[18].buttonpos.y+Buttons[18].buttonpos.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==4)){
								S_etat=1;
								etat=8;	
							}
///
							else if( (event.button.x>=Buttons[10].buttonpos.x) && (event.button.x<=(Buttons[10].buttonpos.x+Buttons[10].buttonpos.w) ) && (event.button.y>=Buttons[10].buttonpos.y) && (event.button.y<=(Buttons[10].buttonpos.y+Buttons[10].buttonpos.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==4)){
								f=fopen("difficulty.txt","w");
								if(f!=NULL){
									fprintf(f,"easy");
								}
								else
									printf("\nLe fichier ne s'est pas ouvert correctement.\n");
								fclose(f);
							}
							else if( (event.button.x>=Buttons[11].buttonpos.x) && (event.button.x<=(Buttons[11].buttonpos.x+Buttons[11].buttonpos.w) ) && (event.button.y>=Buttons[11].buttonpos.y) && (event.button.y<=(Buttons[11].buttonpos.y+Buttons[11].buttonpos.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==4)){
								f=fopen("difficulty.txt","w");
								if(f!=NULL){
									fprintf(f,"medium");
								}
								else
									printf("\nLe fichier ne s'est pas ouvert correctement.\n");
								fclose(f);
							}
							else if( (event.button.x>=Buttons[12].buttonpos.x) && (event.button.x<=(Buttons[12].buttonpos.x+Buttons[12].buttonpos.w) ) && (event.button.y>=Buttons[12].buttonpos.y) && (event.button.y<=(Buttons[12].buttonpos.y+Buttons[12].buttonpos.h) ) && (event.button.button=SDL_BUTTON_LEFT) && (S_etat==4)){
								f=fopen("difficulty.txt","w");
								if(f!=NULL){
									fprintf(f,"hard");
								}
								else
									printf("\nLe fichier ne s'est pas ouvert correctement.\n");
								fclose(f);
							}
						}
				break;
		}

		menu(etat,Vetat,S_etat,screen,pbackground);

		}

		else if(Game==INGAME){
			SDL_PollEvent(&ing);
			SDL_BlitSurface(image2,&scroll.posback,screen,&positionecran);
		switch(ing.type){
			case SDL_QUIT:
				continuer=0;
				break;
			case SDL_KEYDOWN:
				switch(ing.key.keysym.sym){
					case SDLK_BACKSPACE:
						continuer=0;
						break;
					case SDLK_ESCAPE:
						Game=2;
						etat=0;
						S_etat=0;
						SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
						SDL_BlitSurface(Backgrounds[6].buttonimage,NULL,screen,&pbackground);
						SDL_Flip(screen);
						SDL_Delay(100);
						break;
					case SDLK_RETURN:
						stairs();
						break;
					case SDLK_UP:
						if(Gameplay==FLECHES)
						{
							if(collision_Parfaite(image2,detective.C[0].X,detective.C[0].Y))
							{
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
							}
							else{
								scrolling(&scroll,&detective.positionInit,4);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
							}
								SDL_Flip(screen);
						}

						break;

					case SDLK_DOWN:
						if(Gameplay==FLECHES)
						{
							if(collision_Parfaite(image2,detective.C[1].X,detective.C[1].Y))
							{
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}
							else{
								scrolling(&scroll,&detective.positionInit,3);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}
						}

						break;

					case SDLK_RIGHT:

						if(Gameplay==FLECHES)
						{
							if(collision_Parfaite(image2,detective.C[3].X,detective.C[3].Y))
							{
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}
							else{
								//detective.positionInit.x+=3;
								scrolling(&scroll,&detective.positionInit,1);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}

						}
						break;

					case SDLK_LEFT:
						if(Gameplay==FLECHES)
						{
							if(collision_Parfaite(image2,detective.C[2].X,detective.C[2].Y))
							{
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(1);
								SDL_Flip(screen);
							}
							else
							{
								//detective.positionInit.x-=3;
								scrolling(&scroll,&detective.positionInit,2);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(1);
								SDL_Flip(screen);
							}
						}

						break;

					case SDLK_d:
						if(Gameplay==CLAVIER)
						{
							if(collision_Parfaite(image2,detective.C[3].X,detective.C[3].Y))
							{
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}
							else{
								scrolling(&scroll,&detective.positionInit,1);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}

						}
						break;
					case SDLK_q:
						if(Gameplay==CLAVIER)
						{
							if(collision_Parfaite(image2,detective.C[2].X,detective.C[2].Y))
							{
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(1);
								SDL_Flip(screen);
							}
							else
							{
								scrolling(&scroll,&detective.positionInit,2);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(1);
								SDL_Flip(screen);
							}
						}
						break;
					case SDLK_z:
						if(Gameplay==CLAVIER)
						{
							if(collision_Parfaite(image2,detective.C[0].X,detective.C[0].Y))
							{
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}
							else{
								scrolling(&scroll,&detective.positionInit,4);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}
						}
						break;
					case SDLK_s:

						if(Gameplay==CLAVIER)
						{
							if(collision_Parfaite(image2,detective.C[1].X,detective.C[1].Y))
							{
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}
							else{
								scrolling(&scroll,&detective.positionInit,3);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								animerHero(0);
								SDL_Flip(screen);
							}
						}
						break;


				}
				break;

			}
		}
		else if(Game==SETTINGS){
			SDL_WaitEvent(&event2);
			switch(event2.type){
				case SDL_KEYDOWN:
					switch(event2.key.keysym.sym){
						case SDLK_ESCAPE:
							Game=1;
							SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
							SDL_BlitSurface(image2,&scroll.posback,screen,&positionecran);
							SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
							detective.frameTimer=0;
							detective.frameNumber=0;
							affPerso(&detective,screen,0);
							SDL_Flip(screen);
							SDL_Delay(100);
							break;
						case SDLK_n:
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
							if(S_etat==0){
								Game=1;
								SDL_BlitSurface(image2,&scroll.posback,screen,&positionecran);
								SDL_BlitSurface(image,&scroll.posback,screen,&positionecran);
								detective.frameTimer=0;
								detective.frameNumber=0;
								affPerso(&detective,screen,0);
								SDL_Flip(screen);
								SDL_Delay(100);
							}
							else if(S_etat==1)
								S_etat--;
							else if(S_etat==2)
								S_etat=0;
						break;

					case SDLK_DOWN:
					if(Game==SETTINGS)
					{

						if (S_etat == 0) 
						{
							Mix_PlayChannel(-1, bouton_sclic, 0);
							etat= etat%4 + 1;
						}

						else if (S_etat == 1)
						{
							Mix_PlayChannel(-1, bouton_sclic, 0);
							etat++;
							if (etat==9)
								etat=6;
						}

					}
						
					break;

					case SDLK_UP:
							Mix_PlayChannel(-1, bouton_sclic, 0);
							
						if (S_etat==0)
						{
							if (etat == 0 || etat == 1)
								etat = 4;
							else etat--;
						}


						else if (S_etat==1)
						{
							if (etat == 5 || etat == 6)
								etat = 8;
							else etat--;
						}
					break;

					case SDLK_RETURN:
							
							Mix_PlayChannel(-1, bouton_clic, 0);

							if( (etat==1) && (S_etat==0) ){
								S_etat=2;
							}
							else if(  (etat==2) && (S_etat==0)  ){
								save=saveGame("sauvegarde.txt",&detective,save);
							}
							else if( (etat==3) && (S_etat==0) ){
								S_etat=1;
								etat=5;
							}
							else if( (etat==4) && (S_etat==0)){
								continuer=0;
							}
							else if( (etat==6) && (S_etat==1) ){
								Gameplay=CLAVIER;
							}
							else if( (etat==7) && (S_etat==1) ){
								Gameplay=FLECHES;
							}
							else if( (etat==8) && (S_etat==1) ){
								S_etat=0;
								etat=0;
							}


					break;
					//
					//
					}
		}
		menu(etat,Vetat,S_etat,screen,pbackground);
		}
	}

	freeButton(Volumes,11);
	freeButton(Backgrounds,11);
	freeButton(Buttons,20);
	SDL_FreeSurface(screen);
	Mix_FreeMusic(mbackground);
	Mix_FreeChunk(bouton_clic);
   	Mix_FreeChunk(bouton_sclic);

	Mix_CloseAudio();
	SDL_Quit();
	return EXIT_SUCCESS;
}
