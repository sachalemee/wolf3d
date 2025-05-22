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
    if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y))
        button->function(sys);
}

static void set_status(buttons_t *button,
    sfVector2i mouse_pos, sfFloatRect hitbox)
{
    if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y)) {
        sfSprite_setScale(button->sprite, (sfVector2f){button->scale.x + 0.025,
            button->scale.y + 0.025});
    } else {
        sfSprite_setScale(button->sprite, button->scale);
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
