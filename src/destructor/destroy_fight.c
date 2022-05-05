/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_fight
*/

#include <stdlib.h>
#include "my.h"

void destroy_fight(fight_t *fight)
{
    sfVertexArray_clear(fight->slash);
    sfVertexArray_clear(fight->smoke);
    sfVertexArray_destroy(fight->slash);
    sfVertexArray_destroy(fight->smoke);
    sfText_destroy(fight->hp);
    sfText_destroy(fight->text);
    destroy_sprite(fight->back);
    destroy_sprite(fight->enemy[0]->sprite);
    destroy_sprite(fight->enemy[1]->sprite);
    free(fight->enemy[0]->stats);
    free(fight->enemy[1]->stats);
    free(fight->enemy[0]);
    free(fight->enemy[1]);
    free(fight->enemy);
    free(fight);
}
