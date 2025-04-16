/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** draw_button.c
*/

#include "buttons.h"
#include "wolfengine.h"

int draw_button(sfRenderWindow *window, buttons_t *button)
{
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    if (button->texture != NULL)
        sfRenderWindow_drawSprite(window, button->sprite, NULL);
    if (button->title != NULL)
        sfRenderWindow_drawText(window, button->title, NULL);
    return SUCCESS;
}
