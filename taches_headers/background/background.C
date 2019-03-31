#ifndef BK_H_
#define BK_H_
#include <stdio.h>
 #include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
 #include <SDL/SDL_mixer.h>
#include "persop.h"

typedef struct BACKGROUND
{
SDL_Surface*  bg;

SDL_Rect position;
SDL_Rect scroll;// map t9adem ou twa5zr
int stage;
int position_actuel;
}BACKGROUND;

void init_bk(BACKGROUND* b);
void afficher_bk(BACKGROUND bk,SDL_Surface *fenetre);

void scrollingbg(int sens,BACKGROUND *bg);
#endif

