/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** raycasting.c
*/

#include <math.h>
#include <stdlib.h>
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

static void dist_ray_travel(player_t *player)
{
    player->map->map_pos.x = (int)(player->pos.x);
    player->map->map_pos.y = (int)(player->pos.y);
    if (player->rays->raydir.x < 0) {
        player->rays->step.x = -1;
        player->rays->sidedist.x = (player->pos.x
            - player->map->map_pos.x) * player->rays->delta_dist.x;
    } else {
        player->rays->step.x = 1;
        player->rays->sidedist.x = (player->map->map_pos.x + 1.0
            - player->pos.x) * player->rays->delta_dist.x;
    }
    if (player->rays->raydir.y < 0) {
        player->rays->step.y = -1;
        player->rays->sidedist.y = (player->pos.y
            - player->map->map_pos.y) * player->rays->delta_dist.y;
    } else {
        player->rays->step.y = 1;
        player->rays->sidedist.y = (player->map->map_pos.y
            + 1.0 - player->pos.y) * player->rays->delta_dist.y;
    }
}

static void dda_algo(player_t *player)
{
    int hit_wall = 0;

    while (hit_wall == 0) {
        if (player->rays->sidedist.x < player->rays->sidedist.y) {
            player->rays->sidedist.x += player->rays->delta_dist.x;
            player->map->map_pos.x += player->rays->step.x;
            player->rays->side = 0;
        } else {
            player->rays->sidedist.y += player->rays->delta_dist.y;
            player->map->map_pos.y += player->rays->step.y;
            player->rays->side = 1;
        }
        if (map[player->map->map_pos.x][player->map->map_pos.y] > 0)
            hit_wall = 1;
    }
}

static void len_ray(player_t *player)
{
    if (player->rays->side == 0)
        player->rays->perpwalldist =
        player->rays->sidedist.x - player->rays->delta_dist.x;
    else
        player->rays->perpwalldist =
        player->rays->sidedist.y - player->rays->delta_dist.y;
}

static void set_vertex(player_t *player,
    int beg_draw, int end_draw, int x)
{
    sfColor color_vertex = sfColor_fromRGB(100, 240, 232);
    sfVertex vertex = {0};

    player->rays->vertex = sfVertexArray_create();
    vertex = (sfVertex){{(float)x, (float)beg_draw}, color_vertex, {0, 0}};
    sfVertexArray_append(player->rays->vertex, vertex);
    color_vertex = sfColor_fromRGB(232, 240, 100);
    vertex = (sfVertex){{(float)x, (float)end_draw}, color_vertex, {0, 0}};
    sfVertexArray_append(player->rays->vertex, vertex);
    sfVertexArray_setPrimitiveType(player->rays->vertex, sfLines);
}

static void draw_vertex_lines(player_t *player, int x, sfRenderWindow* window)
{
    int beg_draw = 0;
    int end_draw = 0;
    int wall_size = 0;

    wall_size = (int)(WIN_HEIGHT / player->rays->perpwalldist) + WALL_HEIGHT_MULTI;
    beg_draw = (-wall_size / 2) + (WIN_HEIGHT / 2);
    end_draw = (wall_size / 2) + (WIN_HEIGHT / 2);
    if (beg_draw < 0)
        beg_draw = 0;
    if (end_draw >= WIN_HEIGHT)
        end_draw = WIN_HEIGHT;
    set_vertex(player, beg_draw, end_draw, x);
    sfRenderWindow_drawVertexArray(window, player->rays->vertex, NULL);
}

void raycasting(game_t *game, player_t *player)
{
    int x = 0;

    for (int i = 0; i < WIN_WIDTH; i++) {
        x = i * (WIN_WIDTH / NUM_RAYS);
        dist_ray_travel_sidexy(player, x);
        dist_ray_travel(player);
        dda_algo(player);
        len_ray(player);
        draw_vertex_lines(player, x, game->window);
        sfVertexArray_clear(player->rays->vertex);
        sfVertexArray_destroy(player->rays->vertex);
    }
}
