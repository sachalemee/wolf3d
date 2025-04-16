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

static void dist_ray_travel_sidexy(player_t *player, int x)
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

static void dist_ray_travel(game_t *game, player_t *player)
{
    game->map->map_pos.x = (int)(player->pos.x);
    game->map->map_pos.y = (int)(player->pos.y);
    if (player->rays->raydir.x < 0) {
        player->rays->step.x = -1;
        player->rays->sidedist.x =(player->pos.x
            - game->map->map_pos.x) * player->rays->delta_dist.x;
    } else {
        player->rays->step.x = 1;
        player->rays->sidedist.x = (game->map->map_pos.x + 1.0
            - player->pos.x) * player->rays->delta_dist.x;
    }
    if (player->rays->raydir.y < 0) {
        player->rays->step.y = -1;
        player->rays->sidedist.y = (player->pos.y
            - game->map->map_pos.y) * player->rays->delta_dist.y;
    } else {
        player->rays->step.y = 1;
        player->rays->sidedist.y = (game->map->map_pos.y
            + 1.0 - player->pos.y) * player->rays->delta_dist.y;
    }
}

int raycasting(game_t *game, player_t *player)
{
    for (int x = 0; x < WIN_WIDTH; x++) {
        dist_ray_travel_sidexy(player, x);
        dist_ray_travel(game, player);
    }
    return EXIT_S;
}
