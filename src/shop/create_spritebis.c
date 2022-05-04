/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "SFML/Graphics.h"
#include "stdlib.h"

char *itoa(int nbr)
{
    char *str = malloc(sizeof(char) * 5);
    int i = 0;
    while (nbr >= 10) {
        str[i] = (char) ((nbr % 10) + '0');
        nbr = nbr / 10;
        i += 1;
    }
    str[i] = (char) (nbr + '0');
    str[i + 1] = '\0';
    return my_revstr(str);
}

void create_sprite_text(shop_t *shop)
{
    float pos[2] = {210, 370};
    sfFont *font = sfFont_createFromFile("fonts/pixelart.TTF");
    char *str;
    shop->text = malloc(sizeof(text_shop) * 10);

    for (int i = 0; i != 10; i++) {
        shop->text[i].text = sfText_create();
        sfVector2f place = (sfVector2f){pos[0], pos[1]};
        str = itoa(shop->items_shop[i].prize);
        sfText_setString(shop->text[i].text, str);
        sfText_setFont(shop->text[i].text, font);
        sfText_setCharacterSize(shop->text[i].text, 24);
        sfText_setPosition(shop->text[i].text, place);
        pos[0] += 384;
        if (i == 4) {
            pos[1] = 800;
            pos[0] = 210;
        }
    }
}

void initial_shop(inv_shop *item_shop, char *name, int prize, int place)
{
    item_shop->place = place;
    item_shop->prize = prize;
    item_shop->name = name;
}

void make_shop(shop_t *shop)
{
    shop->items_shop = malloc(sizeof(inv_shop) * 10);
    initial_shop(&shop->items_shop[0], "casque de linitier", 80, 1);
    initial_shop(&shop->items_shop[1], "armure de linitier", 150, 2);
    initial_shop(&shop->items_shop[2], "jambiere de linitier", 80, 3);
    initial_shop(&shop->items_shop[3], "epee de linitier", 80, 4);
    initial_shop(&shop->items_shop[4], "gants de linitier", 80, 5);
    initial_shop(&shop->items_shop[5], "collier de linitier", 80, 6);
    initial_shop(&shop->items_shop[6], "epaulettes de linitier", 80, 7);
    initial_shop(&shop->items_shop[7], "bottes de linitier", 80, 8);
    initial_shop(&shop->items_shop[8], "potion", 20, 9);
    initial_shop(&shop->items_shop[9], "antidote", 30, 10);
}

void create_sprite_coins(shop_t *shop)
{
    float pos[2] = {258, 370};

    shop->coins = malloc(sizeof(sprite_t) * 10);
    sfTexture *texture =
        sfTexture_createFromFile("sprites/shop/coins.png", NULL);
    for (int i = 0; i != 10; i++) {
        sfVector2f place = (sfVector2f){pos[0], pos[1]};
        sfVector2f scale = (sfVector2f){0.08, 0.08};
        sfIntRect rect = (sfIntRect){250, 100, 380, 380};
        shop->coins[i].sprite = sfSprite_create();
        sfSprite_setTexture(shop->coins[i].sprite, texture, sfTrue);
        sfSprite_setTextureRect(shop->coins[i].sprite, rect);
        sfSprite_setPosition(shop->coins[i].sprite, place);
        sfSprite_setScale(shop->coins[i].sprite, scale);
        pos[0] += 384;
        if (i == 4) {
            pos[1] = 800;
            pos[0] = 258;
        }
    }
}
