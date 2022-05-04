/*
** EPITECH PROJECT, 2022
** defender.h
** File description:
** defender.h
*/

#include "my.h"

#ifndef _DEFENDER_H_
    #define _DEFENDER_H_

typedef struct play_btn_s {
    sfTexture *play_b;
    sfSprite *play_sprite;
    sfVector2f play_b_pos;
    sfVector2f play_b_scale;
    sfEvent event;
    int pb_pos_x;
    int pb_pos_y;
} play_btn_t;

typedef struct exit_btn_s {
    sfTexture *play_b;
    sfSprite *play_sprite;
    sfVector2f play_b_pos;
    sfVector2f play_b_scale;
    int pb_pos_x;
    int pb_pos_y;
} exit_btn_t;

typedef struct option_btn_s {
    sfTexture *play_b;
    sfSprite *play_sprite;
    sfVector2f play_b_pos;
    sfVector2f play_b_scale;
    int pb_pos_x;
    int pb_pos_y;
} option_btn_t;

typedef struct how_play_btn_s {
    sfTexture *play_b;
    sfSprite *play_sprite;
    sfVector2f play_b_pos;
    sfVector2f play_b_scale;
    int pb_pos_x;
    int pb_pos_y;
} how_play_btn_t;

typedef struct mouse_poss_s {
    sfEvent event;
    sfVector2i mouse_poss;
} mouse_poss_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode vid_mod;
} window_t;

#endif
