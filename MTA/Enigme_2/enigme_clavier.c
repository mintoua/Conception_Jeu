/**
 * @file enigme_clavier.c
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
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include "enigme_clavier.h"

/**
 * @brief Pour afficher enigme
 * @author Mintoua T Level-Up
 * @param ecran .c'est l'écran du jeu
 * @param chaine .Pour la question  de l'enigme
 * @param police .La police des textes
 * @date Apr 21, 2019
 * @return numero de l'enigme(question) dans le fichier
 */
int afficher_enigme(SDL_Surface *ecran,SDL_Surface *chaine,TTF_Font* police)
{
        FILE* Livre=NULL;
        int MAX=7,MIN=1,alea,s,x;
        char enig[30],trans[500];
        SDL_Rect position;
        TTF_Init();
	SDL_Color couleurBlanche = {255, 255, 255};
        srand(time(NULL));
        Livre=fopen("fichier_enigme.txt","r");
	position.x=0;
	position.y=0;
        if(Livre!=NULL)
        {
                alea=(rand()%(MAX -MIN +1) );
		printf("\n %d \n",alea);
                x=1;
                while(fgets(trans,100,Livre)!=NULL && x!=alea && x!=6)
                {
                        x++;
                }
		printf("\n %s \n",trans);
                fclose(Livre);
        }
	police = TTF_OpenFont("fente.ttf", 30);
        chaine = TTF_RenderText_Blended(police,trans, couleurBlanche);
	SDL_BlitSurface(chaine,NULL,ecran,&position);
        SDL_Flip(ecran);
	//SDL_Delay(5000);
        return alea;
}
/**
 * @brief Ecris le programme pour le resolution et affichage de l'enigme
 * @author Mintoua T Level-Up
 * @param ecran l'ecran du jeu
 * @return entier (score ou vie)
 * @date Apr 21, 2019
 *
 *Writing program for enigme
 *
 */
int enigme_clavier(SDL_Surface *ecran)
{
	SDL_Event event;
	int pos,r, k=0,i=3, j, n=0;
	char enigm[15],trans[30],carac[2];
        int s=1,x=0,cpt=0,continuer=1;
	SDL_Surface *image1;
	SDL_Surface *image2; 
        SDL_Surface *chaine=NULL;
	FILE* reponse=NULL;
	TTF_Init();
	TTF_Font *police=NULL;
	SDL_Rect positionimage;
	image1=IMG_Load("br.png");
	image2=IMG_Load("mr.png");
	positionimage.x=375;
	positionimage.y=250;
        reponse=fopen("reponse_enigme.txt","r");
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Rect position;
	position.x=0;
	position.y=50;
	pos=afficher_enigme(ecran,chaine,police);
	SDL_Flip(ecran);
	//SDL_WaitEvent(&event);
	//while(SDL_PollEvent(&event));
	//r= resolution (pos,ecran,event,chaine,police);
	if(reponse!=NULL)
        {
                while(fscanf(reponse,"%s \n",enigm)!=EOF && s!=pos)
                {
                        s+=1;
                }
		printf("\n %s \n",enigm);
                //x=strlen(enigm)-1;
		fclose(reponse);
	}
        while(continuer)
        {
		SDL_WaitEvent(&event);
		//while(SDL_PollEvent(&event));
		police = TTF_OpenFont("fente.ttf", 30);
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
                                	case SDLK_a:
                                        	trans[cpt]='a';
						carac[0]='a';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
        					SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_b:
                                        	trans[cpt]='b';
						carac[0]='b';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
        					SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_c:
        					trans[cpt]='c';
						carac[0]='c';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
        					SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);			
                                                break;
                                        case SDLK_d:
                                                trans[cpt]='d';
						carac[0]='d';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
      					  	SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_e:
                                                trans[cpt]='e';
						carac[0]='e';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
		                                 break;
                                        case SDLK_f:
                                                trans[cpt]='f';
						carac[0]='f';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_g:
                                                trans[cpt]='g';
						carac[0]='g';
						chaine = TTF_RenderText_Blended(police,trans, couleurBlanche);
        					SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=50;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_h:
                                              	trans[cpt]='h';
						carac[0]='h';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_i:
                                                trans[cpt]='i';
						carac[0]='i';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_j:
                                                trans[cpt]='j';
						carac[0]='j';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_k:
                                                trans[cpt]='k';
						chaine = TTF_RenderText_Blended(police,trans, couleurBlanche);
       					        SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=50;
						SDL_Flip(ecran);
						break;
                                        case SDLK_l:
                                                trans[cpt]='l';
						carac[0]='l';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_m:
                                                trans[cpt]='m';
						carac[0]='m';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_n:
                                                trans[cpt]='n';
						carac[0]='n';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_o:
                                                trans[cpt]='o';
						carac[0]='o';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_p:
                                                trans[cpt]='p';
						carac[0]='p';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_q:
                                                trans[cpt]='q';
						carac[0]='q';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                               	break;
                                        case SDLK_r:
                                                trans[cpt]='r';
						carac[0]='r';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_s:
                                                trans[cpt]='s';
						carac[0]='s';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
					case SDLK_t:
                                                trans[cpt]='t';
						carac[0]='t';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                               	break;
	                                case SDLK_u:
                                                trans[cpt]='u';
						carac[0]='u';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_v:
                                                trans[cpt]='v';
						carac[0]='v';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                      	case SDLK_y:
                                                trans[cpt]='y';
						carac[0]='y';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_w:
                                                trans[cpt]='w';
						carac[0]='w';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_x:
                                                trans[cpt]='x';
						carac[0]='x';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
                                        case SDLK_z:
                                                trans[cpt]='z';
						carac[0]='z';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
                                                break;
					case SDLK_SPACE:
                                                trans[cpt]=' ';
						carac[0]=' ';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x+=20;
						SDL_Flip(ecran);
					break;

					/*case SDLK_BACKSPACE:
						cpt--;
                                                trans[cpt]=' ';
						carac[0]=' ';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
						SDL_BlitSurface(chaine,NULL,ecran,&position);
						position.x-=20;
						SDL_Flip(ecran);
					break;*/
                                        case SDLK_RETURN:
                                                continuer=0;
                                                break;
                                        default:
						trans[cpt]='&';
						carac[0]='&';
						chaine = TTF_RenderText_Blended(police,carac, couleurBlanche);
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
        //trans[cpt]='\0';
	
	/*chaine = TTF_RenderText_Blended(police,trans, couleurBlanche);
        SDL_BlitSurface(chaine,NULL,ecran,&position);*/
        SDL_Flip(ecran);
	SDL_Delay(1000);
	if(strcmp(trans,enigm)==0)
	{	
		printf("\nReponse correcte\n");
		SDL_BlitSurface(image1,NULL,ecran,&positionimage);
		SDL_Flip(ecran);
		SDL_Delay(3000);
            	k = 1;
	}
	else
	{	
		printf("\nReponse incorrect\n");
		SDL_BlitSurface(image2,NULL,ecran,&positionimage);
		SDL_Flip(ecran);
		SDL_Delay(3000);
                k = 0;
	}
	/*if(r==1)
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
	
	TTF_CloseFont(police);
	SDL_FreeSurface(chaine);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	return k;
}


