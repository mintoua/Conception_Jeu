#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include "enigme_clavier.h"
#include "random.h"
#include "text.h"
#include "defs.h"

int equation_enigme(SDL_Surface *ecran)
{
	SDL_Event event; int p; TTF_Font *police;
	SDL_Surface *chaine=NULL;
	SDL_Surface *image1;
	SDL_Surface *image2;
	SDL_Rect pos;
	SDL_Rect position;
	SDL_Rect positionimage;
	Text equation;

	initText(&equation);
	p = loadFont(&police);
	int a,b,c,d,e,k=0,rp,cpt=0,continuer=1;
	char trans[30],carac[2];

	image1=IMG_Load("win.png");
	image2=IMG_Load("lost.png");
/*	pos.x=0;
	pos.y=0;
	position.x=50;
	position.y=50;
	positionimage.x=0;
	positionimage.y=0;*/
	a=nombre();
	b=nombre();
	c=nombre();
	d=nombre();
	displayText(police,&equation,ecran,a,b,c,d);
	/*while(continuer)
        {
		SDL_WaitEvent(&event);
		//while(SDL_PollEvent(&event));
                switch(event.type)
                {
                	case SDL_QUIT:
                        	continuer = 0;
                                break;
                        case SDL_KEYDOWN:
				printf("\n %d \n",cpt);
				carac[1]='\0';
                        	switch(event.key.keysym.sym)
                                {
                                	case SDLK_0:
                                        	trans[cpt]='0';
						carac[0]='0';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
        					SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_1:
                                        	trans[cpt]='1';
						carac[0]='1';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
        					SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_2:
        					trans[cpt]='2';
						carac[0]='2';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
        					SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);			
                                                break;
                                        case SDLK_3:
                                                trans[cpt]='3';
						carac[0]='3';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
      					  	SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_4:
                                                trans[cpt]='4';
						carac[0]='4';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
		                                break;
                                        case SDLK_5:
                                                trans[cpt]='5';
						carac[0]='5';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_6:
                                                trans[cpt]='6';
						carac[0]='6';
						chaine = TTF_RenderText_Blended(police,trans, couleurblanche);
        					SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=50;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_7:
                                              	trans[cpt]='7';
						carac[0]='7';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_8:
                                                trans[cpt]='8';
						carac[0]='8';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_9:
                                                trans[cpt]='9';
						carac[0]='9';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        /*case SDLK_9:
                                                trans[cpt]='9';
						carac[0]='9';
						chaine = TTF_RenderText_Blended(police,trans, couleurblanche);
       					        SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=50;
						SDL_Flip(ecran);
						break;
					case SDLK_COMMA:
						trans[cpt]=',';
						carac[0]=',';
						chaine = TTF_RenderText_Blended(police,trans, couleurblanche);
       					        SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=50;
						SDL_Flip(ecran);
						break;
                                        case SDLK_RETURN:
                                                continuer=0;
                                                break;
                                        default:
						trans[cpt]='&';
						carac[0]='&';
						chaine = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                               	}
                        cpt++;
			trans[cpt]='\0';
			printf("\n %s \n",trans);
			break;
                }
        }
	rp=atoi(trans);
	e=a*(d*d)+(b*d)+c;
	if(e==rp)
	{	
		printf("\nReponse correcte\n");
		SDL_BlitSurface(image1,NULL,ecran,&positionimage);
		SDL_Flip(ecran);
		SDL_Delay(5000);
            	k += 500;
	}
	else
	{	
		printf("\nReponse incorrect\n");
		SDL_BlitSurface(image2,NULL,ecran,&positionimage);
		SDL_Flip(ecran);
		SDL_Delay(5000);
                k -= 500;
	}*/
 freeFont(&police);
	SDL_FreeSurface(chaine);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	return k;
}
