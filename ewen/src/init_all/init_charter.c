/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_charter
*/

#include "my.h"

charter_t *create_charter(char *path, int *pos)
{
    charter_t *charter = malloc(sizeof(charter_t));

    int *ok = malloc(sizeof(int) * 2);
    ok[0] = 1920 / 2 - 100;
    ok[1] = 1080 / 2 - 70;
    charter->pos = malloc(sizeof(int) * 2);
    charter->exep = malloc(sizeof(int) * 2);
    charter->pos[0] = 2;
    charter->pos[1] = 4;
    charter->exep[0] = 0;
    charter->exep[1] = 0;
    pos[2] = 50;
    pos[3] = 50;
    charter->sprite = create_sprite(path, pos, ok);

    sfSprite_setScale(charter->sprite->sprite, (sfVector2f){2, 2});
    return (charter);
}
