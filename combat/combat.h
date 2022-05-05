/*
** EPITECH PROJECT, 2022
** combat.h
** File description:
** combat.h
*/

#ifndef COMBAT_H
    #define COMBAT_H

typedef struct player_s {
    /*sfTexture player;
    sfSprite player_sprite;
    sfVector2f player_pos;
    sfVector2f player_scale;
    sfEvent event;*/
    int hp;
    int mp;
    int ep;
    int pa;
    int ma;
    int damage;
    int poison;
    int turn;
} player_t;

typedef struct champigoule_s {
    /*sfTexture champi;
    sfSprite champi_sprite;
    sfVector2f champi_pos;
    sfVector2f champi_scale;
    sfEvent event;*/
    int nb;
    int *hp;
    int mp;
    int pa;
    int ma;
    int damage;
    int poison;
} champigoule_t;

typedef struct vampivol_s {
    /*sfTexture vampi;
    sfSprite vampi_sprite;
    sfVector2f vampi_pos;
    sfVector2f vampi_scale;
    sfEvent event;*/
    int nb;
    int *hp;
    int mp;
    int pa;
    int ma;
    int maxhp;
    int damage;
    int lifesteal;
} vampivol_t;

typedef struct magivol_t {
    /*sfTexture magi;
    sfSprite magi_sprite;
    sfVector2f magi_pos;
    sfVector2f magi_scale;
    sfEvent event;*/
    int nb;
    int *hp;
    int mp;
    int pa;
    int ma;
    int magic_damage;
} magivol_t;

typedef struct rochexplosif_s {
    /*sfTexture roche;
    sfSprite roche_sprite;
    sfVector2f roche_pos;
    sfVector2f roche_scale;
    sfEvent event;*/
    int nb;
    int *hp;
    int mp;
    int pa;
    int ma;
    int damage;
    int explosion;
} rochexplosif_t;

typedef struct combat_s {
    /*sfTexture combat;
    sfSprite combat_sprite;
    sfVector2f combat_pos;
    sfVector2f combat_scale;
    sfEvent event;*/
    creature_t *creature;
} combat_t;

typedef struct creature_s;
{
    int type;
    champigoule_t *champigoule;
    vampivol_t *vampivol;
    magigoule_t *magivol;
    rochexplosif_t *rochexplosif;
} creature_t;