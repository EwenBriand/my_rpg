/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** task03
*/

#include "my.h"

char *my_revstr(char *str)
{
    int lenght = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i < (lenght + 1) / 2; i++) {
        temp = str[i];
        str[i] = str[lenght - i];
        str[lenght - i] = temp;
    }

    return (str);
}
