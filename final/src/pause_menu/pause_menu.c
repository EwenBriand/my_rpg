/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pause_menu
*/

#include "my.h"

static void key_pressed(game_t *game, sfEvent event, int *status)
{
    if (event.key.code == sfKeyEscape) {
        *status = 1;
        game->state = 1;
    }
    if (event.key.code == sfKeyEnter)
        *status = 1;
}

static void mouse_click(game_t *game, sfEvent event, int *status)
{
    sfVector2f pos_m = sfSprite_getPosition(game->resume_btn->sprite);
    sfVector2f pos_q = sfSprite_getPosition(game->quit_btn->sprite);

    if (event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x >= pos_m.x
            && event.mouseButton.x <= pos_m.x + 200
            && event.mouseButton.y >= pos_m.y
            && event.mouseButton.y <= pos_m.y + 200) {
            *status = 1;
        } else if (event.mouseButton.x >= pos_q.x
            && event.mouseButton.x <= pos_q.x + 200
            && event.mouseButton.y >= pos_q.y
            && event.mouseButton.y <= pos_q.y + 200) {
            *status = 1;
            game->state = 1;
        }
    }
}

static void event_pause_menu(sfRenderWindow *window, game_t *game, int *status)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            game->state = 1;
            *status = 1;
        } else if (event.type == sfEvtKeyPressed)
            key_pressed(game, event, status);
        if (event.type == sfEvtMouseButtonPressed)
            mouse_click(game, event, status);
    }
}

void pause_menu(sfRenderWindow *window, game_t *game)
{
    int status = 0;

    while (sfRenderWindow_isOpen(window) && status == 0) {
        draw_map(window, game);
        sfRenderWindow_drawSprite(window, game->resume_btn->sprite, NULL);
        sfRenderWindow_drawSprite(window, game->quit_btn->sprite, NULL);
        sfRenderWindow_display(window);
        event_pause_menu(window, game, &status);
    }
}
