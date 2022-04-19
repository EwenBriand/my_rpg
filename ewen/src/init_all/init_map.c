/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init_map
*/

#include "my.h"

int **creat_int_array_from_file(char *path)
{
    int **array = malloc(sizeof(int *) * 12);
    char *buffer = get_buffer(path);
    int pos[3] = {0, 0, 0};
    char *temp = malloc(sizeof(char) * 5);
    array[0] = malloc(sizeof(int) * 21);

    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == '\n' && buffer[i + 1] == '\n')
            break;
        if (buffer[i] == '\n') {
            printf("\n");
            array[pos[1]++][pos[0]] = -1;
            array[pos[1]] = malloc(sizeof(int) * 21);
            pos[0] = 0;
        } else if (buffer[i] == ' ') {
            printf("%i ", my_atoi(temp));
            array[pos[1]][pos[0]++] = my_atoi(temp);
            pos[2] = 0;
        } else {
            temp[pos[2]++] = buffer[i];
            temp[pos[2]] = '\0';
        }
    }
    array[pos[1] + 1] = NULL;
    free(buffer);
    free(temp);
    return (array);
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
