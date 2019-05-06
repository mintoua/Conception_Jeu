/**  
* @file text.h
*/ 
#ifndef TEXT_H
#define TEXT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

/**  
* @struct Text  
* @brief struct for Text
*/
struct Text {
	SDL_Surface *score;  /*!< Score*/
	SDL_Surface *vie; /*!< Vie*/
	SDL_Surface *tmp; /*!< Temps jeu*/
	SDL_Surface *equation;
};
typedef struct Text Text;


void initText(Text *T);
int loadFont(TTF_Font **police);
void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,int vie,int score,int tmp);

#endif
