/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_map
*/

#include "my.h"

void destroy_map(map_t *map)
{
    destroy_sprite(map->background);
    free(map);
}
