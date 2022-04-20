/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** del
*/

#include "my.h"

void del_object_in_inv(game_t *game, char *name, int nb)
{
    objet_t *obj = NULL;
    int i = 0;

    for (; game->perso->inv->inv[i] != NULL; ++i)
        if (my_strcmp(game->perso->inv->inv[i]->name, name) == 0) {
            obj = game->perso->inv->inv[i];
            break;
        }
    if (obj == NULL)
        return;
    if (obj->stack - nb <= 0) {
        for (; game->perso->inv->inv[i + 1] != NULL; ++i)
            game->perso->inv->inv[i] = game->perso->inv->inv[i + 1];
        game->perso->inv->inv[i] = NULL;
        --game->perso->inv->nb_obj;
        obj->stack = 0;
    } else {
        obj->stack -= nb;
    }
}
