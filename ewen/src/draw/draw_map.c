/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** draw_map
*/

#include "my.h"

void draw_map(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->map->background->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->charter->sprite->sprite, NULL);
}
