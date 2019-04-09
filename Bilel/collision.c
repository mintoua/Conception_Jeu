#include "entete.h"

SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
	SDL_Color color;
	Uint32 col=0;

	//Determine position

	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);

	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);

	//convertir color
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);

	return (color);
}

int collision_Parfaite(SDL_Surface *calque, int coord_x, int coord_y){

	SDL_Color color;

	int c = 0;

	color=GetPixel(calque,coord_x,coord_y);
	
	if ((color.r == 0) && (color.b == 0) && (color.g == 0)){
		c = 1;
	}

	return c;
}
