/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** librairie getnbr
*/

#include "my.h"

int neg(char const *str, int i)
{
    if (str[i] == '-') {
        if (str[i + 1] >= 48 && str[i + 1] <= 48 +9)
            return 1;
    } else
        return 0;
}

int number(char const *str, int i)
{
    int nbr = 0;
    int neg = 0;

    if (str[i] == '-') {
        neg = 1;
        i += 1;
    }
    while (str[i] >= 48 && str[i] <= 48 + 9) {
        nbr = nbr * 10 + (str[i] - '0');
        i += 1;
    }
    if (neg == 1)
        nbr = nbr * (-1);
    return nbr;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int stop = 0;

    while (stop != 1) {
        if (str[i] == '\0')
            stop = 1;
        else if ((str[i] < 48 || str[i] > 48 + 10) && neg(str, i) == 0)
            i += 1;
        else
            return number(str, i);
    }
    return 0;
}
