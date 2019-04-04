#ifndef BACKGROUND_H_
#define BACKGROUND_H_

typedef struct
{
	SDL_Surface * image;
	SDL_Rect positionecran;

}background;


background initialiser ();
void afficher (background b , SDL_Surface *screen);


#endif /* BACKGROUND_H_ */
