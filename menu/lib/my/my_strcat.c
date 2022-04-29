/*
** EPITECH PROJECT, 2021
** strcat
** File description:
** strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int count = 0;
    int i = my_strlen(dest);
    for (i; src[count] != '\0'; i++) {
        dest[i] = src[count];
        count++;
    }
    dest[i] = '\0';
    return (dest);
}