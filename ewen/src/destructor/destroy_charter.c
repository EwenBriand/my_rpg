/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_charter
*/

#include "my.h"

void destroy_charter(charter_t *charter)
{
    destroy_sprite(charter->sprite);
    free(charter->pos);
    free(charter->exep);
    free(charter);
}
