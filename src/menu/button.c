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
