/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** tel_the_story
*/

#include <stdlib.h>
#include "my.h"

static char *setup_text(sfText *text, sfFont *font)
{
    char *string = my_strcat(
        "The story is a bit long, but it's a good one.\nThere is a "
        "crash,there are many advanced technology\nand different "
        "species...\nIt's an incredible story even better than star wars "
        "I swear\nBut "
        "like i said before, it's a bit long.\nSo it's not the story you "
        "will "
        "play\nBut don't worry there is a crash too but for more "
        "coherence in "
        "the universes\nthe rifle of the player has miraculously "
        "broken\n\nGood luck",
        "\n");

    sfText_setFont(text, font);
    sfText_setColor(text, (sfColor){174, 174, 174, 255});
    sfText_setPosition(text, (sfVector2f){300, 310});
    sfText_setString(text, string);
    return string;
}

static void story_event(sfRenderWindow *window, int *status)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)
            || sfKeyboard_isKeyPressed(sfKeyEnter))
            *status = 1;
    }
}

static void show_the_story(
    sfRenderWindow *window, sfText *text, sprite_t *back)
{
    int status = 0;

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, back->sprite, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window) && status == 0)
        story_event(window, &status);
}

static void destroy_the_story(
    sfText *text, sfFont *font, sprite_t *back, char *string)
{
    destroy_sprite(back);
    sfText_destroy(text);
    sfFont_destroy(font);
    free(string);
}

void tel_the_story(sfRenderWindow *window)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/pixelart.TTF");
    char *string = setup_text(text, font);
    sprite_t *back = create_sprite(
        "sprites/beg.png", (int[4]){0, 0, 1000, 600}, (int[2]){0, 0});

    sfSprite_setScale(back->sprite, (sfVector2f){2, 2});
    show_the_story(window, text, back);
    destroy_the_story(text, font, back, string);
}
