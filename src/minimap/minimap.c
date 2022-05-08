/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** minimap
*/

#include "my.h"

static void event_minimap(sfRenderWindow *window, int *status)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(window);
            *status = 1;
        } else if (event.type == sfEvtKeyReleased
            && event.key.code == sfKeySpace)
            *status = 1;
    }
}

void open_minimap(sfRenderWindow *window, game_t *game)
{
    int status = 0;

    sfRenderWindow_clear(window, sfBlack);
    if (game->minimap->which_map == 0)
        sfRenderWindow_drawSprite(window, game->minimap->map1->sprite, NULL);
    else
        sfRenderWindow_drawSprite(window, game->minimap->map2->sprite, NULL);
    sfRenderWindow_display(window);
    while (status == 0 && sfRenderWindow_isOpen(window))
        event_minimap(window, &status);
}
