#ifndef MENU_H_
#define MENU_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>
#include "button.h"
#include "structs.h"

extern Button Volumes[11];
extern Button Backgrounds[11];
extern Button Buttons[20];
extern ingame Game; 

void menu(int etat,int Vetat, int S_etat,SDL_Surface *screen,SDL_Rect pbackground);

#endif // MENU_H_