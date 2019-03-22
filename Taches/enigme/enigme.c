/* Mintoua Toupkandi*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "enigme.h" 

void init_enigme(enigme E[])
{
SDL_Surface * e1 = NULL;
SDL_Surface * e2 = NULL; 
SDL_Surface * e3 = NULL;
SDL_Surface * e4 = NULL;
SDL_Surface * e5 = NULL;
SDL_Surface * e6 = NULL;
SDL_Surface * e7 = NULL;
SDL_Surface * e8 = NULL;

e1 = IMG_Load("enigmes/e1");
e2 = IMG_Load("enigmes/e2");
e3 = IMG_Load("enigmes/e3");
e4 = IMG_Load("enigmes/e4");
e5 = IMG_Load("enigmes/e5");
e6 = IMG_Load("enigmes/e6");
e7 = IMG_Load("enigmes/e7");
e8 = IMG_Load("enigmes/e8");

E[0].SEnigme = e1; E[0].reponse = 1; 
E[1].SEnigme = e2; E[1].reponse = 1;
E[2].SEnigme = e3; E[2].reponse = 2;
E[3].SEnigme = e4; E[3].reponse = -1;
E[4].SEnigme = e5; E[4].reponse = -1;
E[5].SEnigme = e6; E[5].reponse = -1;
E[6].SEnigme = e7; E[6].reponse = -1;
E[7].SEnigme = e8; E[7].reponse = -1;

E[0].posEnigme.x = 0; 
E[0].posEnigme.y = 0; 
E[1].posEnigme.x = 0; 
E[1].posEnigme.y = 0; 
E[2].posEnigme.x = 0; 
E[2].posEnigme.y = 0; 
E[3].posEnigme.x = 0; 
E[3].posEnigme.y = 0; 
E[4].posEnigme.x = 0; 
E[4].posEnigme.y = 0; 
E[5].posEnigme.x = 0; 
E[5].posEnigme.y = 0; 
E[6].posEnigme.x = 0; 
E[6].posEnigme.y = 0; 
E[7].posEnigme.x = 0; 
E[7].posEnigme.y = 0; 
}

/*
void init_enigme(enigme tab[],int nbrE,char nomFich)
{
int i;
enigme imgE;
FILE * F = fopen(nomFich,"rb")
for(i=0;i<nbrE;i++)
{
	fread(&imgE,sizeof(enigme),1,F);
	tab[i].Senigme = imgE.image;
	tab[i].reponse = -1;
	tab[i].posEnigme.x=0
	tab[i].posEnigme.y=0
}
}*/

/*affichage enigme 
tableau enigme et surface 
return position de l'enigme dans le tableau
*/

int affEnigme(Enigme E[],SDL_Surface *ecran);
{  int alea, MAX = 7, MIN=0;
srand(time(NULL));
alea=(rand()%(MAX -MIN +1) +MIN);
SDL_BlitSurface(E[alea].SEnigme, NULL,ecran, &E[alea].posEnigme);
SDL_Flip(ecran);

return alea;
}

/*resolution enigme 
tab,posalea, et evenement
return reponse(int)
*/

int resolutio_enigme(Enigme E[], int alea, SDL_Event event)
{
SDL_Rect positionClic; 
int rep=0;
switch(event.type)
{
case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	{
	case SDLK_A:
	rep = 1;
	break;
	case SDLK_B:
	rep = 2;
	break;
	case SDLK_C:
	rep = 3;
	break;
	}
case SDL_MOUSEBUTTONUP:
	if(event.button.button == SDL_BUTTON_LEFT)
	{
          positionClic.x = event.button.x;//recupere les coordonnées du clic avec le curseur
          positionClic.y = event.button.y;

        if(positionClic.x >115 && positionClic.x <498 && positionClic.y >208 && positionClic.y<299)// les position des boutons de l'enigme
         {
		rep = 1;
          }
	else if(positionClic.x >115 && positionClic.x <498 && positionClic.y >311 && positionClic.y<404)
	{
		rep = 2;
	}
	else if(positionClic.x >115 && positionClic.x <498 && positionClic.y >406 && positionClic.y<505)
	{
		rep = 3;
	}
	}
	break;
}
	if(rep == E[alea].reponse)// reponse juste return 1
{
	return 1;
}
else 
{
 return 0;
} // reponse fausse return 0;
}

