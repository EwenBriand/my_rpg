/*
** EPITECH PROJECT, 2021
** 2_Semestre
** File description:
** main.c
*/

#include "my.h"

static sfRenderWindow *create_renderwindow(window_t *var_wind, unsigned int x,
                                           unsigned int y, unsigned int bpp)
{
    char *title;
    var_wind->vid_mod = (sfVideoMode){ x, y, bpp };
    return (sfRenderWindow_create(var_wind->vid_mod, title, sfResize | sfClose,
                                  NULL));
}

void display_image(window_t *var_wind, sfSprite *sprite, mouse_poss_t *poss)
{
    play_btn_t *var = button(var_wind->window);
    exit_btn_t *exite = exit_btn(var_wind->window);
    option_btn_t *option = option_btn(var_wind->window);
    how_play_btn_t *htp = how_play_btn(var_wind->window);
    while (sfRenderWindow_isOpen(var_wind->window)) {
        sfRenderWindow_clear(var_wind->window, sfBlack);
        sfRenderWindow_drawSprite(var_wind->window, sprite, NULL);
        sfRenderWindow_drawSprite(var_wind->window, var->play_sprite, NULL);
        sfRenderWindow_drawSprite(var_wind->window, exite->play_sprite, NULL);
        sfRenderWindow_drawSprite(var_wind->window, option->play_sprite, NULL);
        sfRenderWindow_drawSprite(var_wind->window, htp->play_sprite, NULL);
        poss->mouse_poss = sfMouse_getPositionRenderWindow(var_wind->window);
        while (sfRenderWindow_pollEvent(var_wind->window, &var_wind->event)) {
            if (var_wind->event.type == sfEvtClosed) {
                sfRenderWindow_close(var_wind->window);
            }
            press_play(poss, var);
        }
        sfRenderWindow_display(var_wind->window);
    }
}

void open_window(mouse_poss_t *poss, window_t *var_wind)
{
    var_wind->vid_mod = (sfVideoMode){ 1920, 1080, 32 };
    var_wind->window = sfRenderWindow_create(var_wind->vid_mod, "My RPG", sfDefaultStyle, NULL);
    sfTexture *texture = sfTexture_createFromFile("ressources/plaine.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f my_pos = { 0.f,0.f };
    sfVector2f scale = { 1.7, 1.7 };
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, my_pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_setFramerateLimit(var_wind->window, 30);
    display_image(var_wind, sprite, poss);
}

void main(int ac, char **av)
{
    window_t *var_wind = malloc(sizeof(window_t));
    mouse_poss_t *poss = malloc(sizeof(mouse_poss_t));
    open_window(poss, var_wind);
}
