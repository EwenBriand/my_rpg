/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** util_inv
*/

#include "../../include/my.h"
#include "SFML/Graphics.h"
#include "string.h"


void display_inv_tree(int display, objet_t *objet, game_t *game,
                        sfSprite *sprite)
{
    if (my_strcmp(objet->name, "potion") == 0) {
        sprite = game->shop.items[8].sprite;
        display = 2;
    }
    if (my_strcmp(objet->name, "antidote") == 0) {
        sprite = game->shop.items[9].sprite;
        display = 2;
    }
    if (my_strcmp(objet->name, "baie") == 0) {
        sprite = game->shop.items[10].sprite;
        display = 2;
    }
    if (my_strcmp(objet->name, "bois") == 0) {
        sprite = game->shop.items[11].sprite;
        display = 2;
    }
}

void display2(sfSprite *sprite, int *nbr, game_t *game, sfRenderWindow *window)
{
    sfVector2f place3 = sfSprite_getPosition(sprite);

    if (nbr[0] == 2) {
        sfSprite_setPosition(sprite, game->place_inv);
        sfText_setString(game->text_inv, itoa(
                game->perso->inv->inv[nbr[1]]->stack));
        sfText_setPosition(game->text_inv, (sfVector2f) {
                game->place_inv.x + 30, game->place_inv.y + 120});
        sfRenderWindow_drawText(window, game->text_inv, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfSprite_setPosition(sprite, place3);
        game->place_inv.x += 219;
        nbr[0] = 0;
    }
}

void display1(sfSprite *sprite, sfRenderWindow *window, int *nbr, sfVector2f *place1)
{
    sfVector2f place3 = sfSprite_getPosition(sprite);

    if (nbr[0] == 1) {
        sfSprite_setPosition(sprite, *place1);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfSprite_setPosition(sprite, place3);
        place1->x += 170;
        nbr[0] = 0;
    }
}

void create_sprite_inv(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile("sprites/shop/items.png",
                        NULL);
    sfVector2f place = (sfVector2f){0, 0};
    sfIntRect rectangle = (sfIntRect){0, 760, 95, 95};
    sfVector2f scale = (sfVector2f) {0.1, 0.1};

    game->shop.items[10].sprite = sfSprite_create();
    sfSprite_setTexture(game->shop.items[10].sprite, texture, sfTrue);
    sfSprite_setTextureRect(game->shop.items[10].sprite, rectangle);
    sfSprite_setPosition(game->shop.items[10].sprite, place);
    texture = sfTexture_createFromFile("sprites/shop/bois.jpg", NULL);
    game->shop.items[11].sprite = sfSprite_create();
    sfSprite_setTexture(game->shop.items[11].sprite, texture, sfTrue);
    sfSprite_setScale(game->shop.items[11].sprite, scale);
    sfSprite_setPosition(game->shop.items[11].sprite, place);
}
