/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_pnj
*/

#include "stdlib.h"
#include "../../include/my.h"

void destroy_pnj(pnj_t **pnj)
{
    for (int i = 0; pnj[i] != NULL; ++i) {
        free(pnj[i]->replique);
        free(pnj[i]);
    }
    free(pnj);
}
