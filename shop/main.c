/*
** EPITECH PROJECT, 2021
** Myrunner
** File description:
** main file
*/

#include <stdio.h>
#include "include/my.h"

void display_h(void)
{
    my_printf("USAGE\n          ./my_rpg\n");
    my_printf("DESCRIPTION\n    this game is RPG game.\n");
    my_printf("         use the help menu in the game to know how to play\n");
}

void create_default_window(setup_t *window)
{
    printf("width%i\n", sfVideoMode_getDesktopMode().width);
    printf("heigt: %i\n", sfVideoMode_getDesktopMode().height);
    window->window_y = 1080;
    window->window_x = 1920;
    window->mode.height = window->window_y;
    window->mode.width = window->window_x;
    window->mode.bitsPerPixel = 64;
    window->window = sfRenderWindow_create(window->mode, "My_rpg_shop",
                                           sfDefaultStyle, NULL);
}

void create_sprite_shop_bis(draw_sprite_t *my_sprite, int i, const float *pos, const int *rect)
{
    my_sprite->shop[i].place = (sfVector2f) {pos[0], pos[1]};
    my_sprite->shop[i].rect = (sfIntRect) {rect[0], rect[1], 95, 95};
    my_sprite->shop[i].s = sfSprite_create();
    sfSprite_setTexture(my_sprite->shop[i].s, my_sprite->item_t.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->shop[i].s, my_sprite->shop[i].rect);
    sfSprite_setPosition(my_sprite->shop[i].s, my_sprite->shop[i].place);
}

void create_sprite_shop(draw_sprite_t *my_sprite)
{
    float pos[2] = {192, 270};
    int rect[][2] = {{380, 480}, {96, 675}, {288, 578}, {0, 0}, {480, 672}, {288, 385}, {192, 675}, {97, 580}, {480, 288}, {672, 288}};

    my_sprite->shop = malloc(sizeof (set_sprite_t ) * 10);
    for (int i = 0; i != 10; i++) {
        create_sprite_shop_bis(my_sprite, i, pos, rect[i]);
        pos[0] += 384;
        if (i == 4) {
            pos[1] = 700;
            pos[0] = 192;
        }
    }
}

void create_sprite_coins(draw_sprite_t *my_sprite)
{
    float pos[2] = {258, 370};

    my_sprite->coins = malloc(sizeof (set_sprite_t) * 10);
    my_sprite->coins_t.t = sfTexture_createFromFile("file/coins.png", NULL);
    for (int i = 0; i != 10; i++) {
        my_sprite->coins[i].place = (sfVector2f) {pos[0], pos[1]};
        my_sprite->coins[i].scale = (sfVector2f) {0.08, 0.08};
        my_sprite->coins[i].rect = (sfIntRect) {250, 100, 380, 380};
        my_sprite->coins[i].s = sfSprite_create();
        sfSprite_setTexture(my_sprite->coins[i].s, my_sprite->coins_t.t, sfTrue);
        sfSprite_setTextureRect(my_sprite->coins[i].s, my_sprite->coins[i].rect);
        sfSprite_setPosition(my_sprite->coins[i].s, my_sprite->coins[i].place);
        sfSprite_setScale(my_sprite->coins[i].s, my_sprite->coins[i].scale);
        pos[0] += 384;
        if (i == 4) {
            pos[1] = 800;
            pos[0] = 258;
        }
    }
}

void create_sprite_color(set_sprite_t *sprite, sfTexture *texture)
{
    float pos[2] = {192, 370};

    for (int i = 0; i != 10; i++) {
        sprite[i].place = (sfVector2f) {pos[0], pos[1]};
        sprite[i].rect = (sfIntRect) {0, 0, 95, 30};
        sprite[i].s = sfSprite_create();
        sfSprite_setTexture(sprite[i].s, texture, sfTrue);
        sfSprite_setTextureRect(sprite[i].s, sprite[i].rect);
        sfSprite_setPosition(sprite[i].s, sprite[i].place);
        pos[0] += 384;
        if (i == 4) {
            pos[1] = 800;
            pos[0] = 192;
        }
    }
}

void create_sprite_prize(draw_sprite_t *my_sprite)
{
    my_sprite->grey = malloc(sizeof (set_sprite_t) * 10);
    my_sprite->red = malloc(sizeof (set_sprite_t) * 10);
    my_sprite->green = malloc(sizeof (set_sprite_t) * 10);
    my_sprite->back_grey_t.t = sfTexture_createFromFile("file/back_grey.jpg", NULL);
    my_sprite->back_green_t.t = sfTexture_createFromFile("file/back_green.jpg", NULL);
    my_sprite->back_red_t.t = sfTexture_createFromFile("file/back_red.jpg", NULL);
    create_sprite_color(my_sprite->grey, my_sprite->back_grey_t.t);
    create_sprite_color(my_sprite->green, my_sprite->back_green_t.t);
    create_sprite_color(my_sprite->red,  my_sprite->back_red_t.t);
    create_sprite_coins(my_sprite);
}

char *itoa(int nbr)
{
    char *str = malloc(sizeof (char ) * 5);
    int i = 0;
    while (nbr >= 10) {
        str[i] = (char)((nbr % 10) + '0');
        nbr = nbr / 10;
        i += 1;
    }
    str[i] = (char)(nbr + '0');
    str[i + 1] = '\0';
    return my_revstr(str);
}

void create_sprite_text(draw_sprite_t *my_sprite) {
    float pos[2] = {210, 370};
    sfFont *font = sfFont_createFromFile("file/arial.ttf");
    char *str;
    my_sprite->text = malloc(sizeof (text_shop) * 10);

    for (int i = 0; i != 10; i++) {
        my_sprite->text[i].text = sfText_create();
        my_sprite->text[i].place = (sfVector2f) {pos[0], pos[1]};
        str = itoa(my_sprite->items_shop[i].prize);
        sfText_setString(my_sprite->text[i].text, str);
        sfText_setFont(my_sprite->text[i].text, font);
        sfText_setCharacterSize(my_sprite->text[i].text, 24);
        sfText_setPosition(my_sprite->text[i].text, my_sprite->text[i].place);
        pos[0] += 384;
        if (i == 4) {
            pos[1] = 800;
            pos[0] = 210;
        }
    }
}


void initial_shop(inv_shop *item_shop, char *name, int prize, int place)
{
    item_shop->place = place;
    item_shop->prize = prize;
    item_shop->name = name;
}

void make_shop(draw_sprite_t *my_sprite)
{
    my_sprite->items_shop = malloc(sizeof (inv_shop) * 10);
    initial_shop(&my_sprite->items_shop[0], "head", 80, 1);
    initial_shop(&my_sprite->items_shop[1], "body", 150, 2);
    initial_shop(&my_sprite->items_shop[2], "leg", 80, 3);
    initial_shop(&my_sprite->items_shop[3], "weapon", 80, 4);
    initial_shop(&my_sprite->items_shop[4], "gauntlet", 80, 5);
    initial_shop(&my_sprite->items_shop[5], "neck", 80, 6);
    initial_shop(&my_sprite->items_shop[6], "shoulder", 80, 7);
    initial_shop(&my_sprite->items_shop[7], "foot", 80, 8);
    initial_shop(&my_sprite->items_shop[8], "potion", 20, 9);
    initial_shop(&my_sprite->items_shop[9], "antidote", 30, 10);
}

void create_sprite_default(draw_sprite_t *my_sprite)
{
    my_sprite->default_t.t = sfTexture_createFromFile("file/default.jpg", NULL);
    my_sprite->default_s.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->default_s.s, my_sprite->default_t.t, sfTrue);

    my_sprite->back_shop_s.scale = (sfVector2f) {5, 3};
    my_sprite->back_shop_t.t = sfTexture_createFromFile("file/back.jpg", NULL);
    my_sprite->back_shop_s.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->back_shop_s.s, my_sprite->back_shop_t.t, sfTrue);
    sfSprite_setScale(my_sprite->back_shop_s.s, my_sprite->back_shop_s.scale);

    my_sprite->item_t.t = sfTexture_createFromFile("file/items.png", NULL);
    my_sprite->item_s.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->item_s.s, my_sprite->item_t.t, sfTrue);

    create_sprite_shop(my_sprite);
    create_sprite_prize(my_sprite);
    make_shop(my_sprite);
    create_sprite_text(my_sprite);
}

void initial(setup_t *window, draw_sprite_t *my_sprite, personnag_t *player)
{
    window->map = 0;
    player->stat.pm = 3;
    player->credits = 170;
    my_sprite->clock1.clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(window->window, 60);
}

void check_close(setup_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
    }
}

void click_open_shop(setup_t *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && window->map == 0)
        window->map = 10;
    else if (sfKeyboard_isKeyPressed(sfKeyEscape) && window->map == 10)
        window->map = 0;
}

void display_home(setup_t *window, draw_sprite_t *my_sprite)
{
    sfRenderWindow_drawSprite(window->window, my_sprite->default_s.s, NULL);
    click_open_shop(window);
}

void display_color(setup_t *window, draw_sprite_t *my_sprite, set_sprite_t sprite, int i)
{
    sfRenderWindow_drawSprite(window->window, sprite.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->coins[i].s, NULL);
    sfRenderWindow_drawText(window->window, my_sprite->text[i].text, NULL);
}

void check_buy(setup_t *window, draw_sprite_t *my_sprite, const int nbrs[5], personnag_t *player)
{
    sfVector2i mouse = window->posi_mouse;
    my_sprite->clock1.time = sfClock_getElapsedTime(my_sprite->clock1.clock);
    my_sprite->seconds1 = (double) my_sprite->clock1.time.microseconds / 1000000.0;
    if (mouse.x >= nbrs[1] && mouse.x <= nbrs[2] && mouse.y >= nbrs[3] && mouse.y <= nbrs[4] && window->event.type == sfEvtMouseButtonPressed) {
        if (my_sprite->seconds1 > 1) {
            player->credits -= my_sprite->items_shop[nbrs[0]].prize;
            sfClock_restart(my_sprite->clock1.clock);
        }
    }
}

void check_money(setup_t *window, draw_sprite_t *my_sprite, personnag_t *player, int nbrs[5])
{
    nbrs[3] += 100;
    if (my_sprite->items_shop[nbrs[0]].prize <= player->credits) {
        display_color(window, my_sprite, my_sprite->green[nbrs[0]], nbrs[0]);
        check_buy(window, my_sprite, nbrs, player);
    } else
        display_color(window, my_sprite, my_sprite->red[nbrs[0]], nbrs[0]);
}

void display_button(setup_t *window, sfVector2i mouse, draw_sprite_t *my_sprite, personnag_t *player)
{
    int nbrs[5] = {0, 192, 287, 270, 400};

    for (; nbrs[0] != 10; nbrs[0]++) {
        if (mouse.x >= nbrs[1] && mouse.x <= nbrs[2] && mouse.y >= nbrs[3] && mouse.y <= nbrs[4])
            check_money(window, my_sprite, player, nbrs);
        nbrs[1] += 384;
        nbrs[2] += 384;
        if (nbrs[0] == 4) {
            nbrs[3] = 700;
            nbrs[4] = 830;
            nbrs[1] = 192;
            nbrs[2] = 287;
        }
    }
}

void display_shop(setup_t *window, draw_sprite_t *my_sprite, personnag_t *player)
{
    window->posi_mouse = sfMouse_getPositionRenderWindow(window->window);
    sfRenderWindow_drawSprite(window->window, my_sprite->back_shop_s.s, NULL);
    for (int i = 0; i != 10; i++) {
        sfRenderWindow_drawSprite(window->window, my_sprite->shop[i].s, NULL);
        display_color(window, my_sprite, my_sprite->grey[i], i);
    }
    display_button(window ,window->posi_mouse, my_sprite, player);
    click_open_shop(window);
}

void destroy(setup_t *window)
{
    sfRenderWindow_destroy(window->window);
}

void display_map(setup_t *window, draw_sprite_t *my_sprite, personnag_t *player)
{
    switch (window->map) {
        case 0: display_home(window, my_sprite);
        break;
        case 10: display_shop(window, my_sprite, player);
        break;
    }
}

void default_start(setup_t window, draw_sprite_t my_sprite, personnag_t player)
{
    initial(&window, &my_sprite, &player);
    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_clear(window.window, sfBlack);
        check_close(&window);
        display_map(&window, &my_sprite, &player);
        sfRenderWindow_display(window.window);
    }
    destroy(&window);
}

void my_rpgshop(void)
{
    setup_t window;
    draw_sprite_t my_sprite;
    personnag_t player;

    create_default_window(&window);
    create_sprite_default(&my_sprite);
    default_start(window, my_sprite, player);
}

int main(int ac, char **argv)
{
    if (ac == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            display_h();
        else
            return 84;
    } else if (ac != 1)
        return 84;
    else
        my_rpgshop();
    return 0;
}
