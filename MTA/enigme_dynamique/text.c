/**
 * @file text.c
 * @brief Writing Program.
 * @author Mintoua T Level-Up
 * @version 0.1
 * @date Apr 21, 2019
 *
 *Writing program for text
 *
 */
#include "text.h"
#include "defs.h"

/**
 * @brief Pour Initialiser le texte
 * @author Mintoua T Level-Up
 * @param T Le texte ecrit
 * @date Apr 28, 2019
 * @return void(rien)
 */
void initText(Text *T)
{
	T->equation=NULL;
}

/**
 * @brief Pour Charger le texte
 * @author Mintoua T Level-Up
 * @param *police Le pointeur sur la police des textes
 * @date Apr 28, 2019
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
int loadFont(TTF_Font **police)
{
	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return EXIT_FAILURE;
	}
	*police = TTF_OpenFont("fente.ttf", 30);
	return EXIT_SUCCESS;
}
/**
 * @brief Pour Afficher le texte
 * @author Mintoua T Level-Up
 * @param *police Le pointeur sur la police des textes
 * @param *T Le texte ecrit
 * @param screen Ecran du jeu
 * @param vie vie joueur
 * @param score son score
 * @param tmp temps du jeu
 * @date Apr 28, 2019
 * @return NULL(rien)
 */

void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,int a,int b,int c,int d)
{
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Rect positionequation;


	positionequation.x=SCREEN_W-600;


	positionequation.y=80;


	char equation[50];

	//vie
	sprintf(equation,"Pour x=%d que vaut %dx²+%dx+%d",a,b,c,d);
	T->equation = TTF_RenderText_Shaded(police,equation,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->equation, SDL_SRCCOLORKEY, SDL_MapRGB(T->equation->format, 255, 255, 255));


	//clean screen &&
	//Flip the backbuffer to the primary Hardware Video Memory
	SDL_BlitSurface(T->equation,NULL,screen,&positionequation);
	
}


/**
 * @brief Pour Liberer l'espace occupé par les textes
 * @author Mintoua T Level-Up
 * @param *police Le pointeur sur la police des textes
 * @date Apr 28, 2019
 * @return NULL(rien)
 */
void freeFont(TTF_Font **police)
{
	TTF_CloseFont(*police); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}
