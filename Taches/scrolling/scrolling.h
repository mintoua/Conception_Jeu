#ifndef SCROLLING_H_INCLUDED
#define SCROLLING_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct scrol
{
SDL_Rect posback ; 

int mouvement_personnage;
} scorlling ; 


void scrolling (scorlling *scrol,SDL_Rect *positionpersonage);



#endif
