/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** level_up
*/

#include <SFML/Graphics.h>
#include "my.h"

static void leveling_up(game_t *game)
{
    ++game->perso->level;
    game->perso->xp -= game->perso->xp_supp;
    game->perso->xp_supp += 20;
    game->perso->stat->pv_max += 10;
    game->perso->stat->pv = game->perso->stat->pv_max;
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
