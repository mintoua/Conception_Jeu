#include "menu.h"

void menu(int etat,int Vetat, int S_etat,SDL_Surface *screen,SDL_Rect pbackground)
{
	if(Game==0){
			if(etat==1 && S_etat==0){
				SDL_BlitSurface(Backgrounds[1].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}
			else if(etat==2 && S_etat==0){
				SDL_BlitSurface(Buttons[0].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}
			else if(etat==4 && S_etat==0){
				SDL_BlitSurface(Buttons[2].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}
			else if(etat==3 && S_etat==0){
				SDL_BlitSurface(Buttons[1].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}

			else if(etat==5 && S_etat==1){
				SDL_BlitSurface(Buttons[16].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(etat==6 && S_etat==1){
				SDL_BlitSurface(Buttons[19].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(etat==7 && S_etat==1){
				SDL_BlitSurface(Buttons[18].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(etat==8 && S_etat==1){
				SDL_BlitSurface(Backgrounds[0].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(etat==9 && S_etat==1){
				SDL_BlitSurface(Buttons[17].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}
			if(Vetat==1 && S_etat==2){
				SDL_BlitSurface(Volumes[0].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
				SDL_Flip(screen);
			}
			else if(Vetat==2 && S_etat==2){
				SDL_BlitSurface(Volumes[1].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
				SDL_Flip(screen);	
			}
			else if(Vetat==3 && S_etat==2){
				SDL_BlitSurface(Volumes[2].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==4 && S_etat==2){
				SDL_BlitSurface(Volumes[3].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==5 && S_etat==2){
				SDL_BlitSurface(Volumes[4].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==6 && S_etat==2){
				SDL_BlitSurface(Volumes[5].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==7 && S_etat==2){
				SDL_BlitSurface(Volumes[6].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==8 && S_etat==2){
				SDL_BlitSurface(Volumes[7].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==9 && S_etat==2){
				SDL_BlitSurface(Volumes[8].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==10 && S_etat==2){
				SDL_BlitSurface(Volumes[9].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==11 && S_etat==2){
				SDL_BlitSurface(Volumes[10].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}


			else if(S_etat==3 && etat==10){
				SDL_BlitSurface(Backgrounds[3].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(S_etat==3 && etat==11){
				SDL_BlitSurface(Buttons[14].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(S_etat==3 && etat==12){
				SDL_BlitSurface(Buttons[15].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(S_etat==3 && etat==13){
				SDL_BlitSurface(Backgrounds[4].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(S_etat==4 && etat==14){
				SDL_BlitSurface(Backgrounds[2].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(S_etat==4 && etat==15){
				SDL_BlitSurface(Buttons[10].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(S_etat==4 && etat==16){
				SDL_BlitSurface(Buttons[11].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(S_etat==4 && etat==17){
				SDL_BlitSurface(Buttons[12].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(S_etat==4 && etat==18){
				SDL_BlitSurface(Buttons[13].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
		}
		else if(Game==2){
			if(etat==0 && S_etat==0){
				SDL_BlitSurface(Backgrounds[6].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}
			else if(etat==1 && S_etat==0){
				SDL_BlitSurface(Buttons[8].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}
			else if(etat==2 && S_etat==0){
				SDL_BlitSurface(Buttons[7].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}
			else if(etat==3 && S_etat==0){
				SDL_BlitSurface(Buttons[9].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}
			else if(etat==4 && S_etat==0){
				SDL_BlitSurface(Buttons[6].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
			}

			else if(etat==5 && S_etat==1){
				SDL_BlitSurface(Backgrounds[5].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(etat==6 && S_etat==1){
				SDL_BlitSurface(Buttons[3].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(etat==7 && S_etat==1){
				SDL_BlitSurface(Buttons[4].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(etat==8 && S_etat==1){
				SDL_BlitSurface(Buttons[5].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			if(Vetat==1 && S_etat==2){
				SDL_BlitSurface(Volumes[0].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
				SDL_Flip(screen);
			}
			else if(Vetat==2 && S_etat==2){
				SDL_BlitSurface(Volumes[1].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);
				SDL_Flip(screen);	
			}
			else if(Vetat==3 && S_etat==2){
				SDL_BlitSurface(Volumes[2].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==4 && S_etat==2){
				SDL_BlitSurface(Volumes[3].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==5 && S_etat==2){
				SDL_BlitSurface(Volumes[4].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==6 && S_etat==2){
				SDL_BlitSurface(Volumes[5].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==7 && S_etat==2){
				SDL_BlitSurface(Volumes[6].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==8 && S_etat==2){
				SDL_BlitSurface(Volumes[7].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==9 && S_etat==2){
				SDL_BlitSurface(Volumes[8].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==10 && S_etat==2){
				SDL_BlitSurface(Volumes[9].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
			else if(Vetat==11 && S_etat==2){
				SDL_BlitSurface(Volumes[10].buttonimage,NULL,screen,&pbackground);
				SDL_Flip(screen);	
			}
		}

}