/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_perso
*/

#include "my.h"

personnage_t *init_perso(void)
{
    personnage_t *perso = malloc(sizeof(personnage_t));

    perso->druide = 0;
    perso->bucheron = 0;
    perso->xp = 0;
    perso->level = 1;
    perso->xp_supp = 100;
    perso->credits = 1000;

    return (perso);
}
