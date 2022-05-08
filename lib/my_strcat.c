/*
** EPITECH PROJECT, 2021
** Project Name
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len;
    int pos = 0;
    char *new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    if (new == NULL)
        return (NULL);
    len = my_strlen(dest);
    for (int i = 0; i < len; i++)
        new[pos++] = dest[i];
    len = my_strlen(src);
    for (int i = 0; i < len; i++)
        new[pos++] = src[i];
    new[pos] = '\0';
    return new;
}
