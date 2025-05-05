/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** set_button_text.c
*/

#include "buttons.h"
#include "wolfengine.h"

void set_button_text(buttons_t *button, char *title,
    sfFloatRect bounds, sfVector2f origin)
{
    sfText_setString(button->title, title);
    sfText_setScale(button->title, (sfVector2f){1.0, 1.0});
    sfText_setColor(button->title, sfBlack);
    sfText_setFont(button->title, button->font);
    bounds = sfText_getGlobalBounds(button->title);
    origin = (sfVector2f){button->pos.x + ((button->size.x / 2.0f) -
        (bounds.width / 2.0f)), button->pos.y
        + ((button->size.y / 2.0f) - bounds.height)};
    sfText_setPosition(button->title, origin);
}
