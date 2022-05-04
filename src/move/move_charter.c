/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** move_charter
*/

#include "../../include/my.h"
#include "SFML/Graphics.h"

void move_charter(sfRenderWindow *window, game_t *game, float x, float y)
{
    sfVector2f pos = sfSprite_getPosition(game->charter->sprite->sprite);
    int time = 0;
    int sec = 1;
    int i = 1;
    int type = 0;

    sfClock_restart(game->clock);
    while (pos.x != x || pos.y != y) {
        time = sfClock_getElapsedTime(game->clock).microseconds / 10000.0;
        if (time < 1 * sec) {
            sfSprite_setPosition(
                game->charter->sprite->sprite, (sfVector2f){pos.x, pos.y});
        } else if (time >= 1 * sec) {
            if (pos.x < x)
                pos.x += 2;
            if (pos.x > x)
                pos.x -= 2;
            if (pos.y < y)
                pos.y += 2;
            if (pos.y > y)
                pos.y -= 2;
            ++sec;
        }
        if (time < 8 * i)
            change_charter(game, type);
        else if (time >= 8 * i) {
            ++i;
            ++type;
            if (type == 8)
                type = 0;
        }
        draw_map(window, game);
        sfRenderWindow_display(window);
    }
}

void hor_spe_move(game_t *game, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(game->charter->sprite->sprite);

    if (game->input == 'd') {
        game->charter->exep[0] += 200;
        move_charter(window, game, pos.x + 200, pos.y);
    } else if (game->input == 'q') {
        game->charter->exep[0] -= 200;
        move_charter(window, game, pos.x - 200, pos.y);
    }
}

void vert_spe_move(game_t *game, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(game->charter->sprite->sprite);

    if (game->input == 'z') {
        game->charter->exep[1] -= 200;
        move_charter(window, game, pos.x, pos.y - 200);
    } else if (game->input == 's') {
        game->charter->exep[1] += 200;
        move_charter(window, game, pos.x, pos.y + 200);
    }
}

void move_static_charter(game_t *game, sfRenderWindow *window)
{
    if ((game->map->pos[1] >= 11
            || (game->map->pos[1] == 10 && game->input == 'q')))
        hor_spe_move(game, window);
    else if ((game->map->pos[1] >= -4
            || (game->map->pos[1] == 0 && game->input == 'd')))
        hor_spe_move(game, window);

    if ((game->map->pos[0] >= 7
            || (game->map->pos[0] == 6 && game->input == 'z')))
        vert_spe_move(game, window);

    else if ((game->map->pos[0] >= -2
            || (game->map->pos[0] == 0 && game->input == 's')))
        vert_spe_move(game, window);
}

int give_type(game_t *game)
{
    if (((game->map->pos[1] >= 11 || game->map->pos[1] <= -1)
            && (game->input == 'd' || game->input == 'q'))
        || ((game->map->pos[0] >= 7 || game->map->pos[0] <= -1)
            && (game->input == 's' || game->input == 'z'))
        || (game->map->pos[1] == 10 && game->input == 'q')
        || (game->map->pos[1] == 0 && game->input == 'd')
        || (game->map->pos[0] == 6 && game->input == 'z')
        || (game->map->pos[0] == 0 && game->input == 's'))
        return 3;

    if (game->map->pos[0] < 7 && game->map->pos[0] > -1)
        return 1;
    if (game->map->pos[1] < 11 && game->map->pos[1] > -1)
        return 2;
    return 0;
}
