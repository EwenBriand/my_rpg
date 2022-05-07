/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_pnjs
*/

#include "../../include/my.h"
#include "stdlib.h"

static pnj_t *init_pnj1(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    pnj->name = "Tuco";
    pnj->id = 1;
    pnj->finish = 2;
    pnj->avancement = 0;
    pnj->credits = 10;
    pnj->xp = 30;
    pnj->replique = malloc(sizeof(char *) * 3);
    pnj->replique[0] = "Hey you,\nif you find some gunpowder\nI'm ready to "
                       "buy it from you at a good price...";
    pnj->replique[1] =
        "FINALLY I will be able to... uh...\nstop digging. Here is your money";
    pnj->replique[2] = NULL;
    pnj->obj = "poudre a canon";
    pnj->nb_obj = 1;
    pnj->type = 0;
    return (pnj);
}

static pnj_t *init_pnj3(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    pnj->name = "James";
    pnj->id = 3;
    pnj->finish = 2;
    pnj->avancement = 0;
    pnj->credits = 350;
    pnj->xp = 0;
    pnj->replique = malloc(sizeof(char *) * 3);
    pnj->replique[0] = "In video games as in the Oasis, a\n"
                       "adventurer must be well equipped.";
    pnj->replique[1] =
        "Looks like the start of an\nadventure worthy of good old Gary";
    pnj->replique[2] = NULL;
    pnj->type = 3;
    return (pnj);
}

static pnj_t *init_pnj4(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    pnj->name = "Jack";
    pnj->id = 4;
    pnj->finish = 2;
    pnj->avancement = 0;
    pnj->credits = 200;
    pnj->xp = 0;
    pnj->replique = malloc(sizeof(char *) * 3);
    pnj->replique[0] =
        "I'm looking for venom for uh...\nyou don't need to know.";
    pnj->replique[1] = "Thank you very much, I hope that\nyou don't like the\n"
                       "banker too much...";
    pnj->replique[2] = NULL;
    pnj->obj = "venin";
    pnj->nb_obj = 1;
    pnj->type = 0;
    return (pnj);
}

static pnj_t *init_pnj5(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    pnj->name = "Ponzi";
    pnj->id = 5;
    pnj->finish = 2;
    pnj->avancement = 0;
    pnj->credits = 30;
    pnj->xp = 5;
    pnj->replique = malloc(sizeof(char *) * 3);
    pnj->replique[0] = "Someone blew up the wall,\ndo you have a can of wood?";
    pnj->replique[1] =
        "Well, that's enough to take the\ntime to redo a stone wall";
    pnj->replique[2] = NULL;
    pnj->obj = "bois";
    pnj->nb_obj = 10;
    pnj->type = 0;
    return (pnj);
}

pnj_t **init_pnjs(void)
{
    pnj_t **all_pnj = malloc(sizeof(pnj_t *) * (NB_PNJ + 1));

    all_pnj[0] = init_pnj1();
    all_pnj[1] = init_pnj2();
    all_pnj[2] = init_pnj3();
    all_pnj[3] = init_pnj4();
    all_pnj[4] = init_pnj5();
    all_pnj[5] = NULL;
    return (all_pnj);
}
