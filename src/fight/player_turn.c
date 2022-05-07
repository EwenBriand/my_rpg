/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** player_turn
*/

#include <stdlib.h>
#include "my.h"

static void draw_some_sprite(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->fight->back->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->pnj_scene->textbox->sprite, NULL);
    sfRenderWindow_drawSprite(
        window, game->fight->enemy[game->mobs]->sprite->sprite, NULL);
}

void player_turn(sfRenderWindow *window, game_t *game)
{
    char *pv_perso =
        my_strcat("HP PLAYER  ", my_int_to_str(game->perso->stat->pv));
    char *pv_ennemi = my_strcat("HP ENEMY  ",
        my_int_to_str(game->fight->enemy[game->mobs]->stats->pv));
    game->fight->string = "Player turn\n";

    sfText_setPosition(game->fight->hp, (sfVector2f){100, 200});
    draw_some_sprite(window, game);
    sfText_setString(game->fight->hp, pv_perso);
    player_event(window, game);
    sfRenderWindow_drawText(window, game->fight->hp, NULL);
    sfText_setPosition(game->fight->hp, (sfVector2f){100, 300});
    sfText_setString(game->fight->hp, pv_ennemi);
    sfRenderWindow_drawText(window, game->fight->hp, NULL);
    sfText_setString(game->fight->text, game->fight->string);
    sfRenderWindow_drawText(window, game->fight->text, NULL);
    sfRenderWindow_display(window);
    free(pv_ennemi);
    free(pv_perso);
}
