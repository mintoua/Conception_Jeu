#ifndef BK_H_
#define BK_H_
#include <stdio.h>
 #include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
 #include <SDL/SDL_mixer.h>
#include "persop.h"

typedef struct
{
	SDL_Surface * image;
	SDL_Rect position;
	Mix_Music * music;
	TTF_Font *texte;
}background;

typedef struct 
{
	SDL_Surface * img_but;
	SDL_Rect pos_but;
	Mix_Music * son_but;
}button;

<<<<<<< HEAD

typedef struct BACKGROUND
{
SDL_Surface*  bg;
SDL_Rect position;
SDL_Rect scroll;
int stage;
int position_actuel;
}BACKGROUND;

void init_bk(BACKGROUND* b);
void afficher_bk(BACKGROUND bk,SDL_Surface *fenetre);

void scrollingbg(int sens,BACKGROUND *bg);

=======
void init_bck(background tab[]);
>>>>>>> 2d25391ef00ff2ea0f6c3b41364ee2c0ebccc310


#endif /* BACKGROUND_H_ */
