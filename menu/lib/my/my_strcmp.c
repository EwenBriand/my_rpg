/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** task06
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int length = my_strlen(s1);
    int comparator;

    if (my_strlen(s1) < my_strlen(s2))
        length = my_strlen(s2);

    for (int i = 0; i < length; i++) {
        if (s1[i] != s2[i]) {
            comparator = s1[i] - s2[i];
            return (1);
        }
    }

    return (0);
}
