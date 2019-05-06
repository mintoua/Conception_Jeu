#ifndef STRUCTS_H_
#define STRUCTS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>

/**
* @struct Ingame
* @brief struct for the games' actual setting
*/
typedef enum
{
	MAINMENU,
	INGAME,
	SETTINGS /*!<Ingame settings*/

}ingame;

/**
* @struct Gameplay
* @brief struct for the gameplay choice
*/
typedef enum
{
	FLECHES,
	CLAVIER,
	MANETTE
}gameplay;

ingame Game;

#endif // STRUCTS_H_