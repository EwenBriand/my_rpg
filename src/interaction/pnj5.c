/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pnj4
*/

#include "../../include/my.h"
#include "SFML/Graphics.h"
#include "SFML/Audio.h"

static void while_loop_pnj5(sfRenderWindow *window, game_t *game)
{
    sfText_setString(game->pnj_scene->name, game->all_pnj[4]->name);
    sfText_setString(game->pnj_scene->replique,
        game->all_pnj[4]->replique[game->all_pnj[4]->avancement]);
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

void interaction_pnj5(sfRenderWindow *window, game_t *game)
{
    game->state = 3;

    if (game->all_pnj[4]->avancement == 0
        && is_in_inv(game, game->all_pnj[4]->obj, game->all_pnj[4]->nb_obj)
            != -1) {
        del_object_in_inv(
            game, game->all_pnj[4]->obj, game->all_pnj[4]->nb_obj);
        ++game->all_pnj[4]->avancement;
        game->perso->credits += game->all_pnj[4]->credits;
        game->perso->xp += game->all_pnj[4]->xp;
        sfMusic_play(game->quest_complete_sound);
    }
    while_loop_pnj5(window, game);
    sfMusic_stop(game->quest_complete_sound);
}
