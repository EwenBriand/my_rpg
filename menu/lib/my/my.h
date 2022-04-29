/*
** EPITECH PROJECT, 2021
** myh
** File description:
** task02
*/

#ifndef _hoppy_H_
#define _hoppy_H_

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Export.h>
#include <stddef.h>
#include <time.h>
#include "defender.h"

int my_printf(char const *str, ...);
char my_putchar(char c);
char *my_strdup(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_revstr(char *str);
int arl(char **array);
int wl(char *str);
char **my_str_to_word_array(char *str);

void open_window(mouse_poss_t *poss, window_t *var_wind);
play_btn_t *button(sfRenderWindow *window);
void display_image(window_t *var_wind, sfSprite *sprite, mouse_poss_t *poss);
void press_play(mouse_poss_t *poss, play_btn_t *var);
exit_btn_t *exit_btn(sfRenderWindow *window);
option_btn_t *option_btn(sfRenderWindow *window);
how_play_btn_t *how_play_btn(sfRenderWindow *window);
void get_poss_mouse(window_t *var_wind);


#endif