/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"

void my_event(sfRenderWindow *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            game->state = 1;
        if (event.type == sfEvtKeyReleased) {
            if (event.key.code == 18
                && game->map->pos[0] < game->map->size_y) {
                ++game->map->pos[0];
                game->state = 2;
                game->charter->rota = 0;
                ++game->charter->pos[0];
                game->input = 's';
            }
            if (event.key.code == sfKeyD
                && game->map->pos[1] < game->map->size_x) {
                ++game->map->pos[1];
                game->state = 2;
                game->charter->rota = 3;
                ++game->charter->pos[1];
                game->input = 'd';
            }
            if (event.key.code == sfKeyQ && game->map->pos[1] > -4) {
                --game->map->pos[1];
                game->state = 2;
                game->charter->rota = 1;
                --game->charter->pos[1];
                game->input = 'q';
            }
            if (event.key.code == 25 && game->map->pos[0] > -2) {
                --game->map->pos[0];
                game->state = 2;
                game->charter->rota = 2;
                --game->charter->pos[0];
                game->input = 'z';
            }
            if (event.key.code == sfKeyP) {
                game->map->scale += 0.1;
                game->state = 2;
            }
            //     printf("%i %i %f\n", map->pos[0], map->pos[1], map->scale);
        }
    }
}

void change_charter(sfRenderWindow *window, game_t *game, int type)
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
    sfClock *clock = sfClock_create();
    int time = 0;
    int sec = 1;
    int i = 0;
    static int type = 0;
    int old_pos[2] = {map->background->rect->top, map->background->rect->left};
    while (
        old_pos[1] != map->pos[1] * 100 || old_pos[0] != map->pos[0] * 100) {
        time = sfClock_getElapsedTime(clock).microseconds / 10000.0;
        if (time < 1 * sec) {
            free((sfIntRect *) map->background->rect);
            sfTexture_destroy(map->background->texture);
            map->background->rect =
                create_rect(old_pos[0], old_pos[1], 1920, 1080);
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
    sfClock_destroy(clock);
}

void move_map_vert(map_t *map, sfRenderWindow *window, game_t *game)
{
    int old_pos[2] = {map->background->rect->top, map->background->rect->left};
    sfClock *clock = sfClock_create();
    static int type = 0;
    int time = 0;
    int sec = 1;
    int i = 0;
    int save = map->background->rect->left;

    while (old_pos[0] != map->pos[0] * 100) {
        time = sfClock_getElapsedTime(clock).microseconds / 10000.0;
        if (time < 1 * sec) {
            free((sfIntRect *) map->background->rect);
            sfTexture_destroy(map->background->texture);

            map->background->rect = create_rect(old_pos[0], save, 1920, 1080);
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
    sfClock_destroy(clock);
    // printf("FINISH : %i %i %i %i\n", map->background->rect->top,
    //     map->background->rect->left, map->pos[0], map->pos[1]);
}

void move_map_hor(map_t *map, sfRenderWindow *window, game_t *game)
{
    int old_pos[2] = {map->background->rect->top, map->background->rect->left};
    sfClock *clock = sfClock_create();
    static int type = 0;
    int time = 0;
    int sec = 1;
    int i = 0;
    int save = map->background->rect->top;

    while (old_pos[1] != map->pos[1] * 100) {
        time = sfClock_getElapsedTime(clock).microseconds / 10000.0;
        if (time < 1 * sec) {
            free((sfIntRect *) map->background->rect);
            sfTexture_destroy(map->background->texture);

            map->background->rect = create_rect(save, old_pos[1], 1920, 1080);
            map->background->texture = sfTexture_createFromImage(
                map->background->image, map->background->rect);

            sfSprite_setTexture(
                map->background->sprite, map->background->texture, sfTrue);
            sfSprite_setScale(
                map->background->sprite, (sfVector2f){map->scale, map->scale});

        } else if (time >= 1 * sec) {
            if (old_pos[1] < map->pos[1] * 100)
                old_pos[1] += 1;
            if (old_pos[1] > map->pos[1] * 100)
                old_pos[1] -= 1;
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
    sfClock_destroy(clock);
    // printf("FINISH : %i %i %i %i\n", map->background->rect->top,
    //     map->background->rect->left, map->pos[0], map->pos[1]);
}

void update_charter(game_t *game)
{
    sfVector2f pos;
    sfSprite_setRotation(
        game->charter->sprite->sprite, game->charter->rota * 90);

    if (game->charter->rota == 0) {
        pos = sfSprite_getPosition(game->charter->sprite->sprite);
        sfSprite_setPosition(game->charter->sprite->sprite,
            (sfVector2f){1920 / 2 - 100 + game->charter->exep[0],
                1080 / 2 - 70 + game->charter->exep[1]});
    }
    if (game->charter->rota == 1) {
        pos = sfSprite_getPosition(game->charter->sprite->sprite);
        sfSprite_setPosition(game->charter->sprite->sprite,
            (sfVector2f){1920 / 2 - 100 + 80 + game->charter->exep[0],
                game->charter->exep[1] + 1080 / 2 - 70 - 20});
    }
    if (game->charter->rota == 2) {
        pos = sfSprite_getPosition(game->charter->sprite->sprite);
        sfSprite_setPosition(game->charter->sprite->sprite,
            (sfVector2f){1920 / 2 - 100 + 90 + game->charter->exep[0],
                game->charter->exep[1] + 1080 / 2 - 70 + 60});
    }
    if (game->charter->rota == 3) {
        pos = sfSprite_getPosition(game->charter->sprite->sprite);
        sfSprite_setPosition(game->charter->sprite->sprite,
            (sfVector2f){1920 / 2 - 100 + game->charter->exep[0],
                game->charter->exep[1] + 1080 / 2 - 70 + 75});
    }
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
    game_t *game = creat_my_game(window);

    sfRenderWindow_setTitle(window, "OASIS");
    sfRenderWindow_setFramerateLimit(window, 200);
    sfRenderWindow_clear(window, sfBlack);
    my_game(window, game);
    sfRenderWindow_destroy(window);
    return END_VALUE;
}
