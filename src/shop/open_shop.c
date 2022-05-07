/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** open_shop
*/

#include <SFML/Graphics.h>
#include "../../include/my.h"

void display_color(sfRenderWindow *window, shop_t *shop, sprite_t color, int i)
{
    sfRenderWindow_drawSprite(window, color.sprite, NULL);
    sfRenderWindow_drawSprite(window, shop->coins[i].sprite, NULL);
    sfRenderWindow_drawText(window, shop->text[i].text, NULL);
}

void check_close(sfRenderWindow *window, game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            pause_menu(window, game);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            game->state = 0;
    }
}

void open_shop(sfRenderWindow *window, game_t *game)
{
    game->shop.posi_mouse = sfMouse_getPositionRenderWindow(window);
    sfRenderWindow_drawSprite(window, game->shop.back.sprite, NULL);
    for (int i = 0; i != 10; i++) {
        sfRenderWindow_drawSprite(window, game->shop.items[i].sprite, NULL);
        display_color(window, &game->shop, game->shop.grey[i], i);
    }
    display_button(window, game->shop.posi_mouse, &game->shop, game);
    check_close(window, game);
}
