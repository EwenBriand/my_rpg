/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** level_up
*/

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

static void my_big_effect(sfRenderWindow *window, game_t *game)
{
    srand(time(NULL));
    double sec = 0;
    int speed = (rand() % 30 + 1) / 10;

    sfClock_restart(game->clock);
    while (sec < 1) {
        printf("%f\n", sec);
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
}

static void leveling_up(game_t *game)
{
    ++game->perso->level;
    game->perso->xp -= game->perso->xp_supp;
    game->perso->xp_supp += 20;
    game->perso->stat->pv_max += 10;
    game->perso->stat->pv += 10;
    game->perso->stat->att_phy += 2;
    game->perso->stat->def_phy += 2;
    game->perso->stat->att_ma += 2;
    game->perso->stat->def_ma += 2;
}

void level_up(sfRenderWindow *window, game_t *game)
{
    float t = 0;
    if (game->perso->xp >= game->perso->xp_supp) {
        leveling_up(game);
        sfMusic_play(game->level_up_sound);
        sfMusic_play(game->fireworks);
        my_big_effect(window, game);
        sfClock_restart(game->clock);

        draw_map(window, game);
        sfRenderWindow_display(window);
        while (t < 4)
            t = sfClock_getElapsedTime(game->clock).microseconds / 1000000.0;
        sfMusic_stop(game->level_up_sound);
        sfMusic_stop(game->fireworks);

        game->state = 4;
    }
}
