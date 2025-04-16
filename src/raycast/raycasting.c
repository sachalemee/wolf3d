/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** raycasting.c
*/

#include <math.h>
#include "wolfengine.h"
#include "hmap.h"

static void ray_posdir(player_t *player, int x)
{
    player->rays->camera_x = 2 * x / (double)WIN_WIDTH - 1;
    player->rays->raydir.x =
        player->dir.x + player->plane.x * player->rays->camera_x;
    player->rays->raydir.y =
        player->dir.y + player->plane.y * player->rays->camera_x;
}

void dist_ray_travel_sidexy(player_t *player, int x)
{
    ray_posdir(player, x);
    if (player->rays->raydir.x == 0) {
        player->rays->delta_dist.x = INFINITY;
    } else {
        if (1 / player->rays->raydir.x < 0)
            player->rays->delta_dist.x = -(1 / player->rays->raydir.x);
        else
            player->rays->delta_dist.x = 1 / player->rays->raydir.x;
    }
    if (player->rays->raydir.y == 0) {
        player->rays->delta_dist.y = INFINITY;
    } else {
        if (1 / player->rays->raydir.y < 0)
            player->rays->delta_dist.y = -(1 / player->rays->raydir.y);
        else
            player->rays->delta_dist.y = 1 / player->rays->raydir.y;
    }
}

int raycasting(game_t *game, player_t *player)
{
    for (int x = 0; x < WIN_WIDTH; x++) {
        dist_ray_side_by_side(player, x);
    }
    return EXIT_S;
}
