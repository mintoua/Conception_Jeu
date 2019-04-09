#include "entete.h"

SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
	SDL_Color color;
	Uint32 col=0;

	//Determine position

	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);

	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);

	//convertir color
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);

	return (color);
}

int collision_Parfaite(SDL_Surface *calque, int coord_x, int coord_y){

	SDL_Color color;

	int c = 0;

	color=GetPixel(calque,coord_x,coord_y);
	
	if ((color.r == 0) && (color.b == 0) && (color.g == 0)){
		c = 1;
	}

	return c;
}

/*SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y){
	SDL_Color color;
	Uint32 col=0;

	//Determine position
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);

	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);

	//convertir color
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}

int collision_Parfaite(SDL_Surface *calque, SDL_Rect posperso, int x, int y){

	SDL_Color color;

	int c = 0;C
	
	if ((color.r == 0) && (color.b == 0) && (color.g == 0)){
		c = 1;
	}

	return c;
}



/*int collision_Parfaite(SDL_Surface *Background,int x, int y)
{

	int collision=0;
	SDL_Color color ;


	SDL_GetRGB(getpixel(Background,x,y),Background->format,&color.r,&color.g,&color.b);

	if (color.r==0 && color.g==0 && color.b==0)
		collision=1;

	return collision;

}*/




/*
SDL_Color GetPixel(SDL_Surface *background ,Coordinate C)
{


SDL_Color color;
Uint32 col=0;

char* pPosition=(char*) background->pixels;
pPosition+=(background->pitch *C.Y);
pPosition+=(background->format->BytesPerPixel *C.X);
memcpy(&col,pPosition,background->format->BytesPerPixel);


SDL_GetRGB(col,background->format,&color.r, &color.g, &color.b);
return (color);




}
Uint32 getpixel(SDL_Surface *surface,int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
   
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;      
    }
}*/
