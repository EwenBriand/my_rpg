/*
** EPITECH PROJECT, 2022
** my project
** File description:
** enemy turn
*/

int enemy_turn2(void)
{
    if (temp == 3) {
        for (int i = 0; i <= creature->magivol->nb; i++) {
            magivol(player, creature->magivol);
        }
    } else if(temp == 4) {
        for (int i = 0; i <= creature->rochexplosif->nb; i++) {
            rochexplosif(player, creature->rochexplosif, i);
        }
    } else {
        return 0;
    }
}

void enemy_turn(player_t *player, creature_t *creature)
{
    int temp = creature->type;
    if (temp == 1) {
        for (int i = 0; i <= creature->champigoule->nb; i++) {
            champigoule(player, creature->champigoule);
        }
    } else if(temp == 2) {
        for (int i = 0; i <= creature->vampivol->nb; i++) {
            vampivol(player, creature->vampivol, i);
        }
    } else {
        enemy_turn2()
    }
}