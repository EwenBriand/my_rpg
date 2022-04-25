/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_perso
*/

#include "my.h"

void destroy_perso(personnage_t *perso)
{
    for (int i = 0; perso->list_sort[i] != NULL; ++i)
        free(perso->list_sort[i]);
    free(perso->list_sort);

    free(perso->stat);
    free(perso->inv->inv);
    free(perso->inv);
    free(perso->equip);
    free(perso);
}
