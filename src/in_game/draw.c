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

void draw_in_game(sys_data_t *sys, game_t *game, map_t map, settings_t *settings)
{
    draw_background(sys->window, game->background_dsp_rect);
    raycasting(game, map, settings, sys->window);
    draw_sprint_overlay(game, sys->window);
    draw_weapon(game, sys->window, &sys->time);
}
