/**
* @file collision.c
* @date Apr 28, 2019
* @brief the collision functions
* @version 0.1
* @author Bilel Taktak
*/
#include "collision.h"

/**
* @brief get the pixels' color
* @param pSurface the surface in which we'll compare the pixels
* @param x the horizontal axis
* @param y the vertical axis
* @return Nothing
*/
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

/**
* @brief the perfect pixel function
* @param calque the surface in which we'll compare the pixels 
* @param coord_x the horizontal axis
* @param coord_y the vertical axis
* @return Nothing
*/
int collision_Parfaite(SDL_Surface *calque, int coord_x, int coord_y){

	SDL_Color color;

	int c = 0;

	color=GetPixel(calque,coord_x,coord_y);
	
	if ((color.r == 0) && (color.b == 0) && (color.g == 0)){
		c = 1;
	}

	return c;
}
