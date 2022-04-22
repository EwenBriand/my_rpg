/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_pnj2
*/

#include "my.h"

static void init_replique(pnj_t *pnj)
{
    pnj->replique = malloc(sizeof(char *) * 7);
    pnj->replique[0] =
        "J'ai tellement faim,\nje reverrais d'avoir des baies !";
    pnj->replique[1] = "C'est pour moi ?\nMERCI !! tiens c'est pas grand "
                       "chose\nmais c'est toujours mieux que rien";
    pnj->replique[2] = "Ces Taupes me rendent dingues !!!!\nPeux tu en tuer "
                       "quelqu'un pour moi?";
    pnj->replique[3] =
        "Merci beaucoup et comme on dis\ntout travail merite salaire";
    pnj->replique[4] = "Des bandits se sont introduit chez moi\net m'ont "
                       "derober ma faux.\nPeux-tu me la retrouver ?";
    pnj->replique[5] =
        "Tu l'as retrouver ?\nJ'ai crus comprendre que ton\nvaisseau avais "
        "exploser ?\nje peux t'eberger en attendant si tu veux";
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
