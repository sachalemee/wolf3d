/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_player.c
*/

#include <stdlib.h>
#include "wolfengine.h"

int init_rays(rays_t *rays)
{
    rays->wall_states.texture = sfTexture_createFromFile(TEXTURE_WALL, NULL);
    rays->vertex = sfVertexArray_create();
    if (rays->vertex == NULL || rays->wall_states.texture == NULL) {
        destroy_rays(*rays);
        return FAILURE;
    }
    sfVertexArray_setPrimitiveType(rays->vertex, sfLines);
    rays->wall_states.blendMode = sfBlendAlpha;
    rays->wall_states.transform = sfTransform_Identity;
    rays->pixel_texture = 900;
    return SUCCESS;
}

void destroy_rays(rays_t rays)
{
    sfVertexArray_destroy(rays.vertex);
    sfTexture_destroy((void *)rays.wall_states.texture);
}

void destroy_player(player_t player)
{
    free(player.mov);
    destroy_rays(player.rays);
}

int init_player(sfVector2f coords, player_t *dest)
{
    dest->mov = calloc(1, sizeof(player_settings_t));
    if (dest->mov == NULL || init_rays(&(dest->rays)) == FAILURE) {
        destroy_player(*dest);
        return FAILURE;
    }
    dest->dir = (sfVector2f){-1, 0.0};
    dest->plane = (sfVector2f){0.0, PLAYER_FOV};
    dest->map = (sfVector2i){(int)coords.x, (int)coords.y};
    dest->pos = (sfVector2f){coords.x + 0.5, (int)coords.y + 0.5};
    return SUCCESS;
}
