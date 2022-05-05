/*
** EPITECH PROJECT, 2022
** my project
** File description:
** init combat
*/

creature_t *init_creature(void)
{
    creature_t *creature = malloc(sizeof(creature_t));
    creature->type = rand() % 4;
    creature->champigoule = init_champigoule(creature->type);
    creature->vampivol = init_vampivol(creature->type);
    creature->magivol = init_magivol(creature->type);
    creature->rochexplosif = init_rochexplosif(creature->type);
    return creature;
}

combat_t *init_combat(void)
{
    combat_t *combat = malloc(sizeof(combat_t));
    combat->creature = init_creature();
    return combat;
}