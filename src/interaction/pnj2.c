/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pnj2
*/

#include "../../include/my.h"
#include "SFML/Audio.h"
#include "SFML/Graphics.h"

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
    if (game->all_pnj[1]->avancement == game->all_pnj[1]->finish - 1) {
        game->state = 0;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, game->the_end->sprite, NULL);
        sfRenderWindow_display(window);
        while (game->state != 1)
            event_the_end(window, game);
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
        sfMusic_play(game->quest_complete_sound);
    }
    if (game->all_pnj[1]->avancement == 3) {
        while_loop_pnj2(window, game);
        ++game->all_pnj[1]->avancement;
        game->state = 3;
        sfMusic_stop(game->quest_complete_sound);
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
        sfMusic_play(game->quest_complete_sound);
    }
    if (game->all_pnj[1]->avancement == 1) {
        while_loop_pnj2(window, game);
        ++game->all_pnj[1]->avancement;
        game->state = 3;
        sfMusic_stop(game->quest_complete_sound);
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
        sfMusic_play(game->quest_complete_sound);
    }

    while_loop_pnj2(window, game);
    sfMusic_stop(game->quest_complete_sound);
}
