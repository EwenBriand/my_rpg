/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"

void my_game(sfRenderWindow *window, game_t *game)
{
    while (sfRenderWindow_isOpen(window) && game->state != 1) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, game->map->background->sprite, NULL);
        sfRenderWindow_drawSprite(window, game->charter->sprite->sprite, NULL);
        sfRenderWindow_display(window);
        if (game->state != 2)
            my_event(window, game);
        if (game->state == 2) {
            update_charter(game);
            update_map(game->map, window, game);
            game->state = 0;
        }
    }
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
    sfRenderWindow_destroy(window);
    return END_VALUE;
}
