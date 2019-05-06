/*Mintoua Toupkandi*/

#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

typedef struct
{
	SDL_Rect posEnigme;
	SDL_Surface *SEnigme;
	int reponse;
}Enigme;

void init_enigme(Enigme E[]); 
int affEnigme(Enigme E[],SDL_Surface *ecran);
void freeEnigme(Enigme E[]);
int resolution_enigme(Enigme E[], int alea, SDL_Event event);
int enigme(Enigme E[],SDL_Surface * ecran);



#endif /* ENIGME_H_ */


