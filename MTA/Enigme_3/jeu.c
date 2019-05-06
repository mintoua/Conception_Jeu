/**
 * @file jeu.c
 * @brief Writing Program.
 * @author Mintoua T Level-Up
 * @version 0.1
 * @date Apr 28, 2019
 *
 *Writing program for enigme
 *
 */
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "defs.h"
#include "jeu.h"
#include "text.h"
#include "enigme.h"

/**
 * @brief Pour Afficher le jeu
 * @author Mintoua T Level-Up
 * @param screen .c'est l'écran du jeu
 * @date Apr 28, 2019
 * @return 1 bon jeu ou 0 fin jeu
 */
int jouer(SDL_Surface * screen)
{
SDL_Surface *bravo=NULL,*congrat=NULL,*end=NULL,*failed=NULL,*goodluck=NULL, *gameover=NULL;
SDL_Rect p_bravo, p_congrat, p_end, p_failed,p_go;

    p_bravo.x=0;
    p_bravo.y=0;
    p_congrat.x=0;
    p_congrat.y=0;
    p_end.x=0;
    p_end.y=0;
    p_failed.x=0;
    p_failed.y=0;
p_go.x=0;
p_go.y=0;
    bravo=IMG_Load("bravo.png");
    congrat=IMG_Load("congrat.jpg");
    end=IMG_Load("end.jpg");
    failed=IMG_Load("failed.jpg");
gameover=IMG_Load("gameover.png");

	int done = 0; int e;
	int tmp=0, vie = 3, score = 50;

	Text txt;
	
	SDL_Event event;
	int keysHeld[323] = {0}; // everything will be initialized to false
	
	TTF_Font *police = NULL;


	if(loadFont(&police) == EXIT_FAILURE)
	{
		printf("Erreuer Chargement Font ttf\n");
		return(-1);
	}

	initText(&txt);

	// program Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


	while(!done) 
	{

		while (SDL_PollEvent(&event)) 
			
		{
			// check for messages
			switch (event.type) 
			{
				// exit if the window is closed
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
			 switch (event.key.keysym.sym)
           		 	{
           			 case SDLK_RETURN:
				while(vie !=0)
				{
                			e = enigme(screen, police, &txt,&vie,&score,&tmp);
displayText(police,&txt,screen,vie,score,tmp);
                   			 switch(e)
                   			 {
                   			 case 1 : //bonne reponse
					score ++;
                      			SDL_BlitSurface(bravo,NULL,screen,&p_bravo);
displayText(police,&txt,screen,vie,score,tmp);
                      			SDL_Flip(screen);
                      			SDL_Delay(2000);
					vie =0;
					return 0;
                      			break;

                    			case 0 : // mauvaise reponse
					score --;
					vie --;
                      			SDL_BlitSurface(failed,NULL,screen,&p_failed);
displayText(police,&txt,screen,vie,score,tmp);
                      			SDL_Flip(screen);
                      			SDL_Delay(2000);
					if(vie == 0)
                      			{SDL_BlitSurface(gameover,NULL,screen,&p_go);
displayText(police,&txt,screen,vie,score,tmp);
                      			SDL_Flip(screen);
                      			SDL_Delay(3000);
                      			return 0;}
                      			break;
                    			}
				}
						
               			 break;
				}
			}

		} // end of message processing

		tmp ++;
		displayText(police,&txt,screen,vie,score,tmp);
		SDL_Flip(screen);
			
	}

	                // free loaded bitmap

	TTF_CloseFont(police);
	return(0);
}
