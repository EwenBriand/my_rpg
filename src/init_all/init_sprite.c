/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_sprite
*/

#include "stdlib.h"
#include "SFML/Graphics.h"
#include "../../include/my.h"

sprite_t *create_sprite(char *path, int *p, int *position)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfImage *image = sfImage_createFromFile(path);
    sfIntRect *pos = create_rect(p[0], p[1], p[2], p[3]);
    sfTexture *texture = sfTexture_createFromImage(image, pos);

    sprite->sprite = sfSprite_create();
    sprite->texture = texture;
    sprite->rect = pos;
    sprite->image = image;
    sfSprite_setTexture(sprite->sprite, texture, sfTrue);
    sfSprite_setPosition(
        sprite->sprite, (sfVector2f){position[0], position[1]});
    return (sprite);
}
