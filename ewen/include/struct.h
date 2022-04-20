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
#include <SFML/System.h>
#include <SFML/Window.h>

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
    int type; // 0 = equipement on prend en compte stat; 1 = potion (+ 20 PV);
              // 2 = antidote; 3 = objet de quete; 4 = baie; 5 = bois
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
    objet_t *soulder;
    objet_t *foot;
} equip_t;

typedef struct sort_s {
    int po;
    int dmg;
    char *name;
    char *description;
} sort_t;

typedef struct pnj_s {
    int finish;
    int avancement;
    char **replique;
    int credits;
    int xp;
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
    sfTexture *texture;
    sfImage *image;
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

typedef struct game_s {
    pnj_t **all_pnj;
    objet_t **all_objets;
    personnage_t *perso;
    charter_t *charter;
    map_t *map;
    sfRenderWindow *window;
    sfClock *clock;
    int state;
    int input;
    int fight;
} game_t;

#endif
