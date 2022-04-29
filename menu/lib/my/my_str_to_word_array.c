/*
** EPITECH PROJECT, 2021
** Semestre_project
** File description:
** my_str_to_word_array.c
*/

#include "my.h"

int wl(char *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            j++;
            return j;
        }
    }
}

char **my_str_to_word_array(char *str)
{
    int j = 1;
    char **array;
    int m = 0;
    int x = 0;

    array = malloc(sizeof(char *) * (j + 1));

    for (int i = 0; i != j; i++) {
        for (m; str[m] != ' ' && str[m] != '\0'; m++) {
        }
        array[i] = malloc(sizeof(char) * (m + 1));
        for (int y = 0; str[x] != ' ' && str[x] != '\0'; x++, y++) {
            array[i][y] = str[x];
        }
        m++;
        x++;
    }
    return array;
}