/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create_slash
*/

#include "my.h"

void create_slash(game_t *game)
{
    game->fight->slash = sfVertexArray_create();

    for (int j = 0; j < 10; ++j)
        for (int i = 0; i < 50; ++i) {
            sfVertexArray_append(game->fight->slash,
                (sfVertex){.position = (sfVector2f){1920 / 2 + i - j + 500,
                                1080 / 2 + i + 50},
                    .color = (sfColor){180, 50, 61, 255},
                    .texCoords = (sfVector2f){
                        1920 / 2 + i - j + 500, 1080 / 2 + 50 + i}});
        }
    game->fight->smoke = sfVertexArray_create();
    for (int i = 0; i < 360; ++i)
        sfVertexArray_append(game->fight->smoke,
            (sfVertex){
                .position = (sfVector2f){1920 / 2 + 700, 1080 / 2 + 250},
                .color = (sfColor){154, 152, 152, 255},
                .texCoords = (sfVector2f){1920 / 2 + 700, 1080 / 2 + 250}});
}
