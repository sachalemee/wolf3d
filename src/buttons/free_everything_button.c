/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** free_everything_button.c
*/

#include "buttons.h"
#include "wolfengine.h"
#include <stdlib.h>

void free_button(buttons_t *button)
{
    const sfTexture *button_texture =
        sfRectangleShape_getTexture(button->rect);

    sfTexture_destroy((void *)button_texture);
    sfRectangleShape_destroy(button->rect);
    sfText_destroy(button->title);
    sfFont_destroy(button->font);
    free(button);
}

void free_everything_button(buttons_t **buttons)
{
    if (buttons != NULL) {
        for (size_t i = 0; buttons[i] != NULL; i++)
            free_button(buttons[i]);
    }
    free(buttons);
}
