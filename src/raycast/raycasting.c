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

static sfVector2f get_ray_orientation(camera_t camera, int x)
{
    double camera_x = 2 * x / (double)WIN_WIDTH - 1;
    sfVector2f ray_direction = {
        camera.dir.x + camera.plane.x * camera_x,
        camera.dir.y + camera.plane.y * camera_x
    };

    return ray_direction;
}

static void get_sidedist(sfVector2f camera_pos, ray_t *ray)
{
    int nearest_left_wall = (int)(camera_pos.x);
    int nearest_right_wall = (int)(camera_pos.x) + 1;
    int nearest_top_wall = (int)(camera_pos.y);
    int nearest_bottom_wall = (int)(camera_pos.y) + 1;

    if (ray->step.x == NEGATIVE_STEP) {
        ray->sidedist.x = (camera_pos.x - nearest_left_wall);
    } else
        ray->sidedist.x = (nearest_right_wall - camera_pos.x);
    if (ray->step.y == NEGATIVE_STEP) {
        ray->sidedist.y = (camera_pos.y - nearest_top_wall);
    } else
        ray->sidedist.y = (nearest_bottom_wall - camera_pos.y);
    ray->sidedist = (sfVector2f){
        ray->sidedist.x * ray->delta_dist.x,
        ray->sidedist.y * ray->delta_dist.y
    };
}

static void get_dda_values(sfVector2f camera_pos, ray_t *ray)
{
    ray->step = (sfVector2i){
        (ray->dir.x < 0) ?
            NEGATIVE_STEP :
            POSITIVE_STEP,
        (ray->dir.y < 0) ?
            NEGATIVE_STEP :
            POSITIVE_STEP
    };
    ray->delta_dist = (sfVector2f){
        fabs(1 / ray->dir.x),
        fabs(1 / ray->dir.y)
    };
    get_sidedist(camera_pos, ray);
}

// returns the type of wall that was hit
static int get_first_intersecting_wall(ray_t *ray, map_t map,
    size_t max_ray_len, int *wall_side)
{
    int hit_wall = 0;
    sfVector2i wall_coords = {ray->origin.x, ray->origin.y};
    int current_tile = 0;

    for (size_t i = 0; hit_wall == 0 && i < max_ray_len; i++) {
        if (ray->sidedist.x < ray->sidedist.y) {
            ray->sidedist.x += ray->delta_dist.x;
            wall_coords.x += ray->step.x;
            *wall_side = VERTICAL_WALL;
        } else {
            ray->sidedist.y += ray->delta_dist.y;
            wall_coords.y += ray->step.y;
            *wall_side = HORIZONTAL_WALL;
        }
        current_tile = GET_TIL(map, wall_coords.x, wall_coords.y);
        if (current_tile > 0)
            return current_tile;
    }
    return current_tile;
}

static double len_ray(ray_t ray, int side)
{
    if (side == VERTICAL_WALL)
        return ray.sidedist.x - ray.delta_dist.x;
    else
        return ray.sidedist.y - ray.delta_dist.y;
}

static void draw_raycast_band(ray_hit_data_t ray_data,
    sfSprite *wall_sprite, size_t band_x, sfRenderWindow *win)
{
    sfVector2u win_size = sfRenderWindow_getSize(win);
    double wall_height = (double)win_size.y / ray_data.walldist;
    int top_band = (double)((-1 * wall_height + (double)win_size.y) / 2);
    sfIntRect wall_texture_rect = sfSprite_getTextureRect(wall_sprite);
    double band_width = (double)wall_texture_rect.width /
        ((double)win_size.x / ray_data.walldist);
    sfIntRect band_texture_rect = {
        round(ray_data.wall_tex_abscissa * (double)wall_texture_rect.width),
        0, ceil(band_width), wall_texture_rect.height};
    sfVector2f sprite_scale = {(double)1.0 / (double)band_texture_rect.width,
        (double)wall_height / (double)wall_texture_rect.height};

    sfSprite_setTextureRect(wall_sprite, band_texture_rect);
    sfSprite_setScale(wall_sprite, sprite_scale);
    sfSprite_setPosition(wall_sprite, (sfVector2f){band_x, top_band});
    sfRenderWindow_drawSprite(win, wall_sprite, NULL);
    sfSprite_setTextureRect(wall_sprite, wall_texture_rect);
    sfSprite_setScale(wall_sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(wall_sprite, (sfVector2f){0, 0});
}

// wall_type gets +1 because texture 0 doesnt exis (0 is air)
static void dsp_raycast_band(ray_hit_data_t ray_data,
    sfSprite **wall_sprites, size_t band_x, sfRenderWindow *win)
{
    if (ray_data.wall_type != AIR)
        draw_raycast_band(ray_data, wall_sprites[ray_data.wall_type - 1],
            band_x, win);
}

double get_wall_tex_abscissa(sfVector2f dir, int side,
    sfVector2f camera_pos, double wall_dist)
{
    double wall_tex_abscissa = 0;

    if (side == 0)
        wall_tex_abscissa = camera_pos.y + wall_dist * dir.y;
    else
        wall_tex_abscissa = camera_pos.x + wall_dist * dir.x;
    wall_tex_abscissa = wall_tex_abscissa - floor(wall_tex_abscissa);
    return wall_tex_abscissa;
}

ray_hit_data_t cast_ray(map_t map, sfVector2f origin,
    sfVector2f direction, size_t maxlen)
{
    ray_hit_data_t hit_data = {0};
    ray_t ray = {0};

    ray.dir = direction;
    ray.origin = origin;
    get_dda_values(origin, &ray);
    hit_data.wall_type = get_first_intersecting_wall(&ray, map,
        maxlen, &(hit_data.side));
    hit_data.walldist = len_ray(ray, hit_data.side);
    hit_data.wall_tex_abscissa = get_wall_tex_abscissa(ray.dir, hit_data.side,
        ray.origin, hit_data.walldist);
    return hit_data;
}

void raycasting(camera_t camera, map_t map,
    sfSprite **wall_sprites, sfRenderWindow *win)
{
    sfVector2f ray_direction = {0};
    ray_hit_data_t ray_data = {0};

    for (size_t x = 0; x < WIN_WIDTH; x++) {
        ray_direction = get_ray_orientation(camera, x);
        ray_data = cast_ray(map, camera.pos,
            ray_direction, *(camera.render_dist));
        dsp_raycast_band(ray_data, wall_sprites, x, win);
    }
}
