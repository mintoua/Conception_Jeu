#include "button.h"

void initButton(Button *B,int x,int y,int w,int h,char nomduf[])
{
	B->buttonimage=NULL;

	B->buttonpos.x=x;
	B->buttonpos.y=y;
	B->buttonpos.w=w;
	B->buttonpos.h=h;

	B->buttonimage=IMG_Load(nomduf);

	if(B->buttonimage==NULL){
		fprintf(stderr,"Unable to load png: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void freeButton(Button tab[],int n)
{
	int i;

	for(i=0;i<n;i++)
		SDL_FreeSurface(tab[i].buttonimage);

}