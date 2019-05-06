#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "defs.h"
#include "jeu.h"
#include "text.h"

#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

int enigme(SDL_Surface *screen, TTF_Font *police, Text *T,int *vie,int *score,int *tmp);


#endif // ENIGME_H_INCLUDED
