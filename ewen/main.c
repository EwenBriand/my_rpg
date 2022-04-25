/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include <stdlib.h>
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
        draw_map(window, game);
        sfRenderWindow_display(window);
        if (game->state != 2)
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
        }
        level_up(window, game);
    }
    sfMusic_stop(game->level_up_sound);
    sfMusic_stop(game->fireworks);
    sfMusic_stop(game->quest_complete_sound);
}

int main(int argc, char **argv, char **env)
{
    if (env[0] == NULL)
        return ERROR_VALUE;
    sfVideoMode mode = {1920, 1080};
    sfRenderWindow *window =
        sfRenderWindow_create(mode, "window", sfResize | sfClose, NULL);
    game_t *game = creat_my_game();

    sfRenderWindow_setTitle(window, "OASIS");
    sfRenderWindow_setFramerateLimit(window, 200);
    sfRenderWindow_clear(window, sfBlack);
    my_game(window, game);
    destroy_game(game);
    sfRenderWindow_destroy(window);
    return END_VALUE;
}
