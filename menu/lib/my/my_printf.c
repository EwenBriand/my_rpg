/*
** EPITECH PROJECT, 2021
** Semestre1_project
** File description:
** my_printf.c
*/

#include "my.h"

int my_printf(char const *str, ...)
{
    va_list list;
    va_start(list, str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i++;
            switch (str[i]) {
            case 'i':
            case 'd': my_put_nbr(va_arg(list, int)); break;
            case 'c': my_putchar(va_arg(list, int)); break;
            case 's': my_putstr(va_arg(list, char *)); break;
            default: break;
            }
        } else
            my_putchar(str[i]);
    }
    va_end(list);
    return 0;
}