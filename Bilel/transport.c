#include "transport.h"

void stairs()
{
	if(detective.positionInit.x >= 1050 && detective.positionInit.x <= 1150 && detective.positionInit.y >= 450 && detective.positionInit.y <= 550 && scroll.posback.y==1232)
	{
		
		scroll.posback.x=634;
		scroll.posback.y=150;
		detective.positionInit.y=600;
	} 
	else if(detective.positionInit.x >= 1050 && detective.positionInit.x <= 1150 && detective.positionInit.y >= 450 && detective.positionInit.y <= 550 && scroll.posback.y==150)
	{
		
		scroll.posback.x=634;
		scroll.posback.y=1232;
		detective.positionInit.y=600;
	}
}