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
    game->perso->credits = 1000;
}

static void make_arbre(game_t *game)
{
    srand(time(NULL));
    int nb_bois = rand() % 6 + 1;
    ++game->perso->bucheron;
    game->map->map[game->charter->pos[0]][game->charter->pos[1]] = 3;
    add_object_in_inv(game, "bois", nb_bois);
    game->perso->credits = 1000;
}

static void my_chest(sfRenderWindow *window, game_t *game, int code)
{
    if (code == 13)
        open_chest(window, game);
}

void make_interaction(sfRenderWindow *window, game_t *game, int code)
{
    game->perso->credits = 1000;
    if (code == 12) {
        sfClock_restart(game->shop.clock1.clock);
        game->state = 666;
    }
    if (code == 4)
        make_buisson(game);
    if (code == 5)
        make_arbre(game);
    if (code == 7)
        interaction_pnj1(window, game);
    if (code == 10)
        interaction_pnj2(window, game);
    if (code == 9)
        interaction_pnj3(window, game);
    if (code == 6)
        interaction_pnj4(window, game);
    if (code == 8)
        interaction_pnj5(window, game);
    my_chest(window, game, code);
}