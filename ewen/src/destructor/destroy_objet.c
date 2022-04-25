/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_objet
*/

#include "my.h"

void destroy_objet(objet_t **objet)
{
    for (int i = 0; objet[i] != NULL; ++i) {
        if (objet[i]->type == 0)
            free(objet[i]->stat);
        free(objet[i]);
    }
    free(objet);
}
