/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** move_cam
*/

#include "../../include/my.h"
#include "stdlib.h"
#include "SFML/Graphics.h"

#include "stdio.h"

void change_charter_bis(game_t *game, int type)
{
    if (type == 2) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(0, 100, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
                game->charter->sprite->image, game->charter->sprite->rect);
        sfSprite_setTexture(game->charter->sprite->sprite,
                            game->charter->sprite->texture, sfTrue);
    } else if (type == 3) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(0, 150, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
                game->charter->sprite->image, game->charter->sprite->rect);
        sfSprite_setTexture(game->charter->sprite->sprite,
                            game->charter->sprite->texture, sfTrue);
    } else
        change_charter_tree(game, type);
}

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
    } else if (type == 1) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(0, 50, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
            game->charter->sprite->image, game->charter->sprite->rect);
        sfSprite_setTexture(game->charter->sprite->sprite,
            game->charter->sprite->texture, sfTrue);
    } else
        change_charter_bis(game, type);
}

void move_map(map_t *map, sfRenderWindow *window, game_t *game)
{
    sfClock_restart(game->clock);
    int nb[2] = {0, 42};
    int sec = 1;
    int i = 0;
    static int type = 0;
    int old_pos[2] = {map->background->rect->top, map->background->rect->left};
    while (
        old_pos[1] != map->pos[1] * 100 || old_pos[0] != map->pos[0] * 100) {
        nb[0] = sfClock_getElapsedTime(game->clock).microseconds / 10000.0;
        move_map_four(nb, &sec, map, old_pos);
        if (nb[0] < 8 * i)
            change_charter(game, type);
        else if (nb[0] >= 8 * i) {
            ++i;
            ++type;
            type = move_map_tree(type);
        }
        draw_map(window, game);
        sfRenderWindow_display(window);
    }
}

void move_map_vert(map_t *map, sfRenderWindow *window, game_t *game)
{
    int old_pos[2] = {map->background->rect->top, map->background->rect->left};
    static int type = 0;
    int nb[2] = {0, 0};
    int sec = 1;
    int i = 0;

    sfClock_restart(game->clock);
    while (old_pos[0] != map->pos[0] * 100) {
        nb[0] = sfClock_getElapsedTime(game->clock).microseconds / 10000.0;
        move_map_four(nb, &sec, map, old_pos);
        if (nb[0] < 8 * i)
            change_charter(game, type);
        else if (nb[0] >= 8 * i) {
            ++i;
            ++type;
            type = move_map_tree(type);
        }
        draw_map(window, game);
        sfRenderWindow_display(window);
    }
}

void move_map_hor(map_t *map, sfRenderWindow *window, game_t *game)
{
    int old_pos[2] = {map->background->rect->top, map->background->rect->left};
    static int type = 0;
    int nb[2] = {0, 1};
    int sec = 1;
    int i = 0;

    sfClock_restart(game->clock);
    while (old_pos[1] != map->pos[1] * 100) {
        nb[0] = sfClock_getElapsedTime(game->clock).microseconds / 10000.0;
        move_map_four(nb, &sec, map, old_pos);
        if (nb[0] < 8 * i)
            change_charter(game, type);
        else if (nb[0] >= 8 * i) {
            ++i;
            ++type;
            type = move_map_tree(type);
        }
        draw_map(window, game);
        sfRenderWindow_display(window);
    }
}
