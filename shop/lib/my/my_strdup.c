/*
** EPITECH PROJECT, 2021
** C Pool Day 08
** File description:
** task 01
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;
    int len = my_strlen(src);

    dest = malloc(sizeof(char) * (len + 1));
    while (i < len) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
