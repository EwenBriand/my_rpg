/*
** EPITECH PROJECT, 2022
** my project
** File description:
** init player
*/

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    player->hp = 40;
    player->mp = 20;
    player->ep = 20;
    player->pa = 3;
    player->ma = 3;
    player->damage = 10;
    player->poison = 0;
    player ->turn = 0;
    return player;
}