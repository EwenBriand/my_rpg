/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_sprite
*/

#include "my.h"

void destroy_sprite(sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfImage_destroy(sprite->image);
    free(sprite->rect);
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}
