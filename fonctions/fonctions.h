#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include "structures.h"

void jouer(SDL_Surface * screen);
void setting(SDL_Surface * screen);
void menu(SDL_Surface * screen);
void setting_ingame(SDl_Surface * screen);
void affPerso(Hero *A, SDL_Surface *ecran);
void affScore(Hero *A,SDL_Surface *ecran,int Time);
void freePerso(Hero *A);
void affEnigme(Enigme E[],int numEnigme,SDL_Surface *ecran);
void freeEnigme(Enigme E[],int nbEnigme);

#endif /* FONCTIONS_H_ */
