/* ici vous pouvez inclure certaines headers necessaire à l'écriture de vos fonctions
vous pouvez même créer d'autres si voulez ça dependra du necessiteux
*/

#include "background.h" //pour le moment

void init_bck(background tab[])
{
	int i; 
for(i=0; i<4; i++)
	{
		tab[i].image = NULL;
		tab[i].position.x=0;
		tab[i].position.y=0;
		tab[i].music= NULL;
		tab[i].texte=NULL;
	}

<<<<<<< HEAD
#include <stdio.h>
 #include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
 #include <SDL/SDL_mixer.h>
#include "bk.h"
=======
}

void 
>>>>>>> 2d25391ef00ff2ea0f6c3b41364ee2c0ebccc310































































































































































































































































































































































































































#include "menu1.h"
#include "persop.h"
#include "score.h"
void init_bk(BACKGROUND* b)
{
b->bg=NULL;
 b->bg=IMG_Load("img/ni1.png");
b->position.x=0;
b->position.y=0;
b->position.w=(b->bg)->w;
b->position.h=(b->bg)->h;
int stage=1;
b->scroll.x=0;
b->scroll.y=0;
	int position_actuel=0;
  
}



void afficher_bk(BACKGROUND bk,SDL_Surface *fenetre)// afficher bg
{
SDL_BlitSurface(bk.bg,NULL,fenetre,&bk.position);
}

void scrollingbg(int sens,BACKGROUND *bg)//sens droit gauche jump yahbet
{
	if(sens==1&&bg->position.x-2032>-8000)//droite
	{ 

bg->position.x-=32; //bg twa5er


	}
	else if(sens==2&&bg->position.x+32<=0)//gauche
	{ 
bg->position.x+=32;//bg t9adem
	}
	
	else if(sens==3)//haut
	{
		bg->scroll.y-=10;
//bg->position.y-=10;
	}
	else if(sens==4)//bas
	{
		bg->scroll.y+=10;
//bg->position.y+=10;
		
}
//

//

//à vous d'ecriture les fonctions deja definit dans background.h
