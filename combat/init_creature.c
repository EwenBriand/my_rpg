/*
** EPITECH PROJECT, 2022
** my project
** File description:
** init creature
*/

champigoule_t *init_champigoule(int type)
{
    champigoule_t *champigoule = malloc(sizeof(champigoule_t));
    if (type == 0) {
        champigoule->nb = rand() % 6;
        champigoule->hp = malloc(sizeof(int) * champigoule->nb + 1);
        for (int i = 0; i <= champigoule->nb; i++) {
            chamigoule->hp[i] = 15;
        }
        champigoule->mp = 3;
        champigoule->pa = 1;
        champigoule->ma = 5;
        champigoule->damage = 4;
        champigoule->poison = 2;
    } else {
        free(champigoule);
        return NULL;
    }
    return champigoule;
}

vampivol_t *init_vampivol(int type)
{
    vampivol_t *vampivol = malloc(sizeof(vampivol_t));
    if (type == 1) {
        vampivol->nb = rand() % 6;
        vampivol->hp = malloc(sizeof(int) * vampivol->nb + 1);
        for (int i = 0; i <= vampivol->nb; i++) {
            vampivol->hp[i] = 15;
        }
        vampivol->mp = 5;
        vampivol->pa = 3;
        vampivol->ma = 3;
        vampivol->maxhp = 15;
        vampivol->damage = 4;
        vampivol->lifesteal = 4;
    } else {
        free(vampivol);
        return NULL;
    }
    return vampivol;
}

magivol_t *init_magivol(int type)
{
    magivol_t *magivol = malloc(sizeof(magivol_t));
    if (type == 2) {
        magivol->nb = rand() % 6;
        magivol->hp = malloc(sizeof(int) * magivol->nb + 1);
        for (int i = 0; i <= magivol->nb; i++) {
            magivol->hp[i] = 15;
        }
        magivol->mp = 5;
        magivol->pa = 5;
        magivol->ma = 2;
        magivol->magic_damage = 10;
    } else {
        free(magivol);
        return NULL;
    }
    return magivol;
}

rochexplosif_t *init_rochexplosif(int type)
{
    rochexplosif_t *rochexplosif = malloc(sizeof(rochexplosif_t));
    if (type == 3) {
        rochexplosif->nb = rand() % 6;
        rochexplosif->hp = malloc(sizeof(int) * rochexplosif->nb + 1);
        for (int i = 0; i <= rochexplosif->nb; i++) {
            rochexplosif->hp[i] = 20;
        }
        rochexplosif->mp = 4;
        rochexplosif->pa = 5;
        rochexplosif->ma = 4;
        rochexplosif->damage = 1;
        rochexplosif->explosion = 10;
    } else {
        free(rochexplosif);
        return NULL;
    }
    return rochexplosif;
}