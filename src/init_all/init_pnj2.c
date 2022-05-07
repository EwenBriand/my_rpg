/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_pnj2
*/

#include "../../include/my.h"
#include "stdlib.h"

static void init_replique(pnj_t *pnj)
{
    pnj->replique = malloc(sizeof(char *) * 7);
    pnj->replique[0] = "I'm so hungry,\nI dream of having berries!";
    pnj->replique[1] = "Is it for me?\nTHANK YOU!! hey it's not a big"
                       "deal\nbut it's still better than nothing";
    pnj->replique[2] =
        "These snakes are driving me crazy!!!!\nCan you kill someone for me?";
    pnj->replique[3] =
        "Thank you very much and as we say\nall work deserves salary";
    pnj->replique[4] = "Bandits broke into my house\nand stole my "
                       "scythe.\nCan you find it for me?";
    pnj->replique[5] =
        "Did you find it?\nI understand that your ship has exploded?\nI can "
        "accommodate you\nwhile you wait if you want";
    pnj->replique[6] = NULL;
}

pnj_t *init_pnj2(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    init_replique(pnj);
    pnj->name = "Bob";
    pnj->id = 2;
    pnj->finish = 6;
    pnj->avancement = 0;
    pnj->credits = 150;
    pnj->xp = 20;
    pnj->obj = "baie";
    pnj->nb_obj = 5;
    pnj->type = 0;
    return (pnj);
}
