/*
** EPITECH PROJECT, 2021
** 2_Semestre
** File description:
** clickable_btn.c
*/

#include "my.h"

void press_play(mouse_poss_t *poss, play_btn_t *var)
{
        if (poss->mouse_poss.x <= var->play_b_pos.x + 1920 &&
            poss->mouse_poss.y <= var->play_b_pos.y + 1080 &&
            poss->mouse_poss.x >= var->play_b_pos.x + 1920 &&
            poss->mouse_poss.y >= var->play_b_pos.y + 1080 &&
            var->event.type == sfEvtMouseButtonPressed) {
                exit(0);
        }
}
