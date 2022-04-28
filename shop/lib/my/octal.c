/*
** EPITECH PROJECT, 2021
** Octalbase
** File description:
** convert decimal number into octal number
*/

#include "my.h"

int octal(int nb)
{
    int x = 0;
    int i = 1;

    if (nb % 8 == 0)
        i += 1;
    while (nb >= 8) {
        x = x * 10 + nb % 8;
        nb = nb / 8;
    }
    x = x * 10 + nb;
    nb = 0;
    while (x > 0) {
        nb = nb * 10 + x % 10;
        x = x / 10;
    }
    if (i == 0)
        nb = nb * 10;
    return nb;
}
