/*
** EPITECH PROJECT, 2021
** 2_Semestre
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void display_all(sfRenderWindow *window, sfSprite *sprite,
    sfSprite *exit_sprite, sfSprite *option_sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, exit_sprite, NULL);
    sfRenderWindow_drawSprite(window, option_sprite, NULL);
}

static void menu_event(
    window_t *var_wind, int *status, play_btn_t *var, exit_btn_t *exite)
{
    while (sfRenderWindow_pollEvent(var_wind->window, &var_wind->event)) {
        if (var_wind->event.type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape))
            *status = 1;
        if (var_wind->event.type == sfEvtMouseButtonPressed)
            *status = clickable_btn(var_wind, var, exite, *status);
    }
}

void display_image(window_t *var_wind, sfSprite *sprite, int *status)
{
    play_btn_t *var = button();
    exit_btn_t *exite = exit_btn();
    option_btn_t *option = option_btn();
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/pixelart.TTF");
    setup_text_menu(text, font);
    while (sfRenderWindow_isOpen(var_wind->window) && *status == 0) {
        display_all(
            var_wind->window, sprite, exite->play_sprite, option->play_sprite);
        sfRenderWindow_drawSprite(var_wind->window, var->play_sprite, NULL);
        menu_event(var_wind, status, var, exite);
        sfRenderWindow_drawText(var_wind->window, text, NULL);
        sfRenderWindow_display(var_wind->window);
    }
    sfText_destroy(text);
    sfFont_destroy(font);
}

void open_window(window_t *var_wind)
{
    int status = 0;
    var_wind->vid_mod = (sfVideoMode){1920, 1080, 32};
    var_wind->window = sfRenderWindow_create(
        var_wind->vid_mod, "My RPG", sfDefaultStyle, NULL);
    sfTexture *texture =
        sfTexture_createFromFile("ressources/plaine.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f my_pos = {0.f, 0.f};
    sfVector2f scale = {1.7, 1.7};
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, my_pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_setFramerateLimit(var_wind->window, 30);
    display_image(var_wind, sprite, &status);
    if (status == 2)
        start_game(var_wind->window);
    else
        sfRenderWindow_close(var_wind->window);
    sfRenderWindow_destroy(var_wind->window);
}

int main(int ac, char **av, char **env)
{
    if (env[0] == NULL)
        return ERROR_VALUE;
    sfMusic *music = sfMusic_createFromFile("music/music.ogg");
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    window_t *var_wind = malloc(sizeof(window_t));
    open_window(var_wind);
    sfMusic_destroy(music);
    return END_VALUE;
}
