/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** setup my_putchar
*/

#include <unistd.h>

char my_putchar(char c)
{
    write(1, &c, 1);
}
