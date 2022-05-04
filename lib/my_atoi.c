/*
** EPITECH PROJECT, 2022
** truc
** File description:
** my_atoi
*/

#include "../include/my.h"

float my_power(int nb, int power)
{
    float result = 1;
    if (power == 0)
        return result;
    if (power > 0)
        for (int i = 0; i < power; ++i)
            result *= nb;
    else
        for (int i = 0; i < power; ++i)
            result /= nb;
    return result;
}

int my_atoi(char *str)
{
    int result = 0;
    int pow = 0;
    my_revstr(str);
    for (int i = 0; i < my_strlen(str); ++i) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        result += (str[i] - '0') * my_power(10, pow);
        ++pow;
    }
    my_revstr(str);
    return result;
}
