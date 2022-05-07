/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** dmg_deal
*/

#include "my.h"

int phy_dmg_deal(game_t *game)
{
    int dmg = game->perso->stat->att_phy + game->perso->bucheron;
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
    int dmg = game->perso->stat->att_ma + game->perso->druide;
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
