/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw.c
*/

#include "wolfengine.h"

void draw_in_game(sys_data_t *sys, game_t *game, map_t map)
{
    draw_background(sys->window, game->ground_sky->background_dsp_rect);
    raycasting(game->player.camera, map, game->wall_sprites, sys->window);
    draw_sprint_overlay(game, sys->window, &sys->time);
    draw_weapon(&(game->weapon), sys->window, &sys->time);
}
