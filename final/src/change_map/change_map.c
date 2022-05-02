/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** change_map
*/

#include <SFML/Graphics.h>
#include "../../include/my.h"
#include "stdlib.h"

static void create_new_map(game_t *game, char *map, char *tab)
{
    int *pos = malloc(sizeof(int) * 4);
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 1920;
    pos[3] = 1080;
    game->map = create_map(map, pos, tab);
    game->map->pos[1] = -3;
    free(pos);
}

void change_map(sfRenderWindow *window, game_t *game, int code)
{
    sfVector2f pos;
    destroy_map(game->map);
    if (code == 2)
        create_new_map(game, "maps/cave.png", "map_int/cave.int");
    else {
        create_new_map(game, "maps/city1.png", "map_int/city1.int");
        game->charter->exep[1] = 0;
    }
    game->charter->pos[1] = 1;
    game->charter->pos[0] = 2;
    game->charter->exep[0] = -600;
    draw_map(window, game);
    sfRenderWindow_display(window);
}
