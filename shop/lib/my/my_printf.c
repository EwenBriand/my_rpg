/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** main file
*/

#include "my.h"

void display_arg_bis(char type, va_list ap)
{
    switch (type) {
    case 'X': my_printf("%s", min_hexa(va_arg(ap, int), 'X'));
        break;
    case '%': my_putchar('%');
        break;
    case 'P': my_putstr(va_arg(ap, char*));
        break;
    default: my_printf("ERROR\n");
    }
}

void display_arg(char type, va_list ap)
{
    switch (type) {
    case 's': my_putstr(va_arg(ap, char*));
        break;
    case 'i': my_put_nbr(va_arg(ap, int));
        break;
    case 'c': my_putchar(va_arg(ap, int));
        break;
    case 'd': my_put_nbr(va_arg(ap, long int));
        break;
    case 'o': my_printf("%i", octal(va_arg(ap, int)));
        break;
    case 'x': my_printf("%s", min_hexa(va_arg(ap, int), 'x'));
        break;
    case 'b': my_printf("%i", binary(va_arg(ap, int)));
        break;
    default: display_arg_bis(type, ap);
    }
}

int my_printf(const char *format, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            display_arg(format[i + 1], ap);
            i += 2;
        } else {
            my_putchar(format[i]);
            i += 1;
        }
    }
    va_end(ap);
    return 0;
}
