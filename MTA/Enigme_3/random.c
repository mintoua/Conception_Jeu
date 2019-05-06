/**
 * @file random.c
 * @brief Writing Program.
 * @author Mintoua T Level-Up
 * @version 0.1
 * @date Apr 28, 2019
 *
 *Writing program for Random
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

/**
 * @brief Pour calculer un nbre aleatoire
 * @author Mintoua T Level-Up
 * @date Apr 28, 2019
 * @return un nbre
 */
int nombre(void)
{
    srand(time(NULL));

    return 1+rand()%6;
}
