/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** librairie my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
