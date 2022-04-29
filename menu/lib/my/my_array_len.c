/*
** EPITECH PROJECT, 2021
** Semestre_project
** File description:
** my_array_len.c
*/

#include "my.h"

int arl(char **array)
{
    int i = 0;
    while (array[i]) {
        i++;
    }

    return i;
}