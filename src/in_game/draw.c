/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw.c
*/

#include "wolfengine.h"

void draw_sprint_overlay(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift)) {
        sfRenderWindow_drawSprite(game->window,
            game->textures.sprint_overlay, NULL);
    }
}

void draw_in_game(game_t *game, player_t *player, map_t map)
{
    draw_background(game->window, game->background);
    raycasting(game, player, map);
    draw_sprint_overlay(game);
}
