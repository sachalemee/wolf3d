/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** create_button.c
*/

#include <stdlib.h>
#include "buttons.h"
#include "wolfengine.h"

buttons_t *create_button(sfVector2f pos, sfVector2f size,
    char *title, char *path)
{
    buttons_t *button = malloc(sizeof(buttons_t));
    sfFloatRect bounds = {0};
    sfVector2f origin = {0};

    if (button == NULL)
        return NULL;
    set_button_rect(button, size, pos);
    if (title != NULL) {
        button->font = sfFont_createFromFile(FONT);
        button->title = sfText_create();
        set_button_text(button, title, bounds, origin);
    } else
        button->title = (sfText *){NULL};
    if (path != NULL)
        set_sprite(button, bounds, origin, path);
    else {
        button->texture = (sfTexture *){NULL};
        button->sprite = (sfSprite *){NULL};
    }
    return button;
}
