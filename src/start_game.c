/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

void make_code_map(sfRenderWindow *window, game_t *game)
{
    srand(time(NULL));
    int nb_mob = rand() % 6 + 1;
    int code = game->map->map[game->charter->pos[0]][game->charter->pos[1]];

    if (code == 3 || code == 4 || code == 5 || code == 10)
        if (game->nb_fight == 2) {
            game->nb_fight = 0;
            my_fight(window, game, nb_mob);
        } else
            ++game->nb_fight;
    else if (code == 2 || code == 14)
        change_map(window, game, code);
}

void chose_state(sfRenderWindow *window, game_t *game, int state)
{
    if (state == 666)
        open_shop(window, game);
    else
        open_inventory(window, game);
}

void my_game(sfRenderWindow *window, game_t *game)
{
    while (sfRenderWindow_isOpen(window) && game->state != 1) {
        if (game->state == 0)
            draw_map(window, game);
        sfRenderWindow_display(window);
        if (game->state == 666 || game->state == 667)
            chose_state(window, game, game->state);
        else if (game->state != 2)
            my_event(window, game);
        else {
            update_charter(game);
            update_map(game->map, window, game);
            make_code_map(window, game);
            game->state = 0;
        }
        level_up(window, game);
    }
    sfMusic_stop(game->level_up_sound);
    sfMusic_stop(game->fireworks);
    sfMusic_stop(game->quest_complete_sound);
}

int start_game(sfRenderWindow *window)
{
    game_t *game = creat_my_game();

    sfRenderWindow_setTitle(window, "OASIS");
    sfRenderWindow_setFramerateLimit(window, 200);
    sfRenderWindow_clear(window, sfBlack);
    my_game(window, game);
    destroy_game(game);
    sfRenderWindow_close(window);
    return END_VALUE;
}
