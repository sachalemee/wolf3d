/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_player.c
*/

#include <stdlib.h>
#include "wolfengine.h"

static void set_states(player_t *player)
{
    player->rays->wall_states = (sfRenderStates){0};
    player->rays->wall_states.texture =
    sfTexture_createFromFile(TEXTURE_WALL, NULL);
    player->rays->wall_states.blendMode = sfBlendAlpha;
    player->rays->wall_states.transform = sfTransform_Identity;
}

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
    set_states(player);
    player->rays->pixel_texture = 900;
    return player->rays;
}

mov_t *init_mov(player_t *player)
{
    player->mov = malloc(sizeof(mov_t));
    if (player->mov == NULL)
        return NULL;
    player->mov->mov_speed = 0;
    player->mov->rotate_speed = 0;
    return player->mov;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return NULL;
    player->pos = (sfVector2f){PLAYER_START_POS_X, PLAYER_START_POS_Y};
    player->dir = (sfVector2f){-1, 0.0};
    player->plane = (sfVector2f){0.0, PLAYER_FOV};
    player->rays = init_rays(player);
    player->map = init_map(player);
    player->mov = init_mov(player);
    return player;
}
