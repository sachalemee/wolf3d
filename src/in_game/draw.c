/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw.c
*/

#include "wolfengine.h"

void draw_sprint_overlay(game_t *game)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift)) {
        texture = sfTexture_createFromFile(TEXTURE_OVERLAY_SPRINT, NULL);
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setColor(sprite, sfColor_fromRGBA(100, 240, 220, 75));
        sfSprite_setScale(sprite, (sfVector2f){3, 3});
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
    }
}

void draw_in_game(game_t *game, player_t *player)
{
    draw_background(game);
    raycasting(game, player);
    draw_sprint_overlay(game);
}
