#include"animation.h"

void animerHero(int direction)
{

    if (detective.frameTimer <= 0)
    {

        detective.frameTimer = TIME_BETWEEN_2_FRAMES;


        detective.frameNumber++;


        if(detective.frameNumber >= detective.perso[direction]->w / PLAYER_WIDTH)
            detective.frameNumber = 0;

    }
    else
        detective.frameTimer--;

    affPerso(&detective,screen,direction);

}