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
                        "magic attack ", "magic defense ", "XP ", "level ",
                        "credit ", "level druid ", "level lumberjack ",
                        "level up in "};
    int number[11] = {stat->pv, stat->att_phy, stat->def_phy, stat->att_ma,
                        stat->def_ma, perso->xp, perso->level, perso->credits,
                        perso->druide,perso->bucheron, perso->xp_supp};

    str[0] = '\0';
    for (int i = 0; i != 11; i++) {
        str = my_strcat(str, string[i]);
        str = my_strcat(str, itoa(number[i]));
        if (i != 10)
            str = my_strcat(str, "\n\n");
    }
    str = my_strcat(str, " XP\0");
    return str;
}

void display_inv_bis(int display, objet_t *objet, game_t *game, sfSprite *sprite)
{
    if (my_strcmp(objet->name, "gants de linitier") == 0) {
        sprite = game->shop.items[4].sprite;
        display = 1;
    }
    if (my_strcmp(objet->name, "collier de linitier") == 0) {
        sprite = game->shop.items[5].sprite;
        display = 1;
    }
    if (my_strcmp(objet->name, "epaulettes de linitier") == 0) {
        sprite = game->shop.items[6].sprite;
        display = 1;
    }
    if (my_strcmp(objet->name, "bottes de linitier") == 0) {
        sprite = game->shop.items[7].sprite;
        display = 1;
    }
    display_inv_tree(display, objet, game, sprite);
}

void display_inv(int display, int i, game_t *game, sfSprite *sprite)
{
    objet_t *objet = game->perso->inv->inv[i];
    if (my_strcmp(objet->name, "casque de linitier") == 0) {
        sprite = game->shop.items[0].sprite;
        display = 1;
    }
    if (my_strcmp(objet->name, "armure de linitier") == 0) {
        sprite = game->shop.items[1].sprite;
        display = 1;
    }
    if (my_strcmp(objet->name, "jambiere de linitier") == 0) {
        sprite = game->shop.items[2].sprite;
        display = 1;
    }
    if (my_strcmp(objet->name, "epee de linitier") == 0) {
        sprite = game->shop.items[3].sprite;
        display = 1;
    }
    display_inv_bis(display, objet, game, sprite);
}

void display_equip(sfRenderWindow *window, game_t *game, sfText *text)
{
    sfVector2f place1 = (sfVector2f) {75, 150};
    game->place_inv = (sfVector2f) {124, 400};
    sfSprite *sprite;
    int nbr[2] = {0, 0};

    sfText_setString(text, "equipment");
    sfText_setPosition(text, (sfVector2f) {480, 50});
    sfText_setCharacterSize(text, 50);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_setString(text, "inventory");
    sfText_setPosition(text, (sfVector2f) {480, 300});
    sfRenderWindow_drawText(window, text, NULL);
    game->text_inv = text;
    for (int i = 0; game->perso->inv->inv[i] != NULL; i++) {
        display_inv(nbr[0], i, game, sprite);
        display1(sprite, window, nbr, &place1);
        display2(sprite, nbr, game, window);
    }
}

void open_inventory(sfRenderWindow *window, game_t *game)
{
    char *str = make_str(game);
    sfFont *font = sfFont_createFromFile("fonts/pixelart.TTF");
    sfText *text = sfText_create();
    sfVector2f place = (sfVector2f){1450, 250};

    game->shop.posi_mouse = sfMouse_getPositionRenderWindow(window);
    sfRenderWindow_drawSprite(window, game->shop.back.sprite, NULL);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, place);
    sfRenderWindow_drawText(window, text, NULL);
    display_equip(window, game, text);
    check_close(window, game);
}
