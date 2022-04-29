/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update
*/

#include "SFML/Graphics.h"
#include "../../include/my.h"

void update_charter(game_t *game)
{
    sfVector2f pos;
    sfSprite_setRotation(
        game->charter->sprite->sprite, game->charter->rota * 90);

    if (game->charter->rota == 0) {
        pos = sfSprite_getPosition(game->charter->sprite->sprite);
        sfSprite_setPosition(game->charter->sprite->sprite,
            (sfVector2f){1920 / 2 - 100 + game->charter->exep[0],
                1080 / 2 - 70 + game->charter->exep[1]});
    }
    if (game->charter->rota == 1) {
        pos = sfSprite_getPosition(game->charter->sprite->sprite);
        sfSprite_setPosition(game->charter->sprite->sprite,
            (sfVector2f){1920 / 2 - 100 + 80 + game->charter->exep[0],
                game->charter->exep[1] + 1080 / 2 - 70 - 20});
    }
    if (game->charter->rota == 2) {
        pos = sfSprite_getPosition(game->charter->sprite->sprite);
        sfSprite_setPosition(game->charter->sprite->sprite,
            (sfVector2f){1920 / 2 - 100 + 90 + game->charter->exep[0],
                game->charter->exep[1] + 1080 / 2 - 70 + 60});
    }
    if (game->charter->rota == 3) {
        pos = sfSprite_getPosition(game->charter->sprite->sprite);
        sfSprite_setPosition(game->charter->sprite->sprite,
            (sfVector2f){1920 / 2 - 100 + game->charter->exep[0],
                game->charter->exep[1] + 1080 / 2 - 70 + 75});
    }
}

void update_map(map_t *map, sfRenderWindow *window, game_t *game)
{
    int type = 0;

    if (map->pos[0] < 7 && map->pos[1] < 11 && map->pos[0] > -1
        && map->pos[1] > -1
        && !((game->map->pos[1] == 10 && game->input == 'q')
            || (game->map->pos[1] == 0 && game->input == 'd')
            || (game->map->pos[0] == 6 && game->input == 'z')
            || (game->map->pos[0] == 0 && game->input == 's')))
        move_map(map, window, game);
    else {
        type = give_type(game);
        if (type == 3)
            return move_static_charter(game, window);
        if (type == 1)
            return move_map_vert(map, window, game);
        if (type == 2)
            return move_map_hor(map, window, game);
    }
}
