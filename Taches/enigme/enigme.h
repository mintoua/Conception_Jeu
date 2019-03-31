/*La personne dont la tâche est concernée peut modifier comme il veut
les structure et même prototypes*/

#ifndef ENIGME_H_
#define ENIGME_H_
typedef struct
{
	SDL_Event evnt;
	char nom;
	SDL_Rect pos;
}entite_sec;

typedef struct
{
	SDL_Rect posEnigme;
	SDL_Surface *Senigme;
	int reponse;
}Enigme;

void init_enigme(); 
void affEnigme(Enigme E[],int numEnigme,SDL_Surface *ecran);
void freeEnigme(Enigme E[],int nbEnigme);
void resolutio_enigme();
void generation_aleatoire(); 


/*
à vous de faire vos parametre et type de retour
les concernés peuvent modifier
*/
#endif /* ENIGME_H_ */
