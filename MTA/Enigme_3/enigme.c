/**
 * @file enigme.c
 * @brief Writing Program.
 * @author Mintoua T Level-Up
 * @version 0.1
 * @date Apr 21, 2019
 *
 *Writing program for enigme
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"
#include "random.h"
#include "defs.h"
#include "jeu.h"
#include "text.h"

/**
 * @brief Ecriture de la fonction enigme(affichage et resolution)
 * @author Mintoua T Level-Up
 * @param screen .c'est l'écran du jeu
 * @param police .La police des textes
 * @param T .Le texte ecrit
 * @param vie .La vie du joueur
 * @param score .Son score
 * @param tmp .Le temps du jeu
 * @date Apr 28, 2019
 * @return 1 pour vraie 0 pour fausse reponse
 */
int enigme(SDL_Surface *screen, TTF_Font *police, Text *T,int *vie,int *score,int *tmp)
{

    SDL_Surface *e[6]={NULL,NULL,NULL,NULL,NULL,NULL};

 e[0] = IMG_Load("E1.png");
 e[1] = IMG_Load("E2.png");
 e[2] = IMG_Load("E3.png");
 e[3] = IMG_Load("E4.png");
 e[4] = IMG_Load("E5.png");
 e[5] = IMG_Load("E6.png");

 int i =  0;

 for(;i<6;i++)
 {
    if(!e[i])
 {
   printf("erreur de chargement de l'enigme %d : > %s",i+1,SDL_GetError());
 }

 }


SDL_Rect p_enigme;

p_enigme.x = 0;
p_enigme.y = 0;
int x=nombre();

SDL_Event eventen;
SDL_PollEvent(&eventen);

int cont = 1;
switch(x)
 {

 case 1 :

   SDL_BlitSurface(e[0],NULL,screen,&p_enigme);
(*tmp)++;
displayText(police,&(*T),screen,*vie,*score,*tmp);
   SDL_Flip(screen);
   while(cont)
   {
      SDL_WaitEvent(&eventen);
      switch(eventen.type)
   {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       return 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            if(eventen.button.x>=423&&eventen.button.x<=682&&eventen.button.y>=526&&eventen.button.y<=698)
                {

                    return 1;
                }else
                {

                    return 0;
                }
                break;
        }
        break;
       }
    }
    break;

    case 2 :
   SDL_BlitSurface(e[1],NULL,screen,&p_enigme);
(*tmp)++;
displayText(police,&(*T),screen,*vie,*score,*tmp);
   SDL_Flip(screen);
   while(cont)
   {
      SDL_WaitEvent(&eventen);
      switch(eventen.type)
   {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       cont = 0;
       return 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            if(eventen.button.x>=16&&eventen.button.x<=392&&eventen.button.y>=507&&eventen.button.y<=574)
                {

                    return 1;
                }else
                {

                    return 0;
                }
                break;
        }
        break;
       }
    }
    break;

    case 3 :
   SDL_BlitSurface(e[2],NULL,screen,&p_enigme);
(*tmp)++;
displayText(police,&(*T),screen,*vie,*score,*tmp);
   SDL_Flip(screen);
   while(cont)
   {
      SDL_WaitEvent(&eventen);
      switch(eventen.type)
   {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       return 0;
       cont = 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            if(eventen.button.x>=21&&eventen.button.x<=250&&eventen.button.y>=533&&eventen.button.y<=663)
                {

                    return 1;
                }else
                {

                    return 0;
                }
                break;
        }
        break;
       }
    }
    break;

    case 4 :
   SDL_BlitSurface(e[3],NULL,screen,&p_enigme);
(*tmp)++;
displayText(police,&(*T),screen,*vie,*score,*tmp);
   SDL_Flip(screen);
     while(cont)
   {
       SDL_WaitEvent(&eventen);
      switch(eventen.type)
   {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       cont = 0;
       return 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            if(eventen.button.x>=77&&eventen.button.x<=325&&eventen.button.y>=531&&eventen.button.y<=697)
                {

                    return 1;
                }else
                {

                    return 0;
                }
                break;
        }
        break;
       }

    }
    break;

    case 5 :
   SDL_BlitSurface(e[4],NULL,screen,&p_enigme);
(*tmp)++;
displayText(police,&(*T),screen,*vie,*score,*tmp);
   SDL_Flip(screen);
   while(cont)
   {
       SDL_WaitEvent(&eventen);
      switch(eventen.type)
    {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       cont = 0;
       return 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            if(eventen.button.x>=722&&eventen.button.x<=1100&&eventen.button.y>=513&&eventen.button.y<=575)
                {
                    return 1;
                }else
                {
                    return 0;
                }
                break;
        }break;

       }
    }
    break;

    case 6 :
   SDL_BlitSurface(e[5],NULL,screen,&p_enigme);
(*tmp)++;
displayText(police,&(*T),screen,*vie,*score,*tmp);
   SDL_Flip(screen);
   while(cont)
   {
      SDL_WaitEvent(&eventen);
      switch(eventen.type)
   {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       cont = 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            if(eventen.button.x>=30&&eventen.button.x<=413&&eventen.button.y>=633&&eventen.button.y<=700)
                {
                    return 1;
                }else
                {
                    return 0;
                }
                break;
        }
        break;

       }
    }
    break;
}
}









