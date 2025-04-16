/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_player.c
*/

#include <stdlib.h>
#include "wolfengine.h"

rays_t *init_rays(player_t *player)
{
    player->rays = malloc(sizeof(rays_t));
    if (player->rays == NULL)
        return NULL;
    player->rays->vertex = NULL;
    player->rays->raydir = (sfVector2f){0, 0};
    player->rays->camera_x = 0;
    player->rays->delta_dist = (sfVector2f){0, 0};
    player->rays->sidedist = (sfVector2f){0, 0};
    player->rays->step = (sfVector2i){0, 0};
    player->rays->perpwalldist = 0;
    player->rays->side = 0;
    return player->rays;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return NULL;
    player->pos = (sfVector2f){PLAYER_START_POS_X, PLAYER_START_POS_Y};
    player->dir = (sfVector2f){-1, 0.0};
    player->plane = (sfVector2f){0.0, 0.66};
    player->mov_speed = 0;
    player->rotate_speed = 0;
    player->rays = init_rays(player);
    player->map = init_map(player);
    return player;
}
