/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** my_fight
*/

#include "my.h"

static void print_result(game_t *game, sfRenderWindow *window, int nb_mob)
{
    int status = 0;

    if (game->perso->stat->pv <= 0)
        game->fight->string = "You are at death's door\n";
    else {
        game->fight->string = "You have defeated the enemy\nyou have ";
        game->fight->string =
            my_strcat(game->fight->string, my_int_to_str(nb_mob));
        game->fight->string =
            my_strcat(game->fight->string, " enemies left\n");
    }
    sfText_setString(game->fight->text, game->fight->string);
    while (sfRenderWindow_isOpen(window) && status == 0) {
        sfRenderWindow_clear(window, sfBlack);
        draw_result_scene(window, game);
        event_fight_result(window, game, &status);
        sfRenderWindow_display(window);
    }
}

static int fight_a_mob(sfRenderWindow *window, game_t *game, int nb_mob)
{
    while (game->perso->stat->pv > 0
        && game->fight->enemy[game->mobs]->stats->pv > 0
        && sfRenderWindow_isOpen(window)) {
        if (game->fight->status == 0)
            player_turn(window, game);
        if (game->fight->status == 1)
            mob_turn(game);
        if (game->fight->status >= 2)
            print_turn_result(window, game);
    }
    game->fight->enemy[game->mobs]->stats->pv =
        game->fight->enemy[game->mobs]->stats->pv_max;
    print_result(game, window, nb_mob);
    if (game->perso->stat->pv <= 0)
        return (1);
    return (0);
}

static int start_fight(sfRenderWindow *window, game_t *game, int nb_mobs)
{
    for (int i = 0; i < nb_mobs; i++)
        if (fight_a_mob(window, game, nb_mobs - i - 1) == 1)
            return 1;
    return 0;
}

static void is_win(game_t *game, int nb_mobs)
{
    if (game->all_pnj[1]->avancement == 2)
        game->all_pnj[1]->nb_obj += nb_mobs;

    add_object_in_inv(game, "venin", nb_mobs);
    game->perso->xp += nb_mobs * 5;
}

void my_fight(sfRenderWindow *window, game_t *game, int nb_mobs)
{
    if (start_fight(window, game, nb_mobs) == 0) {
        if (game->mobs == 0)
            is_win(game, nb_mobs);
        else if (game->mobs == 1) {
            add_object_in_inv(game, "poudre a canon", nb_mobs);
            game->perso->xp += nb_mobs * 5;
        }
    } else {
        game->perso->xp = 0;
        game->perso->stat->pv = 1;
    }
    game->fight->status = 0;
}
