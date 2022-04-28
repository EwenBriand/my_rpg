/*
** EPITECH PROJECT, 2021
** Binary
** File description:
** convert decimal to binary
*/

#include "my.h"

int binary_bis(int x, int i, int nb)
{
    while (x > 0) {
        nb = nb * 10 + x % 10;
        x = x / 10;
    }
    while (i > 0) {
        nb = nb * 10;
        i -= 1;
    }
    return nb;
}

int binary(int nb)
{
    int x = 0;
    int i = 0;

    while (nb % 2 == 0 && nb != 0) {
        i += 1;
        nb = nb / 2;
    }
    while (nb >= 2) {
        x = x * 10 + nb % 2;
        nb = nb / 2;
    }
    x = x * 10 + nb;
    nb = 0;
    return binary_bis(x, i, nb);
}
