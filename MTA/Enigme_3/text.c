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
#include "random.h"

/**
 * @brief Pour Initialiser le texte
 * @author Mintoua T Level-Up
 * @param T Le texte ecrit
 * @date Apr 28, 2019
 * @return void(rien)
 */
void initText(Text *T)
{
	T->score=NULL;
	T->vie=NULL;
	T->tmp=NULL;
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
	*police = TTF_OpenFont("Ubuntu-Title.ttf", 20);
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

void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,int vie,int score,int tmp)
{
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Rect positionscore;
	SDL_Rect positionvie;
	SDL_Rect positiontmp;
	SDL_Rect positionequation;

	positionscore.x=SCREEN_W-300;
	positionvie.x=SCREEN_W-300;
	positiontmp.x=SCREEN_W-300;
	positionequation.x=SCREEN_W-300;

	positionscore.y=20;
	positionvie.y=50;
	positiontmp.y=80;
	positionequation.y=100;
	

	char Vie[50];
	char Score[50];
	char Tmp[50];
	char equation[50];

int a,b,c,d;
	a=nombre();
	b=nombre();
	c=nombre();
	d=nombre();

	//vie
	sprintf(Vie,"Vie= %d ",vie);
	T->vie = TTF_RenderText_Shaded(police,Vie,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->vie, SDL_SRCCOLORKEY, SDL_MapRGB(T->vie->format, 255, 255, 255));

	//score
	sprintf(Score,"Score =%d pt(s)",score);
	T->score = TTF_RenderText_Shaded(police,Score,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->score, SDL_SRCCOLORKEY, SDL_MapRGB(T->score->format, 255, 255, 255));
	//tmp
	sprintf(Tmp,"Temps= %d s",tmp);
	T->tmp= TTF_RenderText_Shaded(police,Tmp,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->tmp, SDL_SRCCOLORKEY, SDL_MapRGB(T->tmp->format, 255, 255, 255));
	//equation
	sprintf(equation,"Pour x=%d que vaut %dx²+%dx+%d",a,b,c,d);
	T->equation = TTF_RenderText_Shaded(police,equation,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->equation, SDL_SRCCOLORKEY, SDL_MapRGB(T->equation->format, 255, 255, 255));

	//clean screen &&
	//Flip the backbuffer to the primary Hardware Video Memory
	SDL_BlitSurface(T->vie,NULL,screen,&positionvie);
	SDL_BlitSurface(T->score,NULL,screen,&positionscore);
	SDL_BlitSurface(T->tmp,NULL,screen,&positiontmp);
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
