/*
** EPITECH PROJECT, 2021
** 2_Semestre
** File description:
** clickable_btn.c
*/

#include "my.h"

int clickable_btn(
    window_t *window, play_btn_t *var, exit_btn_t *exite, int status)
{
    status = press_play(window, var, status);
    status = press_exit(window, exite, status);

    return status;
}

int press_play(window_t *poss, play_btn_t *var, int status)
{
    if (poss->event.mouseButton.x <= var->play_b_pos.x + 300
        && poss->event.mouseButton.y <= var->play_b_pos.y + 200
        && poss->event.mouseButton.x >= var->play_b_pos.x
        && poss->event.mouseButton.y >= var->play_b_pos.y) {
        return 2;
    }
    return status;
}

int press_exit(window_t *poss, exit_btn_t *var, int status)
{
    if (poss->event.mouseButton.x <= var->play_b_pos.x + 300
        && poss->event.mouseButton.y <= var->play_b_pos.y + 200
        && poss->event.mouseButton.x >= var->play_b_pos.x
        && poss->event.mouseButton.y >= var->play_b_pos.y) {
        return 1;
    }
    return status;
}
