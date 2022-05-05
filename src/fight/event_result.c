/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event_result
*/

#include "my.h"

void event_fight_result(sfRenderWindow *window, game_t *game, int *status)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            *status = 1;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            pause_menu(window, game);
    }
}
