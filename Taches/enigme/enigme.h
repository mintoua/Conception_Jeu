/*Mintoua Toupkandi*/

#ifndef ENIGME_H_
#define ENIGME_H_

typedef struct
{
	SDL_Rect posEnigme;
	SDL_Surface *Senigme;
	int reponse;
}Enigme;

void init_enigme(); 
int affEnigme(Enigme E[],SDL_Surface *ecran);
void freeEnigme(Enigme E[],int nbEnigme);
int resolutio_enigme(Enigme E[], int alea, SDL_Event event)
void generation_aleatoire(); 



#endif /* ENIGME_H_ */


