#ifndef ENIGME_CLAVIER_H_INCLUDED
#define ENIGME_CLAVIER_H_INCLUDED

int afficher_enigme(SDL_Surface *ecran,SDL_Surface *chaine,TTF_Font *police );
int resolution (int alea, SDL_Surface *ecran,SDL_Event event,SDL_Surface *chaine,TTF_Font *police );
int enigme_clavier(SDL_Surface *ecran);

#endif /*ENIGME_CLAVIER_H_*/
