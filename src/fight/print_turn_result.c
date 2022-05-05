/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** print_turn_result
*/

#include "my.h"

static void last_party(sfRenderWindow *window, game_t *game)
{
    if (game->fight->status == 6) {
        draw_fight_scene(window, game, 1);
        player_event(window, game);
    }
}

static void second_party(sfRenderWindow *window, game_t *game)
{
    if (game->fight->status == 4) {
        game->fight->string = "Vous avez fait ";
        game->fight->string =
            my_strcat(game->fight->string, my_int_to_str(phy_dmg_deal(game)));
        game->fight->string =
            my_strcat(game->fight->string, " degat physique\n");
        sfText_setString(game->fight->text, game->fight->string);
        draw_fight_scene(window, game, 1);
        player_event(window, game);
    } else if (game->fight->status == 5) {
        game->fight->string = "Vous avez fait ";
        game->fight->string =
            my_strcat(game->fight->string, my_int_to_str(mag_dmg_deal(game)));
        game->fight->string =
            my_strcat(game->fight->string, " degat magique\n");
        sfText_setString(game->fight->text, game->fight->string);
        draw_fight_scene(window, game, 1);
        player_event(window, game);
    }
}

void print_turn_result(sfRenderWindow *window, game_t *game)
{
    if (game->fight->status == 2) {
        game->fight->string = "Vous vous etes soignie de 30 PV\n";
        sfText_setString(game->fight->text, game->fight->string);
        draw_fight_scene(window, game, 1);
        player_event(window, game);
    }
    if (game->fight->status == 3) {
        game->fight->string = "Vous avez soignie votre empoisonnement\n";
        sfText_setString(game->fight->text, game->fight->string);
        draw_fight_scene(window, game, 1);
        player_event(window, game);
    }
    second_party(window, game);
    last_party(window, game);
}
