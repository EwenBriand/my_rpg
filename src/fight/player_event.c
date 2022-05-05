/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event
*/

#include "my.h"

int phy_dmg_deal(game_t *game)
{
    int dmg = game->perso->stat->att_phy;
    if (game->perso->equip->foot != NULL)
        dmg += game->perso->equip->foot->stat->att_phy;
    if (game->perso->equip->weapon != NULL)
        dmg += game->perso->equip->weapon->stat->att_phy;
    dmg -= game->fight->enemy[game->mobs]->stats->def_phy;
    if (dmg < 0)
        dmg = 0;
    return dmg;
}

int mag_dmg_deal(game_t *game)
{
    int dmg = game->perso->stat->att_ma;
    if (game->perso->equip->shoulder != NULL)
        dmg += game->perso->equip->shoulder->stat->att_ma;
    if (game->perso->equip->weapon != NULL)
        dmg += game->perso->equip->weapon->stat->att_ma;
    if (game->perso->equip->gauntlet != NULL)
        dmg += game->perso->equip->gauntlet->stat->att_ma;
    dmg -= game->fight->enemy[game->mobs]->stats->def_ma;
    if (dmg < 0)
        dmg = 0;
    return dmg;
}

static void a_key_is_press(game_t *game, sfEvent event)
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
    if (event.key.code == sfKeyW) {
        game->fight->enemy[game->mobs]->stats->pv -= phy_dmg_deal(game);
        game->fight->status = 4;
    }
    if (event.key.code == sfKeyL) {
        game->fight->enemy[game->mobs]->stats->pv -= mag_dmg_deal(game);
        game->fight->status = 5;
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
        if (event.type == sfEvtKeyReleased)
            a_key_is_press(game, event);
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
