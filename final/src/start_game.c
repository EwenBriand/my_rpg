/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include <stdio.h>
#include "my.h"

void make_code_map(sfRenderWindow *window, game_t *game)
{
    int code = game->map->map[game->charter->pos[0]][game->charter->pos[1]];

    if (code == 3 || code == 4 || code == 5 || code == 10)
        if (game->fight == 3)
            game->fight = 0;
        // fight
        else
            ++game->fight;
    if (code == 2 || code == 14)
        change_map(window, game, code);
}

void my_game(sfRenderWindow *window, game_t *game)
{
    while (sfRenderWindow_isOpen(window) && game->state != 1) {
        if (game->state == 0)
            draw_map(window, game);
        sfRenderWindow_display(window);
        if (game->state == 666) {
            open_shop(window, game);
        } else if (game->state != 2)
            my_event(window, game);
        else {
            update_charter(game);
            update_map(game->map, window, game);
            make_code_map(window, game);
            game->state = 0;

            printf("%d %d\nok %d %d\n", game->charter->pos[0],
                game->charter->pos[1], game->perso->xp, game->perso->xp_supp);
            for (int i = 0; game->perso->inv->inv[i] != NULL; ++i)
                printf("%s %d\n", game->perso->inv->inv[i]->name,
                    game->perso->inv->inv[i]->stack);
            printf("credits: %i\n", game->perso->credits);
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
