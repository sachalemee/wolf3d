/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** background.c
*/


#include "wolfengine.h"

void draw_background(sfRenderWindow *win,
    sfRectangleShape *background_dsp_rect, sfVector2u win_dimension)
{
    sfColor color = sfColor_fromRGB(FLOOR_RGB);

    sfRectangleShape_setPosition(background_dsp_rect,
        (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(background_dsp_rect,
        sfColor_fromRGB(ROOF_RGB));
    sfRenderWindow_drawRectangleShape(win,
        background_dsp_rect, sfFalse);
    sfRectangleShape_setPosition(background_dsp_rect,
        (sfVector2f){0, win_dimension.y / 2});
    sfRectangleShape_setFillColor(background_dsp_rect, color);
    sfRenderWindow_drawRectangleShape(win,
        background_dsp_rect, sfFalse);
}
