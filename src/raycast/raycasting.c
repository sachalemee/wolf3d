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

static void ray_posdir(player_t *player, int x, sfRenderWindow *win)
{
    sfVector2u win_size = sfRenderWindow_getSize(win);

    player->rays.camera_x = 2 * x / (double)win_size.x - 1;
    player->rays.raydir.x =
        player->dir.x + player->plane.x * player->rays.camera_x;
    player->rays.raydir.y =
        player->dir.y + player->plane.y * player->rays.camera_x;
}

static void dist_ray_travel_sidexy(player_t *player, int x,
    sfRenderWindow *win)
{
    ray_posdir(player, x, win);
    if (player->rays.raydir.x == 0) {
        player->rays.delta_dist.x = INFINITY;
    } else {
        if (player->rays.raydir.x < 0)
            player->rays.delta_dist.x = -1 / player->rays.raydir.x;
        else
            player->rays.delta_dist.x = 1 / player->rays.raydir.x;
    }
    if (player->rays.raydir.y == 0) {
        player->rays.delta_dist.y = INFINITY;
    } else {
        if (player->rays.raydir.y < 0)
            player->rays.delta_dist.y = -1 / player->rays.raydir.y;
        else
            player->rays.delta_dist.y = 1 / player->rays.raydir.y;
    }
}

static void dist_ray_travel(player_t *player)
{
    player->map.x = (int)(player->pos.x);
    player->map.y = (int)(player->pos.y);
    if (player->rays.raydir.x < 0) {
        player->rays.step.x = -1;
        player->rays.sidedist.x = (player->pos.x
            - player->map.x) * player->rays.delta_dist.x;
    } else {
        player->rays.step.x = 1;
        player->rays.sidedist.x = (player->map.x + 1.0
            - player->pos.x) * player->rays.delta_dist.x;
    }
    if (player->rays.raydir.y < 0) {
        player->rays.step.y = -1;
        player->rays.sidedist.y = (player->pos.y
            - player->map.y) * player->rays.delta_dist.y;
    } else {
        player->rays.step.y = 1;
        player->rays.sidedist.y = (player->map.y
            + 1.0 - player->pos.y) * player->rays.delta_dist.y;
    }
}

static void dda_algo(player_t *player, map_t map, settings_t *settings)
{
    int hit_wall = 0;

    for (size_t i = 0; hit_wall == 0 && i < settings->render_dist; i++) {
        if (player->rays.sidedist.x < player->rays.sidedist.y) {
            player->rays.sidedist.x += player->rays.delta_dist.x;
            player->map.x += player->rays.step.x;
            player->rays.side = 0;
        } else {
            player->rays.sidedist.y += player->rays.delta_dist.y;
            player->map.y += player->rays.step.y;
            player->rays.side = 1;
        }
        if (GET_TIL(map, player->map.x, player->map.y) > 0)
            hit_wall = 1;
    }
}

static void len_ray(player_t *player)
{
    if (player->rays.side == 0)
        player->rays.perpwalldist =
        player->rays.sidedist.x - player->rays.delta_dist.x;
    else
        player->rays.perpwalldist =
        player->rays.sidedist.y - player->rays.delta_dist.y;
}

static void set_vertex(player_t *player,
    int beg_draw, int end_draw, int x)
{
    sfColor color_vertex = sfColor_fromRGB(100, 240, 220);
    sfVertex vertex = {0};

    vertex = (sfVertex){{(float)x, (float)beg_draw}, sfWhite, {491, 0}};
    sfVertexArray_append(player->rays.vertex, vertex);
    color_vertex = sfColor_fromRGB(232, 240, 100);
    vertex = (sfVertex){{(float)x, (float)end_draw}, color_vertex,
        {491, player->rays.pixel_texture}};
    sfVertexArray_append(player->rays.vertex, vertex);
}

static void draw_vertex_lines(player_t *player, int x, sfRenderWindow* window)
{
    int beg_draw = 0;
    int end_draw = 0;
    int wall_size = 0;
    sfVector2u win_size = sfRenderWindow_getSize(window);

    wall_size = (int)(win_size.y / player->rays.perpwalldist)
        + WALL_HEIGHT_MULTI;
    beg_draw = (-wall_size / 2) + (win_size.y / 2);
    end_draw = (wall_size / 2) + (win_size.y / 2);
    set_vertex(player, beg_draw, end_draw, x);
    sfRenderWindow_drawVertexArray(window,
        player->rays.vertex, &player->rays.wall_states);
}

void raycasting(game_t *game, settings_t *settings,
    sfRenderWindow *win, float *raycast_data)
{
    sfVector2u win_size = sfRenderWindow_getSize(win);

    for (int i = 0; i < win_size.x; i++) {
        dist_ray_travel_sidexy(&(game->player), i, win);
        dist_ray_travel(&(game->player));
        dda_algo(&(game->player), *(game->current_map), settings);
        len_ray(&(game->player));
        draw_vertex_lines(&(game->player), i, win);
        raycast_data[i] = game->player.rays.perpwalldist;
        sfVertexArray_clear(game->player.rays.vertex);
    }
}
