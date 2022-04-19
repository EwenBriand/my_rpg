/*
** EPITECH PROJECT, 2022
** ewen
** File description:
** init_my_game
*/

#include "my.h"

sfIntRect *create_rect(int top, int left, int width, int height)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = top;
    rect->left = left;
    rect->width = width;
    rect->height = height;
    return (rect);
}

sprite_t *create_sprite(
    sfRenderWindow *window, char *path, int *p, int *position)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfImage *image = sfImage_createFromFile(path);
    const sfIntRect *pos = create_rect(p[0], p[1], p[2], p[3]);
    sfTexture *texture = sfTexture_createFromImage(image, pos);

    sprite->sprite = sfSprite_create();
    sprite->texture = texture;
    sprite->rect = pos;
    sprite->image = image;
    sfSprite_setTexture(sprite->sprite, texture, sfTrue);
    sfSprite_setPosition(
        sprite->sprite, (sfVector2f){position[0], position[1]});
    return (sprite);
}

map_t *create_map(sfRenderWindow *window, char *path, int *pos)
{
    map_t *map = malloc(sizeof(map_t));

    map->pos = malloc(sizeof(int) * 2);
    map->scale = 2;
    map->pos[0] = 0;
    map->pos[1] = 0;
    map->background = create_sprite(window, "maps/city1.png", pos, pos);
    map->size_x = 14;
    map->size_y = 8;

    sfSprite_setScale(
        map->background->sprite, (sfVector2f){map->scale, map->scale});
    return (map);
}

charter_t *create_charter(sfRenderWindow *window, char *path, int *pos)
{
    charter_t *charter = malloc(sizeof(charter_t));

    int *ok = malloc(sizeof(int) * 2);
    ok[0] = 1920 / 2 - 100;
    ok[1] = 1080 / 2 - 70;
    charter->pos = malloc(sizeof(int) * 2);
    charter->exep = malloc(sizeof(int) * 2);
    charter->pos[0] = 2;
    charter->pos[1] = 4;
    charter->exep[0] = 0;
    charter->exep[1] = 0;
    charter->scale = 2;
    pos[2] = 50;
    pos[3] = 50;
    charter->sprite = create_sprite(window, path, pos, ok);

    sfSprite_setScale(
        charter->sprite->sprite, (sfVector2f){charter->scale, charter->scale});
    return (charter);
}

game_t *creat_my_game(sfRenderWindow *window)
{
    game_t *game = malloc(sizeof(game_t));
    int *pos = malloc(sizeof(int) * 4);
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 1920;
    pos[3] = 1080;
    game->map = create_map(window, "maps/city1.png", pos);
    pos[2] = 1920 / 100 - 1;
    pos[3] = 1080 / 100 - 1;
    game->charter = create_charter(window, "sprites/charter.png", pos);
    game->state = 0;
    return (game);
}
