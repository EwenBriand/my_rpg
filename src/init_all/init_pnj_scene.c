/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_pnj_scene
*/

#include "../../include/my.h"
#include "stdlib.h"
#include "SFML/Graphics.h"

pnj_scene_t *init_pnj_scene(void)
{
    pnj_scene_t *pnj_scene = malloc(sizeof(pnj_scene_t));
    pnj_scene->textbox = create_sprite(
        "sprites/dialogue2.png", (int[4]){0, 0, 920, 244}, (int[2]){550, 750});
    pnj_scene->name = sfText_create();
    pnj_scene->replique = sfText_create();
    pnj_scene->font = sfFont_createFromFile("fonts/pixelart.TTF");

    sfText_setPosition(pnj_scene->name, (sfVector2f){780, 775});
    sfText_setPosition(pnj_scene->replique, (sfVector2f){595, 850});
    sfText_setFont(pnj_scene->name, pnj_scene->font);
    sfText_setFont(pnj_scene->replique, pnj_scene->font);
    sfText_setColor(pnj_scene->name, sfWhite);
    sfText_setColor(pnj_scene->replique, sfBlack);

    return (pnj_scene);
}
