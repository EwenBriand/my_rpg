/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_sprite
*/

#include <SFML/Graphics.h>
#include "../../include/my.h"
#include "stdlib.h"

void destroy_sprite(sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfImage_destroy(sprite->image);
    free(sprite->rect);
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}
