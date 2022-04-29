/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_perso
*/

#include "../../include/struct.h"
#include "stdlib.h"
#include "../../include/my.h"

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

static inv_t *creat_inv(void)
{
    inv_t *inv = malloc(sizeof(inv_t));
    inv->inv = malloc(sizeof(inv_t) * (INV_SIZE + 1));
    inv->nb_obj_max = INV_SIZE;
    inv->nb_obj = 0;

    return (inv);
}

equip_t *creat_equip(void)
{
    equip_t *equip = malloc(sizeof(equip_t));
    equip->head = NULL;
    equip->body = NULL;
    equip->leg = NULL;
    equip->gauntlet = NULL;
    equip->neck = NULL;
    equip->shoulder = NULL;
    equip->weapon = NULL;
    equip->foot = NULL;
    return (equip);
}

static sort_t *creat_sort(char *name, int dmg, char *description)
{
    sort_t *sort = malloc(sizeof(sort_t));
    sort->name = name;
    sort->dmg = dmg;
    sort->description = description;
    return (sort);
}

static sort_t **creat_list_sort(void)
{
    sort_t **list = malloc(sizeof(sort_t *) * (NB_SORTS + 1));
    list[0] = creat_sort("boule de feu", 5, "lance une boule de feu");
    list[1] = creat_sort("pique de glace", 5, "lance une pique de glace");
    list[2] = creat_sort("eclair", 5, "lance un eclair");
    list[3] = NULL;

    return (list);
}

personnage_t *init_perso(void)
{
    personnage_t *perso = malloc(sizeof(personnage_t));

    perso->druide = 0;
    perso->bucheron = 0;
    perso->xp = 0;
    perso->level = 1;
    perso->xp_supp = 10;
    perso->credits = 1000;
    perso->stat = creat_stat();
    perso->inv = creat_inv();
    perso->inv->inv[0] = NULL;
    perso->equip = creat_equip();
    perso->list_sort = creat_list_sort();
    return (perso);
}
