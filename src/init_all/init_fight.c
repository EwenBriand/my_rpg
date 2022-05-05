/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_fight
*/

#include <stdlib.h>
#include "my.h"

static stat_t *creat_stat_first_enemy(void)
{
    stat_t *stat = malloc(sizeof(stat_t));
    stat->pv = 30;
    stat->pv_max = 30;
    stat->att_phy = 20;
    stat->def_phy = 13;
    stat->att_ma = 0;
    stat->def_ma = 5;
    return stat;
}

static stat_t *creat_stat_second_enemy(void)
{
    stat_t *stat = malloc(sizeof(stat_t));
    stat->pv = 30;
    stat->pv_max = 30;
    stat->att_phy = 0;
    stat->def_phy = 5;
    stat->att_ma = 20;
    stat->def_ma = 13;
    return stat;
}

static enemy_t *create_first_enemy(void)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    int *pos = malloc(sizeof(int) * 2);
    int *rect = malloc(sizeof(int) * 4);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 1920;
    rect[3] = 1080;
    pos[0] = 1300;
    pos[1] = 500;
    enemy->sprite = create_sprite("sprites/fight/mob1.png", rect, pos);
    enemy->stats = creat_stat_first_enemy();
    free(rect);
    free(pos);
    return enemy;
}

static enemy_t *create_second_enemy(void)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    int *pos = malloc(sizeof(int) * 2);
    int *rect = malloc(sizeof(int) * 4);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 1920;
    rect[3] = 1080;
    pos[0] = 1300;
    pos[1] = 500;
    enemy->sprite = create_sprite("sprites/fight/mob2.png", rect, pos);
    enemy->stats = creat_stat_second_enemy();
    free(rect);
    free(pos);
    return enemy;
}

void init_fight(game_t *game)
{
    game->fight = malloc(sizeof(fight_t));
    int *pos = malloc(sizeof(int) * 2);
    int *rect = malloc(sizeof(int) * 4);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 1920;
    rect[3] = 1080;
    pos[0] = 0;
    pos[1] = 0;
    game->fight->back =
        create_sprite("sprites/fight/background.png", rect, pos);
    game->fight->enemy = malloc(sizeof(enemy_t) * 3);
    game->fight->enemy[0] = create_first_enemy();
    game->fight->enemy[1] = create_second_enemy();
    game->fight->enemy[2] = NULL;
    init_text(game);
    create_slash(game);
}
