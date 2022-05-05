/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_shop
*/

#include <stdlib.h>
#include "my.h"

void destroy_shop(game_t *game)
{
    destroy_sprite(game->shop->back);
    destroy_sprite(game->shop->items);
    destroy_sprite(game->shop->grey);
    destroy_sprite(game->shop->green);
    destroy_sprite(game->shop->red);
    destroy_sprite(game->shop->coins);
    free(game->shop->items_shop);
    free(game->shop->text);
    free(game->shop);
}
