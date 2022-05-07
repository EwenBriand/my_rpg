/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** open_inv
*/

#include "../../include/my.h"
#include "SFML/Graphics.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *make_str(game_t *game)
{
    char *str = malloc(sizeof(char) * 200);
    stat_t *stat = game->perso->stat;
    personnage_t *perso = game->perso;
    char *string[11] = {"PV ", "physical attack ", "physical defense ",
                        "magic attack ", "magic defense ", "XP ",
                        "level ", "credit ", "level druid ",
                        "level lumberjack ", "level up in "};
    int number[11] = {stat->pv, stat->att_phy, stat->def_phy, stat->att_ma,
                      stat->def_ma, perso->xp, perso->level, perso->credits,
                      perso->druide, perso->bucheron, perso->xp_supp};

    str[0] = '\0';
    for (int i = 0; i != 11; i++) {
        strcat(str, string[i]);
        strcat(str, itoa(number[i]));
        if (i != 10)
            strcat(str, "\n\n");
    }
    strcat(str, " XP\0");
    return str;
}

void open_inventory(sfRenderWindow *window, game_t *game)
{
    char *str = make_str(game);
    sfFont *font = sfFont_createFromFile("fonts/pixelart.TTF");
    sfText *text = sfText_create();
    sfVector2f place = (sfVector2f) {1450, 250};

    game->shop.posi_mouse = sfMouse_getPositionRenderWindow(window);
    sfRenderWindow_drawSprite(window, game->shop.back.sprite, NULL);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, place);
    sfRenderWindow_drawText(window, text, NULL);
    check_close(window, game);
}
