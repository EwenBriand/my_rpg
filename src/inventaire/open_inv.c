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
                        "magic attack ", "magic defense ", "XP ", "level ", "credit ",
                        "level druid ", "level lumberjack ", "level up in "};
    int number[11] = {stat->pv, stat->att_phy, stat->def_phy, stat->att_ma,
                      stat->def_ma, perso->xp, perso->level, perso->credits, perso->druide,
                      perso->bucheron, perso->xp_supp};

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

void display_equip(sfRenderWindow *window, game_t *game, sfText *text)
{
    sfVector2f place1 = (sfVector2f) {75, 150};
    sfVector2f place2 = (sfVector2f) {124, 400};
    sfVector2f place3;
    objet_t *objet;
    sfSprite *sprite;
    int display = 0;

    sfText_setString(text, "equipment");
    sfText_setPosition(text, (sfVector2f) {480, 50});
    sfText_setCharacterSize(text, 50);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_setString(text, "inventory");
    sfText_setPosition(text, (sfVector2f) {480, 300});
    sfRenderWindow_drawText(window, text, NULL);
    for (int i = 0; game->perso->inv->inv[i] != NULL; i++) {
        objet = game->perso->inv->inv[i];
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
        if (my_strcmp(objet->name, "potion") == 0) {
            sprite = game->shop.items[8].sprite;
            display = 2;
        }
        if (my_strcmp(objet->name, "antidote") == 0) {
            sprite = game->shop.items[9].sprite;
            display = 2;
        }
        if (display == 1) {
            place3 = sfSprite_getPosition(sprite);
            sfSprite_setPosition(sprite, place1);
            sfRenderWindow_drawSprite(window, sprite, NULL);
            sfSprite_setPosition(sprite, place3);
            place1.x += 170;
            display = 0;
        }
        if (display == 2) {
            place3 = sfSprite_getPosition(sprite);
            sfSprite_setPosition(sprite, place2);
            sfText_setString(text, itoa(game->perso->inv->inv[i]->stack));
            sfText_setPosition(text, (sfVector2f) {place2.x + 30, place2.y + 120});
            sfRenderWindow_drawText(window, text, NULL);
            sfRenderWindow_drawSprite(window, sprite, NULL);
            sfSprite_setPosition(sprite, place3);
            place2.x += 219;
            display = 0;
        }
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
    <<<<<<< HEAD
            =======
                    display_equip(window, game, text);
    for (int i = 0; game->perso->inv->inv[i] != NULL; i++) {
        printf("%s\n", game->perso->inv->inv[i]->name);
    }
    printf("\n\n");
    >>>>>>> c7f991d (finich inv)
    check_close(window, game);
}