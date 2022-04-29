/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** display.c
*/

#include "../../include/my.h"
#include "SFML/Graphics.h"

void check_buy(sfRenderWindow *window, shop_t *shop, const int nbrs[5], int *credits)
{
    sfEvent event;
    sfRenderWindow_pollEvent(window, &event);
    sfVector2i mouse = shop->posi_mouse;
    shop->clock2.time = sfClock_getElapsedTime(shop->clock2.clock);
    shop->seconds2 = (double) shop->clock2.time.microseconds / 1000000.0;
    if (mouse.x >= nbrs[1] && mouse.x <= nbrs[2] && mouse.y >= nbrs[3] &&
    mouse.y <= nbrs[4] && event.type == sfEvtMouseButtonPressed) {
        if (shop->seconds2 > 1) {
            *credits -= shop->items_shop[nbrs[0]].prize;
        }
    }
}

void check_money(sfRenderWindow *window, shop_t *shop, int *credits, int nbrs[5])
{
    nbrs[3] += 100;
    if (shop->items_shop[nbrs[0]].prize <= *credits) {
        display_color(window, shop, shop->green[nbrs[0]], nbrs[0]);
        check_buy(window, shop, nbrs, credits);
    } else
        display_color(window, shop, shop->red[nbrs[0]], nbrs[0]);
}

void display_button(sfRenderWindow *window, sfVector2i mouse, shop_t *shop, int *credits)
{
    int nbrs[5] = {0, 192, 287, 270, 400};

    for (; nbrs[0] != 10; nbrs[0]++) {
        if (mouse.x >= nbrs[1] && mouse.x <= nbrs[2] && mouse.y >= nbrs[3] &&
        mouse.y <= nbrs[4])
            check_money(window, shop, credits, nbrs);
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