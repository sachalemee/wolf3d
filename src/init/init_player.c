/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_player.c
*/

#include <stdlib.h>
#include "wolfengine.h"

void destroy_player(player_t player)
{
    free(player.mov);
}

int init_player(sfVector2f coords, player_t *dest)
{
    dest->mov = calloc(1, sizeof(player_settings_t));
    dest->camera.render_dist = calloc(1, sizeof(size_t));
    if (check_mallocs(2, "", dest->camera.render_dist, dest->mov) == false)
        return FAILURE;
    dest->camera.dir = (sfVector2f){-1, 0.0};
    dest->camera.plane = (sfVector2f){0.0, PLAYER_FOV};
    dest->camera.pos = (sfVector2f){coords.x + 0.5, (int)coords.y + 0.5};
    *(dest->camera.render_dist) = DEFAULT_RENDER_DIST;
    dest->map = (sfVector2i){(int)coords.x, (int)coords.y};
    dest->mov->render_dist = dest->camera.render_dist;
    return SUCCESS;
}
