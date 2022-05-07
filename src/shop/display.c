/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** display.c
*/

#include "../../include/my.h"
#include "SFML/Graphics.h"

static void auto_equiped_sec(game_t *game, shop_t *shop, int nbr)
{
    if (my_strcmp(shop->items_shop[nbr].name, "epaulettes de linitier") == 0) {
        game->perso->equip->shoulder = game->all_objets[3];
        del_object_in_inv(game, shop->items_shop[nbr].name, 1);
    }
    if (my_strcmp(shop->items_shop[nbr].name, "jambiere de linitier") == 0) {
        game->perso->equip->leg = game->all_objets[8];
        del_object_in_inv(game, shop->items_shop[nbr].name, 1);
    }
    if (my_strcmp(shop->items_shop[nbr].name, "bottes de linitier") == 0) {
        game->perso->equip->foot = game->all_objets[7];
        del_object_in_inv(game, shop->items_shop[nbr].name, 1);
    }
    if (my_strcmp(shop->items_shop[nbr].name, "collier de linitier") == 0) {
        game->perso->equip->neck = game->all_objets[10];
        del_object_in_inv(game, shop->items_shop[nbr].name, 1);
    }
}

static void auto_equiped(game_t *game, shop_t *shop, int nbr)
{
    if (my_strcmp(shop->items_shop[nbr].name, "epee de linitier") == 0) {
        game->perso->equip->weapon = game->all_objets[3];
        del_object_in_inv(game, shop->items_shop[nbr].name, 1);
    }
    if (my_strcmp(shop->items_shop[nbr].name, "casque de linitier") == 0) {
        game->perso->equip->head = game->all_objets[5];
        del_object_in_inv(game, shop->items_shop[nbr].name, 1);
    }
    if (my_strcmp(shop->items_shop[nbr].name, "armure de linitier") == 0) {
        game->perso->equip->body = game->all_objets[4];
        del_object_in_inv(game, shop->items_shop[nbr].name, 1);
    }
    if (my_strcmp(shop->items_shop[nbr].name, "gants de linitier") == 0) {
        game->perso->equip->gauntlet = game->all_objets[6];
        del_object_in_inv(game, shop->items_shop[nbr].name, 1);
    }
    auto_equiped_sec(game, shop, nbr);
}

void check_buy(
    sfRenderWindow *window, shop_t *shop, const int nbrs[5], game_t *game)
{
    sfEvent event;
    sfRenderWindow_pollEvent(window, &event);
    sfVector2i mouse = shop->posi_mouse;
    shop->clock2.time = sfClock_getElapsedTime(shop->clock2.clock);
    shop->seconds2 = (double) shop->clock2.time.microseconds / 1000000.0;
    if (mouse.x >= nbrs[1] && mouse.x <= nbrs[2] && mouse.y >= nbrs[3]
        && mouse.y <= nbrs[4] && event.type == sfEvtMouseButtonPressed) {
        if (shop->seconds2 > 1) {
            game->perso->credits -= shop->items_shop[nbrs[0]].prize;
            add_object_in_inv(game, shop->items_shop[nbrs[0]].name, 1);
            auto_equiped(game, shop, nbrs[0]);
        }
    }
}

void check_money(
    sfRenderWindow *window, shop_t *shop, game_t *game, int nbrs[5])
{
    nbrs[3] += 100;
    if (shop->items_shop[nbrs[0]].prize <= game->perso->credits) {
        display_color(window, shop, shop->green[nbrs[0]], nbrs[0]);
        check_buy(window, shop, nbrs, game);
    } else
        display_color(window, shop, shop->red[nbrs[0]], nbrs[0]);
}

void display_button(
    sfRenderWindow *window, sfVector2i mouse, shop_t *shop, game_t *game)
{
    int nbrs[5] = {0, 192, 287, 270, 400};

    for (; nbrs[0] != 10; nbrs[0]++) {
        if (mouse.x >= nbrs[1] && mouse.x <= nbrs[2] && mouse.y >= nbrs[3]
            && mouse.y <= nbrs[4])
            check_money(window, shop, game, nbrs);
        nbrs[1] += 384;
        nbrs[2] += 384;
        if (nbrs[0] == 4) {
            nbrs[3] = 700;
            nbrs[4] = 830;
            nbrs[1] = 192;
            nbrs[2] = 287;
        }
    }
}
