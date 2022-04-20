/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** all_interaction
*/

#include <time.h>
#include "my.h"

static void make_buisson(game_t *game)
{
    srand(time(NULL));
    int nb_baies = rand() % 6 + 1;
    ++game->perso->druide;
    game->map->map[game->charter->pos[0]][game->charter->pos[1]] = 3;
}

static void make_arbre(game_t *game)
{
    srand(time(NULL));
    int nb_bois = rand() % 6 + 1;
    ++game->perso->bucheron;
    game->map->map[game->charter->pos[0]][game->charter->pos[1]] = 3;
    printf("%d\n", nb_bois);
}

void make_interaction(game_t *game, int code)
{
    if (code == 4)
        make_buisson(game);
    if (code == 5)
        make_arbre(game);
    if (code > 5 && code < 11)
        printf("%d is a png\n", code - 5);
}
