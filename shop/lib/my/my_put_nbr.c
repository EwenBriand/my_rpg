/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** librairie my_put_nbr
*/

#include "my.h"

int put_nbr_bis(int nb, int x, int i)
{
    while (nb > 0) {
        x = (x * 10) + (nb % 10);
        nb = nb / 10;
    }
    while (x > 0) {
        my_putchar((x % 10) + 48);
        x = x / 10;
    }
    while (i > 0) {
        my_putchar(48);
        i -= 1;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    int i = 0;
    long x = 0;

    if (nb == 0) {
        my_putchar(48);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    while (nb > 0 && nb % 10 == 0) {
        i += 1;
        nb = nb / 10;
    }
    return put_nbr_bis(nb, x, i);
}
