/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** librairie my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
