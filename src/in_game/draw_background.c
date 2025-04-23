/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** background.c
*/


#include "wolfengine.h"

void draw_background(sfRenderWindow *win, horiz_surfaces_t background)
{
    sfRenderWindow_drawRectangleShape(win, background.floor, sfFalse);
    sfRenderWindow_drawRectangleShape(win, background.roof, sfFalse);
}
