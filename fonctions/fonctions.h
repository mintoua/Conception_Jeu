#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include "structures.h"

void jouer(SDL_Surface * screen);
void setting(SDL_Surface * screen);
void menu(SDL_Surface * screen);
void setting_ingame(SDl_Surface * screen);
void affPerso(Hero *A, SDL_Surface *ecran);
void freePerso(Hero *A);
void affScore(Hero *A,SDL_Surface *ecran,int Time);

#endif /* FONCTIONS_H_ */
