/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pnj3
*/

#include "my.h"

static void while_loop_pnj3(sfRenderWindow *window, game_t *game)
{
    sfText_setString(game->pnj_scene->name, game->all_pnj[2]->name);
    sfText_setString(game->pnj_scene->replique,
        game->all_pnj[2]->replique[game->all_pnj[2]->avancement]);
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

static int full_equiped(game_t *game)
{
    if (game->perso->equip->head == NULL || game->perso->equip->body == NULL
        || game->perso->equip->leg == NULL
        || game->perso->equip->weapon == NULL
        || game->perso->equip->gauntlet == NULL
        || game->perso->equip->foot == NULL
        || game->perso->equip->shoulder == NULL
        || game->perso->equip->neck == NULL)
        return 1;
    return 0;
}

void interaction_pnj3(sfRenderWindow *window, game_t *game)
{
    game->state = 3;

    if (game->all_pnj[2]->avancement == 0 && full_equiped(game) == 0) {
        ++game->all_pnj[2]->avancement;
        game->perso->credits += game->all_pnj[2]->credits;
        game->perso->xp += game->all_pnj[2]->xp;
        sfMusic_play(game->quest_complete_sound);
    }
    while_loop_pnj3(window, game);
    sfMusic_stop(game->quest_complete_sound);
}
