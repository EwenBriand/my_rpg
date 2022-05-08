/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_bestiaire_minimap
*/

#include <stdlib.h>
#include "my.h"

void destroy_bestiaire(bestiaire_t *bestiaire)
{
    destroy_sprite(bestiaire->back);
    destroy_sprite(bestiaire->enemy1);
    destroy_sprite(bestiaire->enemy2);
    sfText_destroy(bestiaire->stat_enemy);
    free(bestiaire);
}

void destroy_minimap(minimap_t *minimap)
{
    destroy_sprite(minimap->map1);
    destroy_sprite(minimap->map2);
    free(minimap);
}
