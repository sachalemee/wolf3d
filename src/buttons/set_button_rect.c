/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** set_button_rect.c
*/

#include "buttons.h"
#include "wolfengine.h"

void set_button_rect(buttons_t *button,
    sfVector2f size, sfVector2f pos)
{
    button->rect = sfRectangleShape_create();
    button->size = size;
    sfRectangleShape_setSize(button->rect, button->size);
    button->pos = pos;
    sfRectangleShape_setPosition(button->rect, button->pos);
    set_button_color(button);
    sfRectangleShape_setFillColor(button->rect, sfTransparent);
}
