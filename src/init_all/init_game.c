/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_game
*/

#include <SFML/Audio.h>
#include "../../include/my.h"
#include "stdlib.h"

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

void create_pause_button(game_t *game)
{
    int *pos = malloc(sizeof(int) * 2);
    int *rect = malloc(sizeof(int) * 4);
    rect[0] = 0;
    rect[1] = 0;
    rect[2] = 200;
    rect[3] = 200;
    pos[0] = 1920 / 2 - 170;
    pos[1] = 1080 / 2 - 250;
    game->resume_btn = create_sprite("ressources/resume.png", rect, pos);
    pos[0] = 1920 / 2 - 170;
    pos[1] = 1080 / 2 + 100;
    game->quit_btn = create_sprite("ressources/btn_quit.png", rect, pos);
    sfSprite_setScale(game->resume_btn->sprite, (sfVector2f){8, 8});
    sfSprite_setScale(game->quit_btn->sprite, (sfVector2f){8, 8});
    free(pos);
}

static void init_lot_of_things(game_t *game)
{
    game->chest = 0;
    game->state = 0;
    game->nb_fight = 0;
    game->mobs = 0;
    game->fight->venin = 0;
    game->fight->status = 0;
    game->clock = sfClock_create();
    game->shop.clock1.clock = sfClock_create();
    game->shop.clock2.clock = sfClock_create();
}

game_t *creat_my_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    creat_map_and_charter(game);
    game->pnj_scene = init_pnj_scene();
    init_fight(game);
    init_lot_of_things(game);
    game->perso = init_perso();
    game->all_objets = init_all_objects();
    game->all_pnj = init_pnjs();
    init_shop(game);
    game->level_up_sound = sfMusic_createFromFile("music/level_up.ogg");
    game->fireworks = sfMusic_createFromFile("music/fireworks.ogg");
    game->quest_complete_sound = sfMusic_createFromFile("music/quest.ogg");
    game->particule_array = init_all_array();
    create_pause_button(game);
    return (game);
}
