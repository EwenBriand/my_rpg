/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy_pnj_scene
*/

#include "my.h"

void destroy_pnj_scene(pnj_scene_t *pnj_scene)
{
    destroy_sprite(pnj_scene->textbox);
    sfText_destroy(pnj_scene->name);
    sfText_destroy(pnj_scene->replique);
    sfFont_destroy(pnj_scene->font);
    free(pnj_scene);
}
