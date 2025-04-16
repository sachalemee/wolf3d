/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** draw_all_buttons.c
*/

#include "buttons.h"
#include "wolfengine.h"

void draw_all_buttons(sfRenderWindow *window,
    game_t *game)
{
    draw_button(window, game->buttons[0]);
    return;
}
