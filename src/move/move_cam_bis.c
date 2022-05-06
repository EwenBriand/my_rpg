/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** move_cam_bis
*/

#include "../../include/my.h"
#include "stdlib.h"
#include "SFML/Graphics.h"

void change_charter_four(game_t *game, int type)
{
    if (type == 6) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(50, 100, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
                game->charter->sprite->image, game->charter->sprite->rect);
        sfSprite_setTexture(game->charter->sprite->sprite,
                            game->charter->sprite->texture, sfTrue);
    }
    if (type == 7) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(50, 150, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
                game->charter->sprite->image, game->charter->sprite->rect);
        sfSprite_setTexture(game->charter->sprite->sprite,
                            game->charter->sprite->texture, sfTrue);
    }
}

void change_charter_tree(game_t *game, int type)
{
    if (type == 4) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(50, 0, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
                game->charter->sprite->image, game->charter->sprite->rect);
        sfSprite_setTexture(game->charter->sprite->sprite,
                            game->charter->sprite->texture, sfTrue);
    } else if (type == 5) {
        free((sfIntRect *) game->charter->sprite->rect);
        sfTexture_destroy(game->charter->sprite->texture);
        game->charter->sprite->rect = create_rect(50, 50, 50, 50);
        game->charter->sprite->texture = sfTexture_createFromImage(
                game->charter->sprite->image, game->charter->sprite->rect);
        sfSprite_setTexture(game->charter->sprite->sprite,
                            game->charter->sprite->texture, sfTrue);
    } else
        change_charter_four(game, type);
}

void move_map_bis(map_t *map, int *old_pos, int x)
{
    if (x != 1) {
        if (old_pos[0] < map->pos[0] * 100)
            old_pos[0] += 1;
        if (old_pos[0] > map->pos[0] * 100)
            old_pos[0] -= 1;
    }
    if (x != 0) {
        if (old_pos[1] < map->pos[1] * 100)
            old_pos[1] += 1;
        if (old_pos[1] > map->pos[1] * 100)
            old_pos[1] -= 1;
    }
}

int move_map_tree(int type)
{
    if (type == 8)
        return 0;
    else
        return type;
}

void move_map_four(int *nb, int *sec, map_t *map, int *old_pos)
{
    if (nb[0] < 1 * *sec) {
        sfTexture_destroy(map->background->texture);
        if (nb[1] != 1)
            map->background->rect->top = old_pos[0];
        if (nb[1] != 0)
            map->background->rect->left = old_pos[1];
        map->background->texture = sfTexture_createFromImage(
                map->background->image, map->background->rect);
        sfSprite_setTexture(
                map->background->sprite, map->background->texture, sfTrue);
    } else if (nb[0] >= 1 * *sec) {
        move_map_bis(map,  old_pos, nb[1]);
        ++*sec;
    }
}
