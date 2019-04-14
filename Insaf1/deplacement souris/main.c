#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"


int main(int argc,char **agrv[])
{
int continuer =1;
SDL_Event event ;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecran=NULL,*image=NULL,*personnage=NULL;
SDL_Rect positionPersonnage;
SDL_Rect positionImage;
positionPersonnage.x=0;
positionPersonnage.y=250;
positionImage.x=0;
positionImage.y=0;
image=IMG_Load/*SDL_LoadBMP*/("back.png");
personnage=IMG_Load("louxep.png");
 SDL_SetColorKey(personnage,SDL_SRCCOLORKEY,SDL_MapRGB(personnage->format,255,255,255));//fond du personn transpar
ecran=SDL_SetVideoMode(1600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 SDL_WM_SetCaption("TESTE",NULL);//donner le nom de la fenetre

while (continuer)
{
SDL_PollEvent(&event);
 switch (event.type)
{
case SDL_QUIT:
continuer=0;
break ;
case SDL_MOUSEBUTTONUP:
if (event.button.button==SDL_BUTTON_LEFT)
{positionPersonnage.x =event.button.x - 45; //coordonnee du curseur
//if (positionPersonnage.y + 10 < 200)
<<<<<<< HEAD
if (positionPersonnage.y  < 10)
=======
//if (positionPersonnage.y  < 10)
>>>>>>> 4b951d2c9633fb41324dc7b031fc9653670d6d05
positionPersonnage.y=event.button.y;
break ;

}}
 
SDL_BlitSurface(image,NULL,ecran,&positionImage); //mise a jou
SDL_BlitSurface(personnage,NULL,ecran,&positionPersonnage); //mise a jou
SDL_Flip(ecran); //mis a jours
}}
