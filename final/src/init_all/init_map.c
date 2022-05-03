/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_map
*/

#include "../../include/my.h"
#include "SFML/Graphics.h"
#include "stdio.h"
#include "stdlib.h"

static int change_temp(char *temp, int pos, char c)
{
    temp[pos++] = c;
    temp[pos] = '\0';
    return pos;
}

static int **for_loop(char *buffer, char *temp)
{
    int **array = malloc(sizeof(int *) * 13);
    int pos[3] = {0, 0, 0};
    array[0] = malloc(sizeof(int) * 21);
    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == '\n' && buffer[i + 1] == '\n')
            break;
        if (buffer[i] == '\n') {
            array[pos[1]++][pos[0]] = -1;
            array[pos[1]] = malloc(sizeof(int) * 21);
            pos[0] = 0;
        } else if (buffer[i] == ' ') {
            array[pos[1]][pos[0]++] = my_atoi(temp);
            pos[2] = 0;
        } else {
            pos[2] = change_temp(temp, pos[2], buffer[i]);
        }
    }
    array[pos[1] + 1] = NULL;
    return array;
}

int **creat_int_array_from_file(char *path)
{
    char *buffer = get_buffer(path);
    char *temp = malloc(sizeof(char) * 5);
    int **array = for_loop(buffer, temp);

    free(buffer);
    free(temp);
    return array;
}

map_t *create_map(char *path, int *pos, char *path_int)
{
    map_t *map = malloc(sizeof(map_t));

    map->map = creat_int_array_from_file(path_int);
    map->pos = malloc(sizeof(int) * 2);
    map->pos[0] = 0;
    map->pos[1] = 0;
    map->background = create_sprite(path, pos, pos);
    map->size_x = 14;
    map->size_y = 8;

    sfSprite_setScale(map->background->sprite, (sfVector2f){2, 2});
    return (map);
}
