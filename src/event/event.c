/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** event
*/

#include "../../include/my.h"
#include "SFML/Graphics.h"

static int is_compatible(game_t *game, int y, int x)
{
    int pos_act = game->map->map[game->charter->pos[0]][game->charter->pos[1]];
    int pos_new =
        game->map->map[game->charter->pos[0] + y][game->charter->pos[1] + x];

    if ((pos_act == 3 || pos_act == 4 || pos_act == 5 || pos_act == 10
            || pos_act == 13 || pos_act == 14 || pos_act == 2)
        && (pos_new == 6 || pos_new == 7 || pos_new == 8 || pos_new == 9
            || pos_new == 0 || pos_new == 12 || pos_new == 1))
        return (1);
    else if ((pos_act == 1 || pos_act == 6 || pos_act == 7 || pos_act == 8
            || pos_act == 9 || pos_act == 0 || pos_act == 12)
        && (pos_new == 3 || pos_new == 4 || pos_new == 5 || pos_new == 10
            || pos_new == 13 || pos_new == 14 || pos_new == 2))
        return (1);
    return (0);
}

static void move_vertical(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyD && game->map->pos[1] < game->map->size_x
        && is_compatible(game, 0, 1) == 0) {
        ++game->map->pos[1];
        game->state = 2;
        game->charter->rota = 3;
        ++game->charter->pos[1];
        game->input = 'd';
    }
    if (event.key.code == sfKeyQ && game->map->pos[1] > -4
        && is_compatible(game, 0, -1) == 0) {
        --game->map->pos[1];
        game->state = 2;
        game->charter->rota = 1;
        --game->charter->pos[1];
        game->input = 'q';
    }
}

static void move_horizontal(game_t *game, sfEvent event)
{
    if (event.key.code == 18 && game->map->pos[0] < game->map->size_y
        && is_compatible(game, 1, 0) == 0) {
        ++game->map->pos[0];
        game->state = 2;
        game->charter->rota = 0;
        ++game->charter->pos[0];
        game->input = 's';
    }

    if (event.key.code == 25 && game->map->pos[0] > -2
        && is_compatible(game, -1, 0) == 0) {
        --game->map->pos[0];
        game->state = 2;
        game->charter->rota = 2;
        --game->charter->pos[0];
        game->input = 'z';
    }
}

void my_event(sfRenderWindow *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            game->state = 1;
        if (event.type == sfEvtKeyReleased) {
            move_vertical(game, event);
            move_horizontal(game, event);
            interaction(window, game, event);
            if (event.key.code == sfKeyF) { // a degager a la fin
                add_object_in_inv(game, "faux", 1);
                game->all_pnj[1]->nb_obj = 5;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            pause_menu(window, game);
    }
}
