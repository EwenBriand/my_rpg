/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create_stat
*/

#include <stdlib.h>
#include "my.h"

stat_t *creat_stat(void)
{
    stat_t *stat = malloc(sizeof(stat_t));
    stat->pv = 100;
    stat->pv_max = 100;
    stat->att_phy = 10;
    stat->def_phy = 10;
    stat->att_ma = 10;
    stat->def_ma = 10;
    return (stat);
}
