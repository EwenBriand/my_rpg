/*
** EPITECH PROJECT, 2022
** ewen
** File description:
** struct
*/

#ifndef F9C0CC17_CC2E_4697_A288_7F066C90954A
#define F9C0CC17_CC2E_4697_A288_7F066C90954A

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct stat_s {
    int pv;
    int pv_max;
    int att_phy;
    int def_phy;
    int att_ma;
    int def_ma;
} stat_t;

typedef struct objet_s {
    char *name;
    int stack;
    int type;
    stat_t *stat;
} objet_t;

typedef struct inv_s {
    int nb_obj_max;
    int nb_obj;
    objet_t **inv;
} inv_t;

typedef struct equip_s {
    objet_t *head;
    objet_t *body;
    objet_t *leg;
    objet_t *weapon;
    objet_t *gauntlet;
    objet_t *neck;
    objet_t *shoulder;
    objet_t *foot;
} equip_t;

typedef struct sort_s {
    int po;
    int dmg;
    char *name;
    char *description;
} sort_t;

typedef struct pnj_s {
    char *name;
    int id;
    int finish;
    int avancement;
    char **replique;
    int credits;
    int xp;
    int type;
    char *obj;
    int nb_obj;
} pnj_t;

typedef struct personnage_s {
    int druide;
    int bucheron;

    stat_t *stat;
    inv_t *inv;
    equip_t *equip;
    sort_t **list_sort;

    char *pseudo;
    int xp;
    int level;
    int xp_supp;
    int credits;
} personnage_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfImage *image;
    sfTexture *texture;
    sfIntRect *rect;
} sprite_t;

typedef struct map_s {
    int **map;
    int size_x;
    int size_y;
    int *pos;
    sprite_t *background;
} map_t;

typedef struct charter_s {
    sprite_t *sprite;
    int *pos;
    int *exep;
    float rota;
} charter_t;

typedef struct pnj_scene_s {
    sprite_t *textbox;
    sfText *name;
    sfText *replique;
    sfFont *font;
} pnj_scene_t;

typedef struct set_clock {
    sfClock *clock;
    sfTime time;
    sfVector2f offset;
} set_clock_t;

typedef struct texte_t {
    sfText *text;
    sfFont *font;
    sfVector2f place;
} text_shop;

typedef struct set_inv_shop {
    int prize;
    char *name;
    int place;
} inv_shop;

typedef struct shop_s {
    sprite_t back;
    sprite_t *items;
    sprite_t *grey;
    sprite_t *green;
    sprite_t *red;
    sprite_t *coins;
    inv_shop *items_shop;
    text_shop *text;
    set_clock_t clock1;
    double seconds1;
    set_clock_t clock2;
    double seconds2;
    sfVector2i posi_mouse;
} shop_t;

typedef struct enemy_s {
    sprite_t *sprite;
    stat_t *stats;
} enemy_t;

typedef struct fight_s {
    sfVertexArray *slash;
    sfVertexArray *smoke;
    sprite_t *back;
    enemy_t **enemy;
    sfText *text;
    sfText *hp;
    int status;
    int venin;
    char *string;
} fight_t;

typedef struct bestiaire_s {
    char *string;
    sfText *stat_enemy;
    sprite_t *enemy1;
    sprite_t *enemy2;
    sprite_t *back;
} bestiaire_t;

typedef struct minimap_s {
    sprite_t *map1;
    sprite_t *map2;
    int which_map;
} minimap_t;

typedef struct game_s {
    sprite_t *the_end;
    sprite_t *resume_btn;
    sprite_t *quit_btn;
    pnj_t **all_pnj;
    pnj_scene_t *pnj_scene;
    objet_t **all_objets;
    personnage_t *perso;
    charter_t *charter;
    map_t *map;
    fight_t *fight;
    shop_t shop;
    sfRenderWindow *window;
    sfClock *clock;
    sfMusic *level_up_sound;
    sfMusic *quest_complete_sound;
    sfMusic *fireworks;
    sfVertexArray **particule_array;
    minimap_t *minimap;
    bestiaire_t *best;
    int state;
    int input;
    int nb_fight;
    int mobs;
    int chest;
} game_t;

#endif