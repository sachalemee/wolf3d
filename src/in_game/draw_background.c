/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** background.c
*/


#include "wolfengine.h"

void draw_background(sfRenderWindow *win,
    sfRectangleShape *background_dsp_rect)
{
    sfColor color = sfColor_fromRGB(FLOOR_RGB);

    sfRenderWindow_drawRectangleShape(win, background_dsp_rect, sfFalse);
    sfRectangleShape_setFillColor(background_dsp_rect, color);
    sfRectangleShape_setPosition(
        background_dsp_rect, (sfVector2f){0, WIN_HEIGHT / 2});
    sfRectangleShape_setPosition(
        background_dsp_rect, (sfVector2f){0, WIN_HEIGHT / 2});
    sfRenderWindow_drawRectangleShape(win, background_dsp_rect, sfFalse);
}
