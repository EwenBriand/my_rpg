/*
** EPITECH PROJECT, 2022
** ewen
** File description:
** move_cam
*/

#include "my.h"

void move_charter(sfRenderWindow *window, game_t *game, float x, float y)
{
    //  sfSprite_setPosition(game->charter->sprite->sprite, (sfVector2f){x,
    //  y});
    sfVector2f pos = sfSprite_getPosition(game->charter->sprite->sprite);
    sfClock *clock = sfClock_create();
    int time = 0;
    int sec = 1;
    int i = 1;
    int type = 0;

    printf("OOOOK %f %f\n%f %f", x, y, pos.x, pos.y);
    while (pos.x != x || pos.y != y) {
        printf("OK %f %f\n", pos.x, pos.y);
        time = sfClock_getElapsedTime(clock).microseconds / 10000.0;
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
            change_charter(window, game, type);
        else if (time >= 8 * i) {
            ++i;
            ++type;
            if (type == 8)
                type = 0;
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, game->map->background->sprite, NULL);
        sfRenderWindow_drawSprite(window, game->charter->sprite->sprite, NULL);
        sfRenderWindow_display(window);
    }
}

void hor_spe_move(game_t *game, sfRenderWindow *window)
{
    int old_pos[2] = {
        game->map->background->rect->top, game->map->background->rect->left};
    sfVector2f pos = sfSprite_getPosition(game->charter->sprite->sprite);

    if (game->input == 'd') {
        game->charter->exep[0] += 200;
        move_charter(window, game, pos.x + 200, pos.y);
        printf("%f %f \n%f %f\n", pos.x, pos.y,
            sfSprite_getPosition(game->charter->sprite->sprite).x,
            sfSprite_getPosition(game->charter->sprite->sprite).y);
    } else if (game->input == 'q') {
        game->charter->exep[0] -= 200;
        move_charter(window, game, pos.x - 200, pos.y);
        printf("%f %f \n%f %f\n", pos.x, pos.y,
            sfSprite_getPosition(game->charter->sprite->sprite).x,
            sfSprite_getPosition(game->charter->sprite->sprite).y);
    }
}

void vert_spe_move(game_t *game, sfRenderWindow *window)
{
    int old_pos[2] = {
        game->map->background->rect->top, game->map->background->rect->left};
    sfVector2f pos = sfSprite_getPosition(game->charter->sprite->sprite);

    if (game->input == 'z') {
        game->charter->exep[1] -= 200;
        move_charter(window, game, pos.x, pos.y - 200);
        printf("%f %f \n%f %f\n", pos.x, pos.y,
            sfSprite_getPosition(game->charter->sprite->sprite).x,
            sfSprite_getPosition(game->charter->sprite->sprite).y);
    } else if (game->input == 's') {
        game->charter->exep[1] += 200;
        move_charter(window, game, pos.x, pos.y + 200);
        printf("%f %f \n%f %f\n", pos.x, pos.y,
            sfSprite_getPosition(game->charter->sprite->sprite).x,
            sfSprite_getPosition(game->charter->sprite->sprite).y);
    }
}

void move_static_charter(game_t *game, sfRenderWindow *window)
{
    if ((game->map->pos[1] >= 11
            || (game->map->pos[1] == 10 && game->input == 'q'))
        && game->map->scale > 1)
        hor_spe_move(game, window);
    else if ((game->map->pos[1] >= -4
                 || (game->map->pos[1] == 0 && game->input == 'd'))
        && game->map->scale > 1)
        hor_spe_move(game, window);

    if ((game->map->pos[0] >= 7
            || (game->map->pos[0] == 6 && game->input == 'z'))
        && game->map->scale > 1)
        vert_spe_move(game, window);

    else if ((game->map->pos[0] >= -2
                 || (game->map->pos[0] == 0 && game->input == 's'))
        && game->map->scale > 1)
        vert_spe_move(game, window);
}

int give_type(game_t *game)
{
    printf(
        "HEY %i %i  %c\n", game->map->pos[0], game->map->pos[1], game->input);
    if (((game->map->pos[1] >= 11 || game->map->pos[1] <= -1)
            && (game->input == 'd' || game->input == 'q'))
        || ((game->map->pos[0] >= 7 || game->map->pos[0] <= -1)
            && (game->input == 's' || game->input == 'z'))
        || (game->map->pos[1] == 10 && game->input == 'q')
        || (game->map->pos[1] == 0 && game->input == 'd')
        || (game->map->pos[0] == 6 && game->input == 'z')
        || (game->map->pos[0] == 0 && game->input == 's')
            && game->map->scale > 1)
        return 3;

    if (game->map->pos[0] < 7 && game->map->scale > 1
        && game->map->pos[0] > -1)
        return 1;
    if (game->map->pos[1] < 11 && game->map->scale > 1
        && game->map->pos[1] > -1)
        return 2;
}

void update_map(map_t *map, sfRenderWindow *window, game_t *game)
{
    int type = 0;
    printf("%i %i\n", map->pos[0], map->pos[1]);
    printf("%i %i\n", game->charter->pos[0], game->charter->pos[1]);

    if (map->pos[0] < 7 && map->scale > 1 && map->pos[1] < 11
        && map->pos[0] > -1 && map->pos[1] > -1
        && !((game->map->pos[1] == 10 && game->input == 'q')
            || (game->map->pos[1] == 0 && game->input == 'd')
            || (game->map->pos[0] == 6 && game->input == 'z')
            || (game->map->pos[0] == 0 && game->input == 's')))
        move_map(map, window, game);
    else {
        type = give_type(game);
        if (type == 3)
            return move_static_charter(game, window);
        if (type == 1)
            return move_map_vert(map, window, game);
        if (type == 2)
            return move_map_hor(map, window, game);
    }

    sfSprite_setScale(
        map->background->sprite, (sfVector2f){map->scale, map->scale});
}
