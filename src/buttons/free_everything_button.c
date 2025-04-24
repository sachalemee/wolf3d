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
    if (button != NULL) {
        if (button->rect != NULL)
            sfRectangleShape_destroy(button->rect);
        if (button->sprite != NULL)
            sfSprite_destroy(button->sprite);
        if (button->texture != NULL)
            sfTexture_destroy(button->texture);
        if (button->title != NULL)
            sfText_destroy(button->title);
    }
    free(button);
}
