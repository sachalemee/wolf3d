/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_player.c
*/

#include "wolfengine.h"
#include <stdlib.h>

static void init_rays(player_t *player)
{
    player->rays = malloc(sizeof(rays_t) * PLAYER_NUMRAYS);
    if (player->rays == NULL)
        return;
    player->rays->ra = 0;
    player->rays->hitpos = (sfVector2f){0, 0};
    player->rays->dist = 0;
    player->rays->verticalhit = 0;
    player->rays->dof = 0;
    player->rays->i_map = 0;
    player->rays->offset = (sfVector2f){0, 0};
}

static void init_mov(player_t *player)
{
    player->mov = malloc(sizeof(mov_t));
    if (player->mov == NULL)
        return;
    player->mov->delta.x = 0;
    player->mov->delta.y = 0;
    player->mov->angle = 0;
}

static void init_view(player_t *player)
{
    player->view = malloc(sizeof(view_t));
    if (player->view == NULL)
        return;
    player->view->numrays = PLAYER_NUMRAYS;
    player->view->fov = degree_to_radian(PLAYER_FOV);
}

player_t *init_player(player_t *player)
{
    player->speed = PLAYER_SPEED;
    player->radius = PLAYER_RADIUS;
    player->color = PLAYER_COLOR;
    player->pos = (sfVector2f){PLAYER_POSX, PLAYER_POSY};
    init_mov(player);
    init_rays(player);
    init_view(player);
    return player;
}
