/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event_pnj
*/

#include "../../include/my.h"
#include "SFML/Graphics.h"

void event_pnj_scene(sfRenderWindow *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            game->state = 1;
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace) {
            game->state = 0;
        }
    }
}
