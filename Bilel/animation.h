#ifndef ANIMATION_H_
#define ANIMATION_H_

#include"entete.h"

extern Hero detective;
extern SDL_Surface *screen;

   /* Prototype des fonctions externes que nous allons utiliser ensuite */

extern void affPerso(Hero *A, SDL_Surface *ecran, int direction);
extern void posPerso(Hero *A);

#endif /* ANIMATION_H_ */