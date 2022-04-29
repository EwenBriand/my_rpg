/*
** EPITECH PROJECT, 2021
** solostumper01
** File description:
** my_strcmp.c
*/

#include "my.h"
#include "stddef.h"

int my_strcmp(char *comp1, char *comp2)
{
    int i = 0;
    if (comp1 == NULL || comp2 == NULL)
        return 0;
    while (comp1[i] != '\0' || comp2[i] != '\0') {
        if (comp1[i] != comp2[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}
