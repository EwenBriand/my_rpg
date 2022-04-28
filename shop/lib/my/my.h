/*
** EPITECH PROJECT, 2021
** headers file
** File description:
** global file
*/

#ifndef MY_H_
    #define MY_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <time.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <fcntl.h>

typedef struct set_texture {
    sfTexture *t;
} set_texture_t;

typedef struct set_clock {
    sfClock *clock;
    sfTime time;
    sfVector2f offset;
} set_clock_t;

typedef struct set_sprite {
    sfVector2f place;
    sfSprite *s;
    sfIntRect rect;
    sfVector2f scale;
} set_sprite_t;

typedef struct set_ennemi {
    set_texture_t ennemi_t;
    set_sprite_t ennemi_s;
} set_ennemi;

typedef struct set_music {
    sfMusic *music;
} set_music_t;

typedef struct draw_sprite {
    set_texture_t start_t;
    set_sprite_t start_s;
    set_texture_t back_t;
    set_sprite_t back_s;
    set_texture_t bg_decor_t;
    set_sprite_t bg_decor_s;
    set_texture_t forground_t;
    set_sprite_t forground_s;
    set_texture_t bg_decor2_t;
    set_sprite_t bg_decor2_s;
    set_texture_t forground2_t;
    set_sprite_t forground2_s;
    set_texture_t golem1_t;
    set_sprite_t golem1_s;
    set_texture_t golem2_t;
    set_sprite_t golem2_s;
    set_texture_t golem3_t;
    set_sprite_t golem3_s;
    set_texture_t ground_t;
    set_sprite_t ground_s;
    set_texture_t midle_t;
    set_sprite_t midle_s;
    set_texture_t ground2_t;
    set_sprite_t ground2_s;
    set_texture_t midle2_t;
    set_sprite_t midle2_s;
    set_texture_t sky_t;
    set_sprite_t sky_s;
    set_ennemi *ennemi;
    set_music_t music_start;
    set_clock_t clock1;
    set_clock_t clock2;
    set_clock_t clock3;
    set_clock_t clock4;
    set_clock_t clock5;
    float seconds1;
    float seconds2;
    float seconds3;
    float seconds4;
    float seconds5;
    int golem;
    int nbr_ennemi;
    sfVector2f posi_golem;
    int score;
    int get_score;
    int time_end;
    int up;
} draw_sprite_t;

typedef	struct setup {
    int window_y;
    int window_x;
    int map;
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    sfVector2i posi_mouse;
    sfVector2f posi_g;
    sfVector2f posi_e;
    sfMouseButton button;
} setup_t;

int my_getnbr(char const *str);
int binary(int nb);
char *my_revstr(char *str);
char* min_hexa(int nb, char c);
int octal(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nbr);
int my_strlen(char const *str);
int my_printf(const char *format, ...);
char *my_strdup(char const *src);
void create_sprite_run4(draw_sprite_t *my_sprite);
void create_sprite_run3(draw_sprite_t *my_sprite);
void create_sprite_run2(draw_sprite_t *my_sprite);
void create_sprite_run(draw_sprite_t *my_sprite);
void create_sprite_golem(draw_sprite_t *my_sprite);
void display_map(setup_t *window, draw_sprite_t *my_sprite);
void click_start(setup_t *window, draw_sprite_t *my_sprite);
void clock4(draw_sprite_t *my_sprite);
void clock3(draw_sprite_t *my_sprite);
void clock2(draw_sprite_t *my_sprite);
void clock1(draw_sprite_t *my_sprite);
void moove_ground(set_sprite_t *sprite, int max, float speed);
void moove_golem(draw_sprite_t *my_sprite);
void destroy(setup_t *window, draw_sprite_t *my_sprite);
void gameloop(setup_t *window, draw_sprite_t *my_sprite);
void check_close(setup_t *window);
void game_start(setup_t window, draw_sprite_t my_sprite);
void music_start(draw_sprite_t *music);
void create_sprite_start(draw_sprite_t *my_sprite);
void create_my_window(setup_t *window);
void check_up(setup_t *window, draw_sprite_t *my_sprite);
void create_ennemi(draw_sprite_t *mysprite);
void display_ennemi(setup_t *window, draw_sprite_t *my_sprite);
void moove_ennemi(set_ennemi *sprite, int nbr, float speed);
sfVector2f getposition(draw_sprite_t *my_sprite);
sfVector2f getennemiposi(set_ennemi ennemi);
void check_posi(setup_t *window, draw_sprite_t *my_sprite);
void display_end(setup_t *window, draw_sprite_t *my_sprite);
void display_game(setup_t *window, draw_sprite_t *my_sprite);
void clock5(draw_sprite_t *my_sprite);
char *get_score(int score);

#endif /* MY_H_ */
