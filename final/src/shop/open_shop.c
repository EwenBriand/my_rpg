/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** open_shop
*/

#include "../../include/my.h"
#include <SFML/Graphics.h>

void display_color(sfRenderWindow *window, shop_t *shop, sprite_t color, int i)
{
    sfRenderWindow_drawSprite(window, color.sprite, NULL);
    sfRenderWindow_drawSprite(window, shop->coins[i].sprite, NULL);
    sfRenderWindow_drawText(window, shop->text[i].text, NULL);
}

void check_close(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
    }
}

void open_shop(sfRenderWindow *window, game_t *game)
{
    //sfClock_restart(game->shop.clock1.clock);
    game->shop.posi_mouse = sfMouse_getPositionRenderWindow(window);
    sfRenderWindow_drawSprite(window, game->shop.back.sprite, NULL);
    for (int i = 0; i != 10; i++) {
        sfRenderWindow_drawSprite(window, game->shop.items[i].sprite, NULL);
        display_color(window, &game->shop, game->shop.grey[i], i);
    }
    display_button(window, game->shop.posi_mouse, &game->shop, &game->perso->credits);
    check_close(window);
    game->shop.clock1.time = sfClock_getElapsedTime(game->shop.clock1.clock);
    game->shop.seconds1 = (double) game->shop.clock1.time.microseconds / 1000000.0;
    if (sfKeyboard_isKeyPressed(sfKeyE) && game->shop.seconds1 > 1) {
        game->state = 0;
        sfClock_restart(game->shop.clock1.clock);
    }
}
