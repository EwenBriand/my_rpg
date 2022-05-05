/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event
*/

#include "my.h"

static void player_action(sfRenderWindow *window, game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyP && is_in_inv(game, "potion", 1) != -1) {
        del_object_in_inv(game, "potion", 1);
        if (game->perso->stat->pv + 30 > game->perso->stat->pv_max)
            game->perso->stat->pv = game->perso->stat->pv_max;
        else
            game->perso->stat->pv += 30;
        game->fight->status = 2;
    }
    if (event.key.code == sfKeyA && is_in_inv(game, "antidote", 1) != -1) {
        del_object_in_inv(game, "antidote", 1);
        game->fight->status = 3;
        game->fight->venin = 0;
    }
}

static void a_key_is_press(sfRenderWindow *window, game_t *game, sfEvent event)
{
    player_action(window, game, event);
    if (event.key.code == sfKeyW) {
        game->fight->enemy[game->mobs]->stats->pv -= phy_dmg_deal(game);
        game->fight->status = 4;
        my_slash(window, game);
    }
    if (event.key.code == sfKeyL) {
        game->fight->enemy[game->mobs]->stats->pv -= mag_dmg_deal(game);
        game->fight->status = 5;
        my_smoke(window, game);
    }
}

static void player_finish_turn(game_t *game)
{
    if (game->fight->venin == 1)
        game->perso->stat->pv -= 5;
    game->fight->status = 1;
}

void player_event(sfRenderWindow *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased && game->fight->status == 0)
            a_key_is_press(window, game, event);
        if (sfKeyboard_isKeyPressed(sfKeySpace) && game->fight->status >= 2
            && game->fight->status <= 5) {
            player_finish_turn(game);
        } else if (sfKeyboard_isKeyPressed(sfKeySpace)
            && game->fight->status == 6)
            game->fight->status = 0;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            pause_menu(window, game);
    }
}
