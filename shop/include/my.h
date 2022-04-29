/*
** EPITECH PROJECT, 2021
** headers file
** File description:
** global file
*/

if (sfKeyboard_isKeyPressed(sfKeyE))
open_shop(window, game);

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


typedef struct stat_s {
    int pv;
    int pv_max;
    int att_phy;
    int def_phy;
    int att_ma;
    int def_ma;
    int pm; // PM = 3
}stat_t;

typedef struct obj_stat_s {
    int pv;
    int att_phy;
    int def_phy;
    int att_ma;
    int def_ma;
}obj_stat_t;

typedef struct objet_s {
    char *name;
    int type; // 0 = equipement on prend en compte stat; 1 = potion (+ 20 PV); 2 = antidote; 3 = objet de quete
    obj_stat_t *stat;
}objet_t;

typedef struct inv_s {
    int nb_obj_max;
    int nb_obj;
    objet_t **inv;
}inv_t;

typedef struct equip_s {
    objet_t *head;
    objet_t *body;
    objet_t *leg;
    objet_t *weapon;
    objet_t *gauntlet;
    objet_t *neck;
    objet_t *soulder;
    objet_t *foot;
}equip_t;

typedef struct sort_s {
    int po;
    int dmg;
    char *name;
    char *desc;
}sort_t;

typedef struct personnag_s {
    int druide;
    int bucheron;

    stat_t stat;
    inv_t *inv;
    equip_t *equip;
    sort_t **list_sort;

    char *pseudo;
    int xp;
    int level;
    int xp_supp;
    int credits;
} personnag_t;

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

typedef struct set_music {
    sfMusic *music;
} set_music_t;

typedef struct set_inv_shop {
    int prize;
    char *name;
    int place;
} inv_shop;

typedef struct texte_t {
    sfText *text;
    sfFont *font;
    sfVector2f place;
} text_shop;

typedef struct draw_sprite {
    set_texture_t default_t;
    set_sprite_t default_s;
    set_texture_t back_shop_t;
    set_sprite_t back_shop_s;
    set_texture_t item_t;
    set_sprite_t item_s;
    set_sprite_t *shop;
    set_sprite_t *grey;
    set_sprite_t *green;
    set_sprite_t *red;
    set_texture_t back_green_t;
    set_texture_t back_red_t;
    set_texture_t back_grey_t;
    set_sprite_t *coins;
    set_texture_t coins_t;
    inv_shop *items_shop;
    text_shop *text;
    set_sprite_t sword_s;
    objet_t potion;
    objet_t antidote;
    set_music_t music_start;
    set_clock_t clock1;
    double seconds1;
    set_clock_t clock2;

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

#endif /* MY_H_ */
