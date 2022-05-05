/*
** EPITECH PROJECT, 2022
** my project
** File description:
** enemy turn 2
*/

void champigoule(player_t *player, champigoule_t *champigoule)
{
    int roll = 0
    player->hp = champigoule->damage - player->pa;
    roll = rand % 6;
    if (roll == 5) {
        player->hp -= 4;
        player->poison = 4;
        player->poison += 1;
    }
}

void vampivol(player_t *player, vampivol_t *vampivol, int i)
{
    player->hp = vampivol->damage - player->pa;
    if (vampivol->hp[i] < vampivol->maxhp) {
        vampivol->hp[i] += vampivol->lifesteal - player->pa;
        if (vampivol->hp[i] > vampivol->maxhp) {
            vampivol->hp[i] = vampivol->maxhp;
        }
    }
}

void magivol(player_t *magivol, creature_t *magivol)
{
    player->hp = magivol->magic_damage - player->ma;
}

void rochexplosif(player_t *player, rochexplosif_t *rochexplosif, int i)
{
    int roll = rand % 6;
    if (roll == 5) {
        rochexplosif->hp[i] = 0;
        player->hp -= rochexplosif->explosion;
    } else {
        player->hp = rochexplosif->damage - player->pa;
    }
}