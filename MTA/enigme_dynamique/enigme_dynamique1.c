#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include "enigme_dynamique.h"
int nbre_aleatoire(int MAX ,int MIN)
{
	int alea;
	srand(time(NULL));
	alea=(rand()%(MAX -MIN +1) +MIN);
	printf("%d",alea);
	return alea;
}
void afficher_enigme(int a, int b,int c ,int d,SDL_Surface* chaine ,SDL_Surface* ecran, TTF_Font* po,SDL_Color couleurblanche)
{
	char sms[50];
	SDL_Rect pos;
	pos.x=0;
	pos.y=0;
	sprintf(sms,"Pourquoi moi");
	//printf("%s",sms);
	chaine=TTF_RenderText_Blended(po,sms,couleurblanche);
	SDL_BlitSurface(chaine,NULL,ecran,&pos);
        SDL_Flip(ecran);
}
int equation_enigme(SDL_Surface *ecran)
{
	int a,b,c,d,k=0;
	SDL_Surface* chaine =NULL;
	TTF_Init();
	SDL_Color couleurblanche={255,255,255};
	TTF_Font *police=NULL;
	police=TTF_OpenFont("fente.tff",20);
	
	a=nbre_aleatoire(100,-100);
	b=nbre_aleatoire(60,-40);
	c=nbre_aleatoire(24,-90);
	d=nbre_aleatoire(100,-100);
	afficher_enigme(a,b,c,d,chaine,ecran,police,couleurblanche);
	SDL_Delay(2000);
	
	TTF_CloseFont(police);
	SDL_FreeSurface(chaine);
	SDL_FreeSurface(ecran);
	return k;
}
