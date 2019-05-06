#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED 
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"


typedef struct 
{
SDL_Rect posvie ;
int nbvie ;
SDL_Surface *image[5] ;

}vie;

typedef struct 

{

SDL_Surface *image1;
SDL_Rect poscoin ;
int on;

}element;

element coin ;
element coin1 ;
element coin2 ;
element coin3 ;
int score;

SDL_Surface *ecran;
SDL_Rect posperso;
TTF_Font *font;




void initVie(vie *v);
void afficheVie(vie *v , SDL_Surface *ecran);
void initCoin();
void AfficheTexte(char *text,SDL_Rect postxt, TTF_Font *font,SDL_Surface *ecran);
int eatCoin(element coin , element coin1 , element coin2 ,element coin3,SDL_Rect posperso);
void loadFont();
void closeFont();
void gestVieScore(vie *v ,int collision, int enigme);
void DrawScore();
void mort(vie *v,int *continuer);







#endif
