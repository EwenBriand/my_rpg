/*
** EPITECH PROJECT, 2021
** Semestre_project
** File description:
** my_strdup.c
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i;

    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}