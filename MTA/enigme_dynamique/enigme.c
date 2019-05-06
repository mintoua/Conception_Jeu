#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include "enigme_clavier.h"
int nbre_aleatoire(int MAX ,int MIN)
{
	int alea;
	srand(time(NULL));
	alea=(rand()%(MAX -MIN +1) +MIN);
	printf("%d",alea);
	return alea;
}
void afficher(int a, int b,int c ,int d,SDL_Surface *chaine ,SDL_Surface *ecran,SDL_Color couleurblanche,TTF_Font *police)
{
	char sms[50];
	SDL_Rect pos;
	sprintf(sms,"Pour x=%d que vaut %dx²+%dx+%d",a,b,c,d);
	printf("%s",sms);
	chaine=TTF_RenderText_Blended(police,sms,couleurblanche);
	SDL_BlitSurface(chaine,NULL,ecran,&pos);
        SDL_Flip(ecran);
	//SDL_Delay(2000);
	//TTF_CloseFont(police);
	//SDL_FreeSurface(chaine);
	
}
int equation(SDL_Surface *ecran)
{
	int a,b,c,d,e,k=0,rp,cpt=0,continuer=1;
	char trans[30],carac[2];
	SDL_Event event;
	SDL_Surface *chaine1=NULL,*chaine2=NULL;
	SDL_Surface *image1;
	SDL_Surface *image2;
	SDL_Rect pos;
	SDL_Rect position;
	SDL_Rect positionimage;
	SDL_Color couleurblanche={255,255,255};
	//SDL_Color couleurnoir={0,0,0,0}
	TTF_Font *police=NULL;
	TTF_Init();
	image1=IMG_Load("win.png");
	image2=IMG_Load("lost.png");
	
	pos.x=0;
	pos.y=0;
	position.x=50;
	position.y=50;
	positionimage.x=0;
	positionimage.y=0;
	
	printf("HELLO WORD");
	a=nbre_aleatoire(100,-100);
	b=nbre_aleatoire(60,-40);
	c=nbre_aleatoire(24,-90);
	d=nbre_aleatoire(100,-100);
	/*sprintf(sms,"Pour x=%d que vaut %dx²+%dx+%d",a,b,c,d);
	printf("%s",sms);
	police=TTF_OpenFont("fente.tff",30);
	chaine1=TTF_RenderText_Blended(police,sms,couleurblanche);
	SDL_BlitSurface(chaine1,NULL,ecran,&pos);
        SDL_Flip(ecran);
	SDL_Delay(2000);*/
	afficher(a,b,c,d,chaine1,ecran,couleurblanche,police);
	while(continuer)
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
						chaine2 = TTF_RenderText_Blended(police,carac, couleurblanche);
        					SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_1:
                                        	trans[cpt]='1';
						carac[0]='1';
						chaine2 = TTF_RenderText_Blended(police,carac, couleurblanche);
        					SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_2:
        					trans[cpt]='2';
						carac[0]='2';
						chaine2 = TTF_RenderText_Blended(police,carac, couleurblanche);
        					SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);			
                                                break;
                                        case SDLK_3:
                                                trans[cpt]='3';
						carac[0]='3';
						chaine2= TTF_RenderText_Blended(police,carac, couleurblanche);
      					  	SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_4:
                                                trans[cpt]='4';
						carac[0]='4';
						chaine2 = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
		                                break;
                                        case SDLK_5:
                                                trans[cpt]='5';
						carac[0]='5';
						chaine2 = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_6:
                                                trans[cpt]='6';
						carac[0]='6';
						chaine2 = TTF_RenderText_Blended(police,trans, couleurblanche);
        					SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=50;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_7:
                                              	trans[cpt]='7';
						carac[0]='7';
						chaine2 = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_8:
                                                trans[cpt]='8';
						carac[0]='8';
						chaine2 = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_9:
                                                trans[cpt]='9';
						carac[0]='9';
						chaine2= TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine2,NULL,ecran,&position);
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
						break;*/
					case SDLK_COMMA:
						trans[cpt]=',';
						carac[0]=',';
						chaine2= TTF_RenderText_Blended(police,trans, couleurblanche);
       					        SDL_BlitSurface(chaine2,NULL,ecran,&position);
						position.x+=50;
						SDL_Flip(ecran);
						break;
                                        case SDLK_RETURN:
                                                continuer=0;
                                                break;
                                        default:
						trans[cpt]='&';
						carac[0]='&';
						chaine2 = TTF_RenderText_Blended(police,carac, couleurblanche);
						SDL_BlitSurface(chaine2,NULL,ecran,&position);
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
	}
	TTF_CloseFont(police);
	TTF_Quit();
	SDL_FreeSurface(chaine1);
	SDL_FreeSurface(chaine2);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	return k;
}
