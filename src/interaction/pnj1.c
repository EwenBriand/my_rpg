/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pnj1
*/

#include "../../include/my.h"
#include "SFML/Audio.h"
#include "SFML/Graphics.h"

static void while_loop_pnj1(sfRenderWindow *window, game_t *game)
{
    sfText_setString(game->pnj_scene->name, game->all_pnj[0]->name);
    sfText_setString(game->pnj_scene->replique,
        game->all_pnj[0]->replique[game->all_pnj[0]->avancement]);
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

void interaction_pnj1(sfRenderWindow *window, game_t *game)
{
    game->state = 3;

    if (game->all_pnj[0]->avancement == 0
        && is_in_inv(game, game->all_pnj[0]->obj, game->all_pnj[0]->nb_obj)
            != -1) {
        del_object_in_inv(
            game, game->all_pnj[0]->obj, game->all_pnj[0]->nb_obj);
        ++game->all_pnj[0]->avancement;
        game->perso->credits += game->all_pnj[0]->credits;
        game->perso->xp += game->all_pnj[0]->xp;
        sfMusic_play(game->quest_complete_sound);
    }
    while_loop_pnj1(window, game);
    sfMusic_stop(game->quest_complete_sound);
}
