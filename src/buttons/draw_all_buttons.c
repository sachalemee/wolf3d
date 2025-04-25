/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** draw_all_buttons.c
*/

#include "buttons.h"
#include "wolfengine.h"

void draw_all_buttons(menu_t *menu, sfRenderWindow *window)
{
    draw_button(window, menu->buttons[0]);
    draw_button(window, menu->buttons[1]);
    draw_button(window, menu->buttons[2]);
    return;
}
