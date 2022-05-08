/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** button.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

play_btn_t *button(void)
{
    play_btn_t *var = malloc(sizeof(play_btn_t));
    if (var == NULL)
        return NULL;
    var->play_b = sfTexture_createFromFile("ressources/btn_play.png", NULL);
    var->play_sprite = sfSprite_create();
    sfSprite_setTexture(var->play_sprite, var->play_b, sfFalse);
    var->pb_pos_x = 630;
    var->pb_pos_y = 450;
    var->play_b_pos.x = var->pb_pos_x;
    var->play_b_pos.y = var->pb_pos_y;
    var->play_b_scale.x = 6.5;
    var->play_b_scale.y = 6.5;
    sfSprite_setPosition(var->play_sprite, var->play_b_pos);
    sfSprite_setScale(var->play_sprite, var->play_b_scale);
    return var;
}

exit_btn_t *exit_btn(void)
{
    exit_btn_t *var = malloc(sizeof(exit_btn_t));
    if (var == NULL)
        return NULL;
    var->play_b = sfTexture_createFromFile("ressources/btn_exit.png", NULL);
    var->play_sprite = sfSprite_create();
    sfSprite_setTexture(var->play_sprite, var->play_b, sfFalse);
    var->pb_pos_x = 1020;
    var->pb_pos_y = 450;
    var->play_b_pos.x = var->pb_pos_x;
    var->play_b_pos.y = var->pb_pos_y;
    var->play_b_scale.x = 6.5;
    var->play_b_scale.y = 6.5;
    sfSprite_setPosition(var->play_sprite, var->play_b_pos);
    sfSprite_setScale(var->play_sprite, var->play_b_scale);
    option_btn();
    return var;
}

option_btn_t *option_btn(void)
{
    option_btn_t *var = malloc(sizeof(option_btn_t));
    if (var == NULL)
        return NULL;
    var->play_b = sfTexture_createFromFile("ressources/btn_sys.png", NULL);
    var->play_sprite = sfSprite_create();
    sfSprite_setTexture(var->play_sprite, var->play_b, sfFalse);
    var->pb_pos_x = 1010 - 120;
    var->pb_pos_y = 665;
    var->play_b_pos.x = var->pb_pos_x;
    var->play_b_pos.y = var->pb_pos_y;
    var->play_b_scale.x = 6.5;
    var->play_b_scale.y = 6.5;
    sfSprite_setPosition(var->play_sprite, var->play_b_pos);
    sfSprite_setScale(var->play_sprite, var->play_b_scale);
    return var;
}

void setup_text_menu(sfText *text, sfFont *font)
{
    sfText_setFont(text, font);
    sfText_setString(text,
        "Z go up\n\nS go down\n\nQ go left\n\nD go right\n\nB to open "
        "bestary\n\nE to open inventory\n\nI to interact with the map\n\nM to "
        "open minimap\n\nPress ESC to exit\n\n\n\nIn Fight\n\n\nA use "
        "antidote\n\nP use potion\n\nL magic attack\n\nF physique attack\n\n");
    sfText_setPosition(text, (sfVector2f){80, 80});
    sfText_setColor(text, sfBlack);
}
