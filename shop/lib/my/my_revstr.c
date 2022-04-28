/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** librairie my_revstr
*/

#include "my.h"

int len(char const *str)
{
    int i = 0;

    while (*str != '\0') {
        str++;
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int i = 0;
    int size = len(str) - 1;
    char letter;

    while (i < size) {
        letter = str[i];
        str[i] = str[size];
        str[size] = letter;
        i++;
        size--;
    }
    return str;
}
