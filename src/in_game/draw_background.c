/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** background.c
*/


#include "wolfengine.h"

/*
    sfRectangleShape *background = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile("ressources/sky.jpeg", NULL);

    sfRectangleShape_setTexture(background, texture, sfTrue);
    sfRectangleShape_setSize(background, (sfVector2f){WIN_WIDTH, WIN_HEIGHT / 2});
    sfRenderWindow_drawRectangleShape(game->window, background, sfFalse);
    texture = sfTexture_createFromFile("ressources/wood-floor.png", NULL);
    sfRectangleShape_setTexture(background, texture, sfTrue);
    sfRectangleShape_setPosition(background, (sfVector2f){0, WIN_HEIGHT / 2});
    sfRenderWindow_drawRectangleShape(game->window, background, sfFalse);
*/

void draw_background(game_t *game)
{
    sfRectangleShape *background = sfRectangleShape_create();
    // sfTexture *r_texture = sfTexture_createFromFile("ressources/sky.jpeg", NULL);
    // sfTexture *f_texture = sfTexture_createFromFile("ressources/wood-floor.png", NULL);
    sfColor color = sfColor_fromRGB(90, 231, 223);

    // sfRectangleShape_setTexture(background, r_texture, sfFalse);
    // sfRectangleShape_setTexture(background, f_texture, sfFalse);
    sfRectangleShape_setFillColor(background, color);
    sfRectangleShape_setSize(background, (sfVector2f){WIN_WIDTH, WIN_HEIGHT / 2});
    sfRenderWindow_drawRectangleShape(game->window, background, sfFalse);
    color = sfColor_fromRGB(223, 231, 90); 
    sfRectangleShape_setFillColor(background, color);
    sfRectangleShape_setPosition(background, (sfVector2f){0, WIN_HEIGHT / 2});
    sfRenderWindow_drawRectangleShape(game->window, background, sfFalse);
    return;
}
