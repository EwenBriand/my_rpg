/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** fight_slash
*/

#include "my.h"

static void new_pos(sfVertex *vertex, int speed)
{
    vertex->position.x += speed;
    vertex->position.y += speed;
}

static void draw_particule(sfRenderWindow *window, game_t *game)
{
    draw_fight_scene(window, game, 0);
    sfRenderWindow_drawVertexArray(window, game->fight->slash, sfFalse);
    sfRenderWindow_display(window);
}

static void reset_particule(game_t *game)
{
    int count = 0;
    for (int j = 0; j < 10; ++j)
        for (int i = 0; i < 50; ++i) {
            sfVertexArray_getVertex(game->fight->slash, count++)->position =
                (sfVector2f){1920 / 2 + i - j + 500, 1080 / 2 + 50 + i};
        }
}

void my_slash(sfRenderWindow *window, game_t *game)
{
    double sec = 0;
    int speed = 6;

    sfClock_restart(game->clock);
    while (sec < 0.5) {
        sec = sfClock_getElapsedTime(game->clock).microseconds / 1000000.0;
        for (int i = 0; i < 500; ++i) {
            new_pos(sfVertexArray_getVertex(game->fight->slash, i), speed);
        }
        draw_particule(window, game);
    }
    reset_particule(game);
}
