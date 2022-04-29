/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_object
*/

#include "stdlib.h"
#include "../../include/struct.h"
#include "../../include/my.h"

stat_t *empty_stat(void)
{
    stat_t *stat = malloc(sizeof(stat_t));
    stat->pv = 0;
    stat->pv_max = 0;
    stat->att_phy = 0;
    stat->def_phy = 0;
    stat->att_ma = 0;
    stat->def_ma = 0;
    return (stat);
}

static objet_t *creat_object(char *name, int type, stat_t *stat)
{
    objet_t *object = malloc(sizeof(objet_t));
    object->name = name;
    object->type = type;
    object->stack = 0;
    object->stat = stat;
    return (object);
}

static void creat_equip(objet_t **objects)
{
    objects[3] = creat_object("epee de linitier", 0, empty_stat());
    objects[3]->stat->att_phy = 1;
    objects[5] = creat_object("casque de linitier", 0, empty_stat());
    objects[5]->stat->def_phy = 1;
    objects[4] = creat_object("armure de linitier", 0, empty_stat());
    objects[4]->stat->def_phy = 1;
    objects[6] = creat_object("gants de linitier", 0, empty_stat());
    objects[6]->stat->att_ma = 1;
    objects[9] = creat_object("epaulettes de linitier", 0, empty_stat());
    objects[9]->stat->att_ma = 1;
    objects[8] = creat_object("jambiere de linitier", 0, empty_stat());
    objects[8]->stat->def_ma = 1;
    objects[7] = creat_object("bottes de linitier", 0, empty_stat());
    objects[7]->stat->att_phy = 1;
    objects[10] = creat_object("collier de linitier", 0, empty_stat());
    objects[10]->stat->pv = 5;
    objects[11] = creat_object("baton de magicien", 0, empty_stat());
    objects[11]->stat->att_ma = 2;
}

objet_t **init_all_objects(void)
{
    objet_t **objects = malloc(sizeof(objet_t *) * (NB_OBJECTS + 1));
    creat_equip(objects);
    objects[0] = creat_object("potion", 1, NULL);
    objects[1] = creat_object("antidote", 2, NULL);
    objects[2] = creat_object("poudre a canon", 3, NULL);
    objects[12] = creat_object("baie", 4, NULL);
    objects[13] = creat_object("bois", 5, NULL);
    objects[14] = creat_object("faux", 3, NULL);
    objects[15] = NULL;

    return (objects);
}
