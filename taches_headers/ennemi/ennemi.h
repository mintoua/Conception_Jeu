/*La personne dont la tâche est concernée peut modifier comme il veut
les structure et même prototypes*/

#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
typedef struct
{
	SDL_Event evnt; 
	char nom; 
	SDL_Rect pos;
	SDL_Surface *surface;
}entite_sec;
entite_sec init_ennemi();
void afficher_ennemi(SDL_Surface  *ecran, entite_sec e);


//void deplacement_aleatoire();



#endif /* ENNEMI_H_ */
