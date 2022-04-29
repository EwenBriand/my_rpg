/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_shop
*/

#include "stdlib.h"
#include "SFML/Graphics.h"
#include "../../include/struct.h"
#include "../../include/my.h"

void create_sprite_items(sprite_t *items, int i, const float *pos, const int *rect)
{
    sfTexture *texture = sfTexture_createFromFile("sprites/shop/items.png",
                                                  NULL);
    sfVector2f place = (sfVector2f) {pos[0], pos[1]};
    sfIntRect rectangle = (sfIntRect) {rect[0], rect[1], 95, 95};
    items[i].sprite = sfSprite_create();
    sfSprite_setTexture(items[i].sprite, texture, sfTrue);
    sfSprite_setTextureRect(items[i].sprite, rectangle);
    sfSprite_setPosition(items[i].sprite, place);
}

void create_sprite_shop(shop_t *shop)
{
    float pos[2] = {192, 270};
    int rect[][2] = {{380, 480}, {96, 675}, {288, 578}, {0, 0}, {480, 672},
                     {288, 385}, {192, 675}, {97, 580}, {480, 288},
                     {672, 288}};

    sfVector2f scale = (sfVector2f) {5, 3};
    sfTexture *texture = sfTexture_createFromFile("sprites/shop/back.jpg", NULL);
    shop->back.sprite = sfSprite_create();
    sfSprite_setTexture(shop->back.sprite, texture, sfTrue);
    sfSprite_setScale(shop->back.sprite, scale);
    shop->items = malloc(sizeof (sprite_t) * 10);
    for (int i = 0; i != 10; i++) {
        create_sprite_items(shop->items, i, pos, rect[i]);
        pos[0] += 384;
        if (i == 4) {
            pos[1] = 700;
            pos[0] = 192;
        }
    }
}

void create_sprite_color(sprite_t *sprite, sfTexture *texture)
{
    float pos[2] = {192, 370};

    for (int i = 0; i != 10; i++) {
        sfVector2f place = (sfVector2f) {pos[0], pos[1]};
        sfIntRect rect = (sfIntRect) {0, 0, 95, 30};
        sprite[i].sprite = sfSprite_create();
        sfSprite_setTexture(sprite[i].sprite, texture, sfTrue);
        sfSprite_setTextureRect(sprite[i].sprite, rect);
        sfSprite_setPosition(sprite[i].sprite, place);
        pos[0] += 384;
        if (i == 4) {
            pos[1] = 800;
            pos[0] = 192;
        }
    }
}

void create_sprite_prize(shop_t *shop)
{
    shop->grey = malloc(sizeof (sprite_t) * 10);
    shop->green = malloc(sizeof (sprite_t) * 10);
    shop->red = malloc(sizeof (sprite_t) * 10);
    shop->grey->texture = sfTexture_createFromFile("sprites/shop/back_grey.jpg",
                                                   NULL);
    shop->green->texture = sfTexture_createFromFile(
            "sprites/shop/back_green.jpg",NULL);
    shop->red->texture = sfTexture_createFromFile("sprites/shop/back_red.jpg",
                                                   NULL);
    create_sprite_color(shop->grey, shop->grey->texture);
    create_sprite_color(shop->green, shop->green->texture);
    create_sprite_color(shop->red, shop->red->texture);
    create_sprite_coins(shop);
}

void init_shop(game_t *game)
{
    create_sprite_shop(&game->shop);
    create_sprite_prize(&game->shop);
    make_shop(&game->shop);
    create_sprite_text(&game->shop);
}