/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** mob_turn
*/

#include <stdlib.h>
#include <time.h>
#include "my.h"

static int player_def(game_t *game)
{
    int def = 0;

    if (game->mobs == 0) {
        def += game->perso->stat->def_phy;
        if (game->perso->equip->head != NULL)
            def += game->perso->equip->head->stat->def_phy;
        if (game->perso->equip->body != NULL)
            def += game->perso->equip->body->stat->def_phy;
        if (def > game->fight->enemy[game->mobs]->stats->att_phy)
            def = game->fight->enemy[game->mobs]->stats->att_phy;
    } else if (game->mobs == 1) {
        def += game->perso->stat->def_ma;
        if (game->perso->equip->leg != NULL)
            def += game->perso->equip->leg->stat->def_ma;
        if (def > game->fight->enemy[game->mobs]->stats->att_ma)
            def = game->fight->enemy[game->mobs]->stats->att_ma;
    }
    return def;
}

char *my_int_to_str(int nb)
{
    int i = 0;
    int len = (nb < 0) ? (nb * -1) + 2 : nb + 2;
    char *str = malloc(sizeof(char) * len);

    if (str == NULL)
        return (NULL);
    if (nb < 0) {
        str[i++] = '-';
        nb = -nb;
    }
    if (nb == 0)
        str[i++] = '0';
    for (; nb > 0; ++i) {
        str[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}

static void change_string(game_t *game, int dmg)
{
    char *temp;
    game->fight->string = "You have taken ";
    temp = my_strcat(game->fight->string, my_int_to_str(dmg));
    game->fight->string = my_strcat(temp, " damage\n");
    free(temp);
    temp = game->fight->string;
    if (game->fight->venin == 1)
        game->fight->string = my_strcat(temp, "You are poisoned\n");
    sfText_setString(game->fight->text, game->fight->string);
    free(temp);
}

void mob_turn(game_t *game)
{
    srand(time(NULL));
    int venin = rand() % 7;
    int dm = 0;

    if (game->mobs == 0) {
        if (venin == 0)
            game->fight->venin = 1;
        dm = game->fight->enemy[game->mobs]->stats->att_phy - player_def(game);
        game->perso->stat->pv -= dm;
        change_string(game, dm);
        game->fight->status = 6;
    } else if (game->mobs == 1) {
        dm = game->fight->enemy[game->mobs]->stats->att_ma - player_def(game);
        game->perso->stat->pv -= dm;
        change_string(game, dm);
        game->fight->status = 6;
    }
}
