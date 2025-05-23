/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw.c
*/

#include "wolfengine.h"

static void draw_sprint_overlay(game_t *game, sfRenderWindow *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift)) {
        sfRenderWindow_drawSprite(win, game->sprites.sprint_overlay, NULL);
    }
}

int draw_in_game(game_t *game, map_t *map, sfRenderWindow *win)
{
    draw_background(win, game->background_dsp_rect);
    raycasting(&(game->player.camera), map, game->wall_sprites, win);
    draw_sprint_overlay(game, win);
    return SUCCESS;
}
