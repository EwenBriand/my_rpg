/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_map
*/

#include "../../include/my.h"
#include "stdlib.h"

void destroy_map(map_t *map)
{
    for (int i = 0; map->map[i] != NULL; ++i)
        free(map->map[i]);
    free(map->map);
    free(map->pos);
    destroy_sprite(map->background);
    free(map);
}
