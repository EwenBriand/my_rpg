/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_game
*/

#include <SFML/Audio.h>
#include "../../include/my.h"
#include "stdlib.h"

void destroy_game(game_t *game)
{
    sfMusic_destroy(game->level_up_sound);
    sfMusic_destroy(game->quest_complete_sound);
    sfMusic_destroy(game->fireworks);
    sfClock_destroy(game->clock);

    destroy_pnj(game->all_pnj);
    destroy_pnj_scene(game->pnj_scene);
    destroy_objet(game->all_objets);
    destroy_perso(game->perso);
    destroy_charter(game->charter);
    destroy_map(game->map);
    destroy_particule(game->particule_array);
    destroy_sprite(game->resume_btn);
    destroy_sprite(game->quit_btn);
    destroy_sprite(game->the_end);
    destroy_fight(game->fight);

    free(game);
}
