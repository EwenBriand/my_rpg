/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** add
*/

#include "../../include/my.h"

static void add_obj(game_t *game, objet_t *objet)
{
    int end = 0;
    for (int i = 0; game->perso->inv->inv[i] != NULL && end == 0; ++i) {
        if (my_strcmp(game->perso->inv->inv[i]->name, objet->name) == 0) {
            ++game->perso->inv->inv[i]->stack;
            ++end;
        }
    }
    if (end == 0) {
        ++objet->stack;
        game->perso->inv->inv[game->perso->inv->nb_obj] = objet;
        ++game->perso->inv->nb_obj;
        game->perso->inv->inv[game->perso->inv->nb_obj] = NULL;
    }
}

void add_object_in_inv(game_t *game, char *name, int nb)
{
    objet_t *objet = NULL;

    for (int i = 0; game->all_objets[i] != NULL; i++) {
        if (my_strcmp(game->all_objets[i]->name, name) == 0) {
            objet = game->all_objets[i];
            break;
        }
    }
    if (game->perso->inv->nb_obj == game->perso->inv->nb_obj_max
        || objet == NULL)
        return;
    for (int i = 0; i < nb; i++) {
        if (objet->type == 0) {
            ++objet->stack;
            game->perso->inv->inv[game->perso->inv->nb_obj] = objet;
            ++game->perso->inv->nb_obj;
            game->perso->inv->inv[game->perso->inv->nb_obj] = NULL;
        } else
            add_obj(game, objet);
    }
}
