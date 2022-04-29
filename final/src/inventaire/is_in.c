/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** is_in
*/

#include "../../include/my.h"

int is_in_inv(game_t *game, char *name, int nb)
{
    for (int i = 0; game->perso->inv->inv[i] != NULL; ++i)
        if (my_strcmp(game->perso->inv->inv[i]->name, name) == 0
            && game->perso->inv->inv[i]->stack >= nb)
            return (i);
    return (-1);
}
