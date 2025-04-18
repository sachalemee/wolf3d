/*
** EPITECH PROJECT, 2025
** myworld
** File description:
** buttons_status.c
*/

#include "buttons.h"
#include "wolfengine.h"

static void button_pressed(buttons_t *button,
    sfVector2i mouse_pos, sfFloatRect hitbox, game_t *game)
{
    if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y)) {
        sfRectangleShape_setFillColor(button->rect,
            button->color[B_PRESSED]);
        button->function(game);
        if (button->title)
            sfText_setColor(button->title, button->color[B_BLACK]);
    }
}

static void set_status(buttons_t *button,
    sfVector2i mouse_pos, sfFloatRect hitbox)
{
    if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y)) {
        sfRectangleShape_setFillColor(button->rect, button->color[B_HOVER]);
        if (button->title != NULL)
            sfText_setColor(button->title, button->color[B_DEFAULT]);
    } else {
        sfRectangleShape_setFillColor(button->rect, button->color[B_DEFAULT]);
        if (button->title != NULL)
            sfText_setColor(button->title, sfColor_fromRGBA(248, 226, 126, 175));
    }
}

int buttons_status(sfRenderWindow *window,
    buttons_t *button, sfEvent event, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(button->rect);

    set_status(button, mouse_pos, hitbox);
    if (event.type == sfEvtMouseButtonPressed) {
        button_pressed(button, mouse_pos, hitbox, game);
    }
    return SUCCESS;
}
