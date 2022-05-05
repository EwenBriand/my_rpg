/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** draw_fight
*/

#include "my.h"

void draw_fight_scene(sfRenderWindow *window, game_t *game)
{
    char *pv_perso =
        my_strcat("HP PLAYER  ", my_int_to_str(game->perso->stat->pv));
    char *pv_ennemi = my_strcat("HP ENEMY  ",
        my_int_to_str(game->fight->enemy[game->mobs]->stats->pv));

    sfText_setPosition(game->fight->hp, (sfVector2f){100, 200});
    sfText_setString(game->fight->hp, pv_perso);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->fight->back->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->pnj_scene->textbox->sprite, NULL);
    sfRenderWindow_drawSprite(
        window, game->fight->enemy[game->mobs]->sprite->sprite, NULL);
    sfRenderWindow_drawText(window, game->fight->hp, NULL);
    sfText_setPosition(game->fight->hp, (sfVector2f){100, 300});
    sfText_setString(game->fight->hp, pv_ennemi);
    sfRenderWindow_drawText(window, game->fight->hp, NULL);
    sfRenderWindow_drawText(window, game->fight->text, NULL);
    sfRenderWindow_display(window);
}

void draw_result_scene(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->fight->back->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->pnj_scene->textbox->sprite, NULL);
    sfRenderWindow_drawText(window, game->fight->text, NULL);
    sfRenderWindow_display(window);
}
