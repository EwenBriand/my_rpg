/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_minimap
*/

#include <stdlib.h>
#include "my.h"

void init_minimap(game_t *game)
{
    game->minimap = malloc(sizeof(minimap_t));
    game->minimap->map1 = create_sprite(
        "maps/city1.png", (int[4]){0, 0, 2100, 1200}, (int[2]){0, 0});
    game->minimap->map2 = create_sprite(
        "maps/cave.png", (int[4]){0, 0, 2100, 1200}, (int[2]){0, 0});
    game->minimap->which_map = 0;
    sfSprite_setScale(game->minimap->map1->sprite, (sfVector2f){1, 0.9});
    sfSprite_setScale(game->minimap->map2->sprite, (sfVector2f){1, 0.9});
}
