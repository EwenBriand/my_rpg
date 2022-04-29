/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** all_interaction
*/

#include <stdlib.h>
#include <time.h>
#include "../../include/my.h"

static void make_buisson(game_t *game)
{
    srand(time(NULL));
    int nb_baies = rand() % 6 + 1;
    ++game->perso->druide;
    game->map->map[game->charter->pos[0]][game->charter->pos[1]] = 3;
    add_object_in_inv(game, "baie", nb_baies);
}

static void make_arbre(game_t *game)
{
    srand(time(NULL));
    int nb_bois = rand() % 6 + 1;
    ++game->perso->bucheron;
    game->map->map[game->charter->pos[0]][game->charter->pos[1]] = 3;
    add_object_in_inv(game, "bois", nb_bois);
}

void make_interaction(sfRenderWindow *window, game_t *game, int code)
{
    if (code == 12) {
        sfClock_restart(game->shop.clock1.clock);
        game->state = 666;
    }
    if (code == 4)
        make_buisson(game);
    if (code == 5)
        make_arbre(game);
    if (code == 7)
        // pnj1
        interaction_pnj1(window, game);
    if (code == 10)
        // pnj2
        interaction_pnj2(window, game);
    if (code == 9)
        // pnj3
        interaction_pnj3(window, game);
    if (code == 6)
        // pnj4
        interaction_pnj4(window, game);
    if (code == 8)
        // pnj5
        interaction_pnj5(window, game);
}
