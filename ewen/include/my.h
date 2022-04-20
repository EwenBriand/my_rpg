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
char *get_buffer(char const *file);
int my_atoi(char *str);

game_t *creat_my_game(void);
personnage_t *init_perso(void);
sprite_t *create_sprite(char *path, int *p, int *position);
map_t *create_map(char *path, int *pos, char *path_int, int *start);
sfIntRect *create_rect(int top, int left, int width, int height);
charter_t *create_charter(char *path, int *pos);

void my_event(sfRenderWindow *window, game_t *game);

void update_charter(game_t *game);
void update_map(map_t *map, sfRenderWindow *window, game_t *game);

int give_type(game_t *game);
void move_static_charter(game_t *game, sfRenderWindow *window);
void change_charter(game_t *game, int type);
void move_map(map_t *map, sfRenderWindow *window, game_t *game);
void move_map_vert(map_t *map, sfRenderWindow *window, game_t *game);
void move_map_hor(map_t *map, sfRenderWindow *window, game_t *game);

void make_interaction(game_t *game, int code);

#endif
