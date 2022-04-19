/*
** EPITECH PROJECT, 2021
** libmy.h
** File description:
** creat the header of the libmy.a
*/

#ifndef _LIBALL_POOL
#define _LIBALL_POOL

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

static const int ERROR_VALUE = 84;
static const int END_VALUE = 0;

int my_strlen_int(int nb);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
int my_putstr(char const *str);
void my_putnbr(int nb);
void my_putchar(char c);

game_t *creat_my_game(sfRenderWindow *window);
sprite_t *create_sprite(
    sfRenderWindow *window, char *path, int *p, int *position);
map_t *create_map(sfRenderWindow *window, char *path, int *pos);
sfIntRect *create_rect(int top, int left, int width, int height);
charter_t *create_charter(sfRenderWindow *window, char *path, int *pos);

#endif
