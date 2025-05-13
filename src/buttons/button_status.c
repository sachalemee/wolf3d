/*
** EPITECH PROJECT, 2025
** myworld
** File description:
** buttons_status.c
*/

#include "wolfengine.h"

static void button_pressed(buttons_t *button,
    sfVector2i mouse_pos, sfFloatRect hitbox, sys_data_t *sys)
{
    if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y)) {
        sfRectangleShape_setFillColor(button->rect,
            sfTransparent);
        button->function(sys);
        if (button->title)
            sfText_setColor(button->title, sfColor_fromRGB(218, 165, 32));
    }
}

static void set_status(buttons_t *button,
    sfVector2i mouse_pos, sfFloatRect hitbox)
{
    if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y)) {
        sfRectangleShape_setFillColor(button->rect, sfTransparent);
        if (button->title != NULL)
            sfText_setColor(button->title, sfColor_fromRGB(205, 133, 63));
    } else {
        sfRectangleShape_setFillColor(button->rect, sfTransparent);
        if (button->title != NULL)
            sfText_setColor(button->title, sfColor_fromRGB(139, 69, 19));
    }
}

int buttons_status(sfRenderWindow *window,
    buttons_t *button, sfEvent event, sys_data_t *sys)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(button->rect);

    set_status(button, mouse_pos, hitbox);
    if (event.type == sfEvtMouseButtonPressed)
        button_pressed(button, mouse_pos, hitbox, sys);
    return SUCCESS;
}
