/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_pnjs
*/

#include "my.h"

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
    pnj->replique[0] = "Eh toi, si tu me trouve de la poudre a canon\nje suis "
                       "pret a te l'acheter a bon prix...";
    pnj->replique[1] = "ENFIN je vais pouvoir... euuh...\narreter de creuser. "
                       "Voici ton argent";
    pnj->replique[2] = NULL;
    pnj->obj = "poudre a canon";
    pnj->nb_obj = 1;
    pnj->type = 0;
    return (pnj);
}

static pnj_t *init_pnj2(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    pnj->name = "Bob";
    pnj->id = 2;
    pnj->finish = 6;
    pnj->avancement = 0;
    pnj->credits = 150;
    pnj->xp = 10;
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
    pnj->obj = "baie";
    pnj->nb_obj = 5;
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
    pnj->replique[0] = "Dans les jeux videos comme dans l'Oasis, un\n"
                       "aventurier se doit d'etre bien equipe.";
    pnj->replique[1] =
        "On dirais le debut d'une aventure\ndigne de ce bon vieux Gary";
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
        "Je recherche du venin pour euh...\nt'as pas besoin de le savoir.";
    pnj->replique[1] =
        "Merci beaucoup, j'espere que\ntu aimes pas beaucoup le banquier...";
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
    pnj->replique[0] =
        "Quelqu'un as fait exploser le mur,\ntu aurrais pas un peux de bois?";
    pnj->replique[1] =
        "Bon c'est suffisant pour tenir le temps\nde refaire un mur en Pierre";
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
