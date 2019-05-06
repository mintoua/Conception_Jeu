#ifndef COLLISION_H_
#define COLLISION_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>
#include "hero.h"
#include "defs.h"

extern Hero detective;
extern SDL_Surface* screen;


int collision_Parfaite(SDL_Surface *calque, int x, int y);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);


#endif /* COLLISION_H_ */