/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_particule
*/

#include <SFML/Graphics.h>
#include "stdlib.h"

void destroy_particule(sfVertexArray **particule)
{
    for (int i = 0; particule[i] != NULL; ++i)
        sfVertexArray_destroy(particule[i]);
    free(particule);
}
