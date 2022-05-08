/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_bestiaire
*/

#include <stdlib.h>
#include "my.h"

void init_bestiaire(game_t *game)
{
    game->best = malloc(sizeof(bestiaire_t));
    game->best->back = create_sprite(
        "sprites/shop/back.jpg", (int[4]){0, 0, 0, 0}, (int[2]){0, 0});
    game->best->enemy1 = create_sprite("sprites/fight/mob1.png",
        (int[4]){0, 0, 700, 700}, (int[2]){600, 100});
    game->best->enemy2 = create_sprite("sprites/fight/mob2.png",
        (int[4]){0, 0, 700, 700}, (int[2]){600, 600});
    sfSprite_setScale(game->best->enemy1->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(game->best->enemy2->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(game->best->back->sprite, (sfVector2f){5, 4});
    game->best->stat_enemy = sfText_create();
    game->best->string =
        "HP   30\nATT PHY  20\nDEF PHY  13\nATT MA   0\nDEF MA   "
        "5\n\n\n\n\n\n\n\n\n\n\n\n\n\nHP   "
        "30\nATT PHY  0\nDEF PHY  5\nATT MA   20\nDEF MA   13\n";
    sfText_setPosition(game->best->stat_enemy, (sfVector2f){1000, 200});
    sfText_setFont(game->best->stat_enemy, game->pnj_scene->font);
    sfText_setColor(game->best->stat_enemy, sfWhite);
    sfText_setString(game->best->stat_enemy, game->best->string);
}
