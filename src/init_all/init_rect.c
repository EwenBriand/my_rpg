/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_rect
*/

#include "SFML/Graphics.h"
#include "stdlib.h"

sfIntRect *create_rect(int top, int left, int width, int height)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = top;
    rect->left = left;
    rect->width = width;
    rect->height = height;
    return (rect);
}
