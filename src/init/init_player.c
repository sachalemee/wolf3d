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
    player->rays = calloc(1, sizeof(rays_t));
    if (player->rays == NULL)
        return NULL;
    player->rays->wall_states.texture =
        sfTexture_createFromFile(TEXTURE_WALL, NULL);
    if (player->rays->wall_states.texture == NULL) {
        // sfTexture_destroy(player->rays->wall_states.texture);
        return NULL;
    }
    player->rays->wall_states.blendMode = sfBlendAlpha;
    player->rays->wall_states.transform = sfTransform_Identity;
    player->rays->pixel_texture = 900;
    return player->rays;
}

void destroy_player(player_t *player)
{
    if (player == NULL)
        return;
    if (player->rays)
        sfTexture_destroy((void *)player->rays->wall_states.texture);
    free(player->rays);
    free(player->mov);
    free(player);
}

player_t *init_player(sfVector2f coords)
{
    player_t *player = calloc(1, sizeof(player_t));

    if (player == NULL)
        return NULL;
    player->dir = (sfVector2f){-1, 0.0};
    player->plane = (sfVector2f){0.0, PLAYER_FOV};
    player->rays = init_rays(player);
    player->mov = calloc(1, sizeof(mov_t));
    player->map = (sfVector2i){(int)coords.x + 0.5, (int)coords.y + 0.5};
    player->pos = (sfVector2f){(float)coords.x + 0.5, (float)coords.y + 0.5};
    if (player->rays == NULL || player->mov == NULL) {
        destroy_player(player);
        return NULL;
    }
    return player;
}
