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
	SDL_Surface *equation;  /*!< Score*/
};
typedef struct Text Text;


void initText(Text *T);
int loadFont(TTF_Font **police);
void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,int a,int b,int c,int d);
void freeFont(TTF_Font **police);
#endif
