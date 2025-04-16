/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** background.c
*/


#include "wolfengine.h"

void draw_background(game_t *game)
{
    sfRectangleShape *background = sfRectangleShape_create();
    sfColor color = sfColor_fromRGB(90, 231, 223);

    sfRectangleShape_setFillColor(background, color);
    sfRectangleShape_setSize(
        background, (sfVector2f){WIN_WIDTH, WIN_HEIGHT / 2});
    sfRenderWindow_drawRectangleShape(game->window,
        background, sfFalse);
    color = sfColor_fromRGB(223, 231, 90);
    sfRectangleShape_setFillColor(background, color);
    sfRectangleShape_setPosition(
        background, (sfVector2f){0, WIN_HEIGHT / 2});
    sfRenderWindow_drawRectangleShape(game->window,
        background, sfFalse);
    return;
}
