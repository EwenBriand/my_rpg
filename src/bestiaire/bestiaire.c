/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** bestiare
*/

#include <stdlib.h>
#include "my.h"

static void event_best(sfRenderWindow *window, int *status)
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

void open_bestiaire(sfRenderWindow *window, game_t *game)
{
    int status = 0;

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->best->back->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->best->enemy1->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->best->enemy2->sprite, NULL);
    sfRenderWindow_drawText(window, game->best->stat_enemy, NULL);
    sfRenderWindow_display(window);
    while (status == 0 && sfRenderWindow_isOpen(window))
        event_best(window, &status);
}
