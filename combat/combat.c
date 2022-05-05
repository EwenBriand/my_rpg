/*
** EPITECH PROJECT, 2022
** my project
** File description:
** combat
*/

#include "combat.h"

int combat(player_t *player, combat_t *combat)
{
    while(player->hp > 0 || combat->creature->count > 0) {
        player_turn(player, combat->creature);
        ennemi_turn(player, combat->creature);
    }
    if (player->hp == 0) {
        return 0;
    } else {
        return 1;
    }
}

int start_combat(void)
{
    int win_cond = 0;
    player_t *player = init_player(void);
    combat_t *combat = init_combat(void);
    win_cond = combat(player, combat);
    return win_cond;
}
