/*
** EPITECH PROJECT, 2021
** Task03 - my_strlen.c
** File description:
** abc
*/


int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;

    return (i);
}