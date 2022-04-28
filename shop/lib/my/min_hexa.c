/*
** EPITECH PROJECT, 2021
** Hexa
** File description:
** convert decimal into hexadecimal
*/

#include "my.h"

char display_valuex(int nb)
{
    switch (nb) {
    case 10: return 'a';
    case 11: return 'b';
    case 12: return 'c';
    case 13: return 'd';
    case 14: return 'e';
    case 15: return 'f';
    default: return nb + '0';
    }
}

char display_value_x(int nb)
{
    switch (nb) {
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    default: return nb + '0';
    }
}

char* min_hexa(int nb, char c)
{
    char *x = malloc(sizeof(char) * 1);
    int j = 0;
    int i = 1;

    if (nb % 16 == 0)
        i = 0;
    while (nb >= 16) {
        if (c == 'x')
            x[j] = display_valuex(nb % 16);
        else
            x[j] = display_value_x(nb % 16);
        nb = nb / 16;
        j += 1;
    }
    if (c == 'x')
        x[j] = display_valuex(nb);
    else
        x[j] = display_value_x(nb);
    x[j + 1] = '\0';
    return my_revstr(x);
}
