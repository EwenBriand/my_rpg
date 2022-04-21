/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_bame
*/

#include "my.h"

static void creat_map_and_charter(game_t *game)
{
    int *pos = malloc(sizeof(int) * 4);
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 1920;
    pos[3] = 1080;
    game->map = create_map("maps/city1.png", pos, "map_int/city1.int");
    pos[2] = 1920 / 100 - 1;
    pos[3] = 1080 / 100 - 1;
    game->charter = create_charter("sprites/charter.png", pos);
    free(pos);
}

game_t *creat_my_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    creat_map_and_charter(game);
    game->state = 0;
    game->fight = 0;
    game->clock = sfClock_create();
    game->perso = init_perso();
    game->all_objets = init_all_objects();
    game->all_pnj = init_pnjs();
    game->pnj_scene = init_pnj_scene();
    return (game);
}

// 0 18  -2 14
