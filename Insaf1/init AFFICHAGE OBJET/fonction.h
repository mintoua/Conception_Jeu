#ifndef FONCTION_H_
#define FONCTION_H_


SDL_Surface *load_image( char *filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

int init();
int load_files();
void clean_up();




#endif
