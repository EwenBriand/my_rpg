/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event_the_end
*/

#include "my.h"

void event_the_end(sfRenderWindow *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->state = 1;
            sfRenderWindow_close(window);
        }
    }
}
