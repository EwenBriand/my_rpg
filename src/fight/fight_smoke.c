/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** fight_smoke
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

static void new_pos(sfVertex *vertex, double speed, double time, int angle)
{
    vertex->position.x += (speed * cos(angle) - speed * sin(angle)) * time;
    vertex->position.y += (speed * sin(angle) + speed * cos(angle)) * time;
}

static void draw_particule(sfRenderWindow *window, game_t *game)
{
    char *pv_perso =
        my_strcat("HP PLAYER  ", my_int_to_str(game->perso->stat->pv));
    char *pv_ennemi = my_strcat("HP ENEMY  ",
        my_int_to_str(game->fight->enemy[game->mobs]->stats->pv));

    sfText_setPosition(game->fight->hp, (sfVector2f){100, 200});
    sfText_setString(game->fight->hp, pv_perso);
    sfRenderWindow_drawText(window, game->fight->hp, NULL);
    sfText_setPosition(game->fight->hp, (sfVector2f){100, 300});
    sfText_setString(game->fight->hp, pv_ennemi);
    sfRenderWindow_drawText(window, game->fight->hp, NULL);
    sfRenderWindow_drawText(window, game->fight->text, NULL);
    sfRenderWindow_drawVertexArray(window, game->fight->smoke, sfFalse);
    sfRenderWindow_display(window);
    free(pv_ennemi);
    free(pv_perso);
}

static void reset_particule(game_t *game)
{
    for (int i = 0; i < 360; ++i) {
        sfVertexArray_getVertex(game->fight->smoke, i)->position =
            (sfVector2f){1920 / 2 + 700, 1080 / 2 + 250};
    }
}

void my_smoke(sfRenderWindow *window, game_t *game)
{
    srand(time(NULL));
    double sec = 0;
    double speed = 0;

    sfClock_restart(game->clock);
    while (sec < 0.5) {
        sec = sfClock_getElapsedTime(game->clock).microseconds / 1000000.0;
        for (int i = 0; i < 360; ++i) {
            speed = (rand() % 100 + 1) / 10;
            new_pos(
                sfVertexArray_getVertex(game->fight->smoke, i), speed, sec, i);
        }
        draw_particule(window, game);
    }
    reset_particule(game);
}
