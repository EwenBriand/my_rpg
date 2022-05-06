/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** open_chest
*/

#include "my.h"

static void while_loop_chest(sfRenderWindow *window, game_t *game)
{
    while (game->state == 3) {
        draw_map(window, game);
        sfRenderWindow_drawSprite(
            window, game->pnj_scene->textbox->sprite, NULL);
        sfRenderWindow_drawText(window, game->pnj_scene->name, NULL);
        sfRenderWindow_drawText(window, game->pnj_scene->replique, NULL);
        sfRenderWindow_display(window);
        event_pnj_scene(window, game);
    }
}

void open_chest(sfRenderWindow *window, game_t *game)
{
    game->state = 3;
    if (game->chest == 0) {
        add_object_in_inv(game, "faux", 1);
        ++game->chest;
        sfText_setString(game->pnj_scene->name, "Chester");
        sfText_setString(game->pnj_scene->replique, "You find an old scythe");
    } else {
        sfText_setString(game->pnj_scene->name, "Chester");
        sfText_setString(game->pnj_scene->replique, "This chest is open");
    }
    while_loop_chest(window, game);
}
