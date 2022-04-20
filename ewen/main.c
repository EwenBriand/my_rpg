/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"

void make_code_map(game_t *game)
{
    int code = game->map->map[game->charter->pos[0]][game->charter->pos[1]];

    if (code == 3 || code == 4 || code == 5 || code == 10)
        if (game->fight == 3)
            game->fight = 0;
        // fight
        else
            ++game->fight;
    else if (code == 2)
        printf("change map\n");
}

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
            make_code_map(game);
            game->state = 0;
            printf("%d %d\n", game->perso->druide, game->perso->bucheron);
            for (int i = 0; game->perso->inv->inv[i] != NULL; ++i)
                printf("%s %d\n", game->perso->inv->inv[i]->name,
                    game->perso->inv->inv[i]->stack);
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
