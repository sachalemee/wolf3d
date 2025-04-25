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
