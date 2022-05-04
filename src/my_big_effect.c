/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** my_big_effect
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

static void new_pos(sfVertex *vertex, int speed, double time, int angle)
{
    vertex->position.x += (speed * cos(angle) - speed * sin(angle)) * time;
    vertex->position.y += (speed * sin(angle) + speed * cos(angle)) * time;
}

static void draw_particule(sfRenderWindow *window, game_t *game)
{
    draw_map(window, game);
    sfRenderWindow_drawVertexArray(window, game->particule_array[0], sfFalse);
    sfRenderWindow_drawVertexArray(window, game->particule_array[1], sfFalse);
    sfRenderWindow_drawVertexArray(window, game->particule_array[2], sfFalse);
    sfRenderWindow_display(window);
}

static void reset_particule(game_t *game)
{
    for (int i = 0; i < 360; ++i) {
        sfVertexArray_getVertex(game->particule_array[0], i)->position =
            (sfVector2f){1920 / 2 + 0, 1080 / 2 + 0};
        sfVertexArray_getVertex(game->particule_array[1], i)->position =
            (sfVector2f){1920 / 2 + 100, 1080 / 2 - 100};
        sfVertexArray_getVertex(game->particule_array[2], i)->position =
            (sfVector2f){1920 / 2 - 100, 1080 / 2 - 100};
    }
}

void my_big_effect(sfRenderWindow *window, game_t *game)
{
    srand(time(NULL));
    double sec = 0;
    int speed = 0;

    sfClock_restart(game->clock);
    while (sec < 1) {
        sec = sfClock_getElapsedTime(game->clock).microseconds / 1000000.0;
        for (int i = 0; i < 360; ++i) {
            speed = (rand() % 30 + 1) / 10;
            new_pos(sfVertexArray_getVertex(game->particule_array[0], i),
                speed, sec, i);
            new_pos(sfVertexArray_getVertex(game->particule_array[1], i),
                speed, sec, i);
            new_pos(sfVertexArray_getVertex(game->particule_array[2], i),
                speed, sec, i);
        }
        draw_particule(window, game);
    }
    reset_particule(game);
}
