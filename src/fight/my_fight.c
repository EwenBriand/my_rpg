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
        game->fight->string = "Vous etes au porte de la mort\n";
    else {
        game->fight->string = "Vous avez vaincu l'ennemi\n il vous reste ";
        game->fight->string =
            my_strcat(game->fight->string, my_int_to_str(nb_mob));
        game->fight->string = my_strcat(game->fight->string, " ennemis\n");
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

void my_fight(sfRenderWindow *window, game_t *game, int nb_mobs)
{
    if (start_fight(window, game, nb_mobs) == 0) {
        if (game->mobs == 0)
            add_object_in_inv(game, "venin", nb_mobs);
        else if (game->mobs == 1)
            add_object_in_inv(game, "poudre a canon", nb_mobs);
    } else {
        game->perso->xp = 0;
        game->perso->stat->pv = 1;
    }
    game->fight->status = 0;
}
