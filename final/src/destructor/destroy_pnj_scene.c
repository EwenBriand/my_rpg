/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_pnj_scene
*/

#include "../../include/my.h"
#include "stdlib.h"
#include <SFML/Graphics.h>

void destroy_pnj_scene(pnj_scene_t *pnj_scene)
{
    destroy_sprite(pnj_scene->textbox);
    sfText_destroy(pnj_scene->name);
    sfText_destroy(pnj_scene->replique);
    sfFont_destroy(pnj_scene->font);
    free(pnj_scene);
}
