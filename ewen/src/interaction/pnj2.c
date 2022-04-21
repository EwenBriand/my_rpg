/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pnj2
*/

#include "my.h"

static void while_loop_pnj2(sfRenderWindow *window, game_t *game)
{
    sfText_setString(game->pnj_scene->name, game->all_pnj[1]->name);
    sfText_setString(game->pnj_scene->replique,
        game->all_pnj[1]->replique[game->all_pnj[1]->avancement]);
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

static void sec_quest(sfRenderWindow *window, game_t *game)
{
    if (game->all_pnj[1]->avancement == 2 && game->all_pnj[1]->nb_obj >= 5) {
        ++game->all_pnj[1]->avancement;
        game->perso->credits += game->all_pnj[1]->credits;
        game->perso->xp += game->all_pnj[1]->xp;
        game->all_pnj[1]->nb_obj = 1;
        game->all_pnj[1]->obj = "faux";
        game->all_pnj[1]->type = 0;
    }
    if (game->all_pnj[1]->avancement == 3) {
        while_loop_pnj2(window, game);
        ++game->all_pnj[1]->avancement;
        game->state = 3;
    }
}

static void first_quest(sfRenderWindow *window, game_t *game)
{
    if (game->all_pnj[1]->avancement == 0
        && is_in_inv(game, game->all_pnj[1]->obj, game->all_pnj[1]->nb_obj)
            != -1) {
        del_object_in_inv(
            game, game->all_pnj[1]->obj, game->all_pnj[1]->nb_obj);
        ++game->all_pnj[1]->avancement;
        game->perso->credits += game->all_pnj[1]->credits;
        game->perso->xp += game->all_pnj[1]->xp;
        game->all_pnj[1]->nb_obj = 0;
        game->all_pnj[1]->type = 1;
    }
    if (game->all_pnj[1]->avancement == 1) {
        while_loop_pnj2(window, game);
        ++game->all_pnj[1]->avancement;
        game->state = 3;
    }
}
void interaction_pnj2(sfRenderWindow *window, game_t *game)
{
    game->state = 3;

    first_quest(window, game);
    sec_quest(window, game);
    if (game->all_pnj[1]->avancement == 4
        && is_in_inv(game, game->all_pnj[1]->obj, game->all_pnj[1]->nb_obj)
            != -1) {
        del_object_in_inv(
            game, game->all_pnj[1]->obj, game->all_pnj[1]->nb_obj);
        ++game->all_pnj[1]->avancement;
        game->perso->credits += game->all_pnj[1]->credits;
        game->perso->xp += game->all_pnj[1]->xp;
    }

    while_loop_pnj2(window, game);
}
