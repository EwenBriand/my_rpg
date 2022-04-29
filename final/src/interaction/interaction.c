/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event
*/

#include "../../include/my.h"

void interaction(sfRenderWindow *window, game_t *game, sfEvent event)
{
    int code;
    if (event.key.code == sfKeyI) {
        code = game->map->map[game->charter->pos[0]][game->charter->pos[1]];
        if (code != 0 && code != 1 && code != 2 && code != 3)
            make_interaction(window, game, code);
    }
    if (event.key.code == sfKeyF) {
        del_object_in_inv(game, "baie", 3);
    }
    if (event.key.code == sfKeyV) {
        del_object_in_inv(game, "bois", 10);
    }
}
