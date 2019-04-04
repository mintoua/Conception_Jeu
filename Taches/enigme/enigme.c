/* Mintoua Toupkandi*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "enigme.h" 

void init_enigme(Enigme E[])
{
SDL_Surface * e1 = NULL;
SDL_Surface * e2 = NULL; 
SDL_Surface * e3 = NULL;

e1 = IMG_Load("enigmes/e1.PNG");
e2 = IMG_Load("enigmes/e2.PNG");
e3 = IMG_Load("enigmes/e3.PNG");

E[0].SEnigme = e1; E[0].reponse = 1; 
E[1].SEnigme = e2; E[1].reponse = 2;
E[2].SEnigme = e3; E[2].reponse = 1;

E[0].posEnigme.x = 0; 
E[0].posEnigme.y = 0; 
E[1].posEnigme.x = 0; 
E[1].posEnigme.y = 0; 
E[2].posEnigme.x = 0; 
E[2].posEnigme.y = 0; 
E[3].posEnigme.x = 0; 
E[3].posEnigme.y = 0; 
}

/*affichage enigme 
tableau enigme et surface 
return position de l'enigme dans le tableau
*/

int affEnigme(Enigme E[],SDL_Surface *ecran)
{  
	int alea, MAX = 3, MIN=1;
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

int resolution_enigme(Enigme E[], int alea, SDL_Event event)
{
SDL_Rect positionClic; 
int rep=0;
SDL_WaitEvent (&event);
switch(event.type)
{
case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	{
	case SDLK_a:
	rep = 1;
	break;
	case SDLK_b:
	rep = 2;
	break;
	case SDLK_c:
	rep = 3;
	break;
	}
break;
}
if(rep == E[alea].reponse)// reponse juste return 1
{
	return 1;
}
if(rep != E[alea].reponse)
{
 return 0;
} // reponse fausse return 0;
}

void freeEnigme(Enigme E[])
{int j;
	for(j = 0; j < 3; j++)
	{ SDL_FreeSurface(E[j].SEnigme);}
}
int enigme(Enigme E[],SDL_Surface * ecran)
{
SDL_Event event; int i;

	SDL_Surface *image1;
	SDL_Surface *image2;
	SDL_Rect positionimage;

	image1=IMG_Load("win.png");
	image2=IMG_Load("lost.png");
	
	positionimage.x=0;
	positionimage.y=0;
int aff; int res; 

	aff = affEnigme(E,ecran);
	SDL_WaitEvent(&event);
	res = resolution_enigme(E,aff,event);
if(res == 1)
{
	printf("\nReponse correcte");
		SDL_BlitSurface(image1,NULL,ecran,&positionimage);
		SDL_Flip(ecran);
		SDL_Delay(5000);
return 0;
}
else
{
                printf("\nReponse incorrect\n");
		SDL_BlitSurface(image2,NULL,ecran,&positionimage);
		SDL_Flip(ecran);
		SDL_Delay(5000);
return 1;
}


	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
}

