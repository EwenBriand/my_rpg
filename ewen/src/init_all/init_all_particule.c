/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_all_particule
*/

#include "my.h"

static sfVertexArray *init_all_particule(sfColor color, int x, int y)
{
    sfVertexArray *new = sfVertexArray_create();
    sfVertex particule = {.position = (sfVector2f){1920 / 2 + x, 1080 / 2 + y},
        .color = color,
        .texCoords = (sfVector2f){1920 / 2 + x, 1080 / 2 + y}};

    for (int i = 0; i < 360; ++i)
        sfVertexArray_append(new, particule);
    return (new);
}

sfVertexArray **init_all_array(void)
{
    sfVertexArray **new = malloc(sizeof(sfVertexArray *) * 4);
    new[0] = init_all_particule(sfWhite, 0, 0);
    new[1] = init_all_particule(sfRed, 100, -100);
    new[2] = init_all_particule(sfBlue, -100, -100);
    new[3] = NULL;

    return (new);
}
