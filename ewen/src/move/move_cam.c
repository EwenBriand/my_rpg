/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** move_cam
*/

#include "my.h"

void change_charter(game_t *game, int type)
{
    if (type == 0) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(0, 0, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
            game->charter->sprite->image, game->charter->sprite->rect);

        sfSprite_setTexture(game->charter->sprite->sprite,
            game->charter->sprite->texture, sfTrue);
    }
    if (type == 1) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(0, 50, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
            game->charter->sprite->image, game->charter->sprite->rect);

        sfSprite_setTexture(game->charter->sprite->sprite,
            game->charter->sprite->texture, sfTrue);
    }
    if (type == 2) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(0, 100, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
            game->charter->sprite->image, game->charter->sprite->rect);

        sfSprite_setTexture(game->charter->sprite->sprite,
            game->charter->sprite->texture, sfTrue);
    }
    if (type == 3) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(0, 150, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
            game->charter->sprite->image, game->charter->sprite->rect);

        sfSprite_setTexture(game->charter->sprite->sprite,
            game->charter->sprite->texture, sfTrue);
    }
    if (type == 4) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(50, 0, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
            game->charter->sprite->image, game->charter->sprite->rect);

        sfSprite_setTexture(game->charter->sprite->sprite,
            game->charter->sprite->texture, sfTrue);
    }
    if (type == 5) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(50, 50, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
            game->charter->sprite->image, game->charter->sprite->rect);

        sfSprite_setTexture(game->charter->sprite->sprite,
            game->charter->sprite->texture, sfTrue);
    }
    if (type == 6) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(50, 100, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
            game->charter->sprite->image, game->charter->sprite->rect);

        sfSprite_setTexture(game->charter->sprite->sprite,
            game->charter->sprite->texture, sfTrue);
    }
    if (type == 7) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(50, 150, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
            game->charter->sprite->image, game->charter->sprite->rect);

        sfSprite_setTexture(game->charter->sprite->sprite,
            game->charter->sprite->texture, sfTrue);
    }
}

void move_map(map_t *map, sfRenderWindow *window, game_t *game)
{
    sfClock_restart(game->clock);
    int time = 0;
    int sec = 1;
    int i = 0;
    static int type = 0;
    int old_pos[2] = {map->background->rect->top, map->background->rect->left};
    while (
        old_pos[1] != map->pos[1] * 100 || old_pos[0] != map->pos[0] * 100) {
        time = sfClock_getElapsedTime(game->clock).microseconds / 10000.0;
        if (time < 1 * sec) {
            sfTexture_destroy(map->background->texture);
            map->background->rect->top = old_pos[0];
            map->background->rect->left = old_pos[1];
            map->background->texture = sfTexture_createFromImage(
                map->background->image, map->background->rect);

            sfSprite_setTexture(
                map->background->sprite, map->background->texture, sfTrue);

        } else if (time >= 1 * sec) {
            if (old_pos[1] < map->pos[1] * 100)
                old_pos[1] += 1;
            if (old_pos[0] < map->pos[0] * 100)
                old_pos[0] += 1;
            if (old_pos[1] > map->pos[1] * 100)
                old_pos[1] -= 1;
            if (old_pos[0] > map->pos[0] * 100)
                old_pos[0] -= 1;
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

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, game->map->background->sprite, NULL);
        sfRenderWindow_drawSprite(window, game->charter->sprite->sprite, NULL);
        sfRenderWindow_display(window);
    }
}

void move_map_vert(map_t *map, sfRenderWindow *window, game_t *game)
{
    int old_pos[2] = {map->background->rect->top, map->background->rect->left};
    static int type = 0;
    int time = 0;
    int sec = 1;
    int i = 0;

    sfClock_restart(game->clock);
    while (old_pos[0] != map->pos[0] * 100) {
        time = sfClock_getElapsedTime(game->clock).microseconds / 10000.0;
        if (time < 1 * sec) {
            sfTexture_destroy(map->background->texture);

            map->background->rect->top = old_pos[0];
            map->background->texture = sfTexture_createFromImage(
                map->background->image, map->background->rect);

            sfSprite_setTexture(
                map->background->sprite, map->background->texture, sfTrue);

        } else if (time >= 1 * sec) {
            if (old_pos[0] < map->pos[0] * 100)
                old_pos[0] += 1;
            if (old_pos[0] > map->pos[0] * 100)
                old_pos[0] -= 1;
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

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, game->map->background->sprite, NULL);
        sfRenderWindow_drawSprite(window, game->charter->sprite->sprite, NULL);
        sfRenderWindow_display(window);
    }
}

void move_map_hor(map_t *map, sfRenderWindow *window, game_t *game)
{
    int old_pos[2] = {map->background->rect->top, map->background->rect->left};
    static int type = 0;
    int time = 0;
    int sec = 1;
    int i = 0;

    sfClock_restart(game->clock);
    while (old_pos[1] != map->pos[1] * 100) {
        time = sfClock_getElapsedTime(game->clock).microseconds / 10000.0;
        if (time < 1 * sec) {
            sfTexture_destroy(map->background->texture);

            map->background->rect->left = old_pos[1];
            map->background->texture = sfTexture_createFromImage(
                map->background->image, map->background->rect);

            sfSprite_setTexture(
                map->background->sprite, map->background->texture, sfTrue);
        } else if (time >= 1 * sec) {
            if (old_pos[1] < map->pos[1] * 100)
                old_pos[1] += 1;
            if (old_pos[1] > map->pos[1] * 100)
                old_pos[1] -= 1;
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

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, game->map->background->sprite, NULL);
        sfRenderWindow_drawSprite(window, game->charter->sprite->sprite, NULL);
        sfRenderWindow_display(window);
    }
}
