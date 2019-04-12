
//Les fichiers d'entête
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string.h>

//Les attributs de l'écran (640 * 480)
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 700;
const int SCREEN_BPP = 32;

//Les surfaces
SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;

//La structure d'événements que nous allons utiliser
SDL_Event event;

SDL_Surface *load_image( char *filename )
{
    //L'image qui est chargé
    SDL_Surface* loadedImage = NULL;

    //L'image optimisée que nous allons utiliser
    SDL_Surface* optimizedImage = NULL;

    //Chargement de l'image
    loadedImage = IMG_Load( filename );

    //Si l'image est bien chagée
    if( loadedImage != NULL )
    {
        //Création de l'image optimisée
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Libération de l'ancienne image
        SDL_FreeSurface( loadedImage );
    }

    //On retourne l'image otpimisée
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;
    


    //On "blitte" la surface
    SDL_BlitSurface( source, NULL , destination, &offset );
}

int init()
{
    //Initialisation de tous les sous-systèmes de sdl
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 0;
    }

    //Mise en place de l'écran
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //S'il y a une erreur lors de la mise en place de l'écran
    if( screen == NULL )
    {
        return 0;
    }

    //Mise en place de la barre caption
    SDL_WM_SetCaption( "Event test", NULL );

    //Si tout s'est bien passé
    return 1;
}

int load_files()
{
    //Chargement de l'image
    image = load_image( "x.png" );

    //S'il y a une erreur au chargement de l'image
    if( image == NULL )
    {
        return 0;
    }

    //Si tout s'est bien passé
    return 1;
}

void clean_up()
{
    //Libèration des surfaces
    SDL_FreeSurface( image );

    //On quitte sdl
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Ce qui va nous permettre de quitter
   int quit = 0;

    //Initialisation
    if( init() == 0 )
    {
        return 1;
    }

    //Chargement des fichiers
    if( load_files() == 0 )
    {
        return 1;
    }

    //Application des surfaces sur l'écran
    apply_surface( 0, 0, image, screen );

    //Mise à jour de l'écran
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    //Tant que l'utilisateur n'a pas quitté
    while( quit == 0 )
    {
        //Tant qu'il y a un événement
        while( SDL_PollEvent( &event ) )
        {
            //Si l'utilisateur à cliqué sur le X de la fenêtre
            if( event.type == SDL_QUIT )
            {
                //On quitte le programme
                quit = 1;
            }
        }
    }

    //Libèration des surfaces et on quitte sdl
    clean_up();

    return 0;
}
