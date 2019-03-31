#ifndef BACKGROUND_H_
#define BACKGROUND_H_

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

void init_bck(background tab[]);


#endif /* BACKGROUND_H_ */
