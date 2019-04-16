/* ici vous pouvez inclure certaines headers necessaire à l'écriture de vos fonctions
vous pouvez même créer d'autres si voulez ça dependra du necessiteux
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ennemi.h" //pour le moment
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
entite_sec init_ennemi()
{
entite_sec e ;	
e.pos.x=0;
e.pos.y=0;
e.surface = IMG_Load("Ennemi0.PNG");
return (e) ;
}
void afficher_ennemi(SDL_Surface * ecran, entite_sec e)
{ 
SDL_BlitSurface( e.surface, NULL , ecran , &e.pos);
}
