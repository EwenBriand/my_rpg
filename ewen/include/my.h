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
static const int NB_OBJECTS = 13;
static const int INV_SIZE = 20;
static const int NB_SORTS = 3;
static const int NB_PNJ = 5;

int my_strlen_int(int nb);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
int my_putstr(char const *str);
void my_putnbr(int nb);
void my_putchar(char c);
char *get_buffer(char const *file);
int my_strcmp(char *comp1, char *comp2);
int my_atoi(char *str);

pnj_t **init_pnjs(void);
stat_t *empty_stat(void);
game_t *creat_my_game(void);
personnage_t *init_perso(void);
objet_t **init_all_objects(void);
charter_t *create_charter(char *path, int *pos);
sprite_t *create_sprite(char *path, int *p, int *position);
sfIntRect *create_rect(int top, int left, int width, int height);
map_t *create_map(char *path, int *pos, char *path_int, int *start);

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
void interaction(game_t *game, sfEvent event);

int is_in_inv(game_t *game, char *name);
void add_object_in_inv(game_t *game, char *name, int nb);
void del_object_in_inv(game_t *game, char *name, int nb);

#endif
