#ifndef ENTETE_H_
#define ENTETE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>

#define PLAYER_WIDTH 62
#define PLAYER_HEIGTH 178
#define TIME_BETWEEN_2_FRAMES 4

typedef struct{
	int X;
	int Y;
}Coordonnees;
typedef struct{
	SDL_Rect positionTimer;
	SDL_Surface *time;
	int timer;
}Timer;
typedef struct
{
	SDL_Rect positionInit;
	SDL_Surface *perso[2];
	Timer T;
	Coordonnees C[4];
	int score;
	int frameNumber,frameTimer;
}Hero;

Hero detective;
SDL_Surface* screen;

void affPerso(Hero *A, SDL_Surface *ecran, int direction);
void affScore(Hero *A,SDL_Surface *ecran);
void freePerso(Hero *A);
void difficulty_set(Hero *A,char diff[],int Time);
void initPerso(Hero *A, SDL_Surface *ecran,int posx,int posy);
int collision_Parfaite(SDL_Surface *calque, int x, int y);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
void posPerso(Hero *A);
void animerHero(int directions);
void loadImage(SDL_Surface* sprite,char file_name[]);


#endif /* ENTETE_H_ */
