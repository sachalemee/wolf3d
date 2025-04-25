/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** mov_player.c
*/

#include <math.h>
#include <math.h>
#include "wolfengine.h"
#include "hmap.h"

static void is_up(player_t *player, map_t map)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (GET_TIL(map, (int)(player->pos.x + player->dir.x
            * player->mov->mov_speed * PLAYER_BORDER_MAP),
            (int)player->pos.y) == 0)
            player->pos.x += player->dir.x * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->pos.x,
            (int)(player->pos.y + player->dir.y * player->mov->mov_speed
            * PLAYER_BORDER_MAP)) == 0)
            player->pos.y += player->dir.y * player->mov->mov_speed;
    }
}

static void is_down(player_t *player, map_t map)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (GET_TIL(map, (int)(player->pos.x - player->dir.x
            * player->mov->mov_speed * PLAYER_BORDER_MAP),
            (int)player->pos.y) == 0)
            player->pos.x -= player->dir.x * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->pos.x,
            (int)(player->pos.y - player->dir.y * player->mov->mov_speed
            * PLAYER_BORDER_MAP)) == 0)
            player->pos.y -= player->dir.y * player->mov->mov_speed;
    }
}

static void is_left(player_t *player,
    double prev_dir_x, double prev_plane_x)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        prev_dir_x = player->dir.x;
        player->dir.x = player->dir.x * cos(player->mov->rotate_speed)
            - player->dir.y * sin(player->mov->rotate_speed);
        player->dir.y = prev_dir_x * sin(player->mov->rotate_speed)
            + player->dir.y * cos(player->mov->rotate_speed);
        prev_plane_x = player->plane.x;
        player->plane.x = player->plane.x * cos(player->mov->rotate_speed)
            - player->plane.y * sin(player->mov->rotate_speed);
        player->plane.y = prev_plane_x * sin(player->mov->rotate_speed)
            + player->plane.y * cos(player->mov->rotate_speed);
    }
}

static void is_right(player_t *player,
    double prev_dir_x, double prev_plane_x)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        prev_dir_x = player->dir.x;
        player->dir.x = player->dir.x * cos(-player->mov->rotate_speed)
            - player->dir.y * sin(-player->mov->rotate_speed);
        player->dir.y = prev_dir_x * sin(-player->mov->rotate_speed)
            + player->dir.y * cos(-player->mov->rotate_speed);
        prev_plane_x = player->plane.x;
        player->plane.x = player->plane.x * cos(-player->mov->rotate_speed)
            - player->plane.y * sin(-player->mov->rotate_speed);
        player->plane.y = prev_plane_x * sin(-player->mov->rotate_speed)
            + player->plane.y * cos(-player->mov->rotate_speed);
    }
}

static void crab_left(player_t *player, sfVector2f crab_mov, map_t map)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        crab_mov.x = -player->dir.y;
        crab_mov.y = player->dir.x;
        if (GET_TIL(map, (int)(player->pos.x + crab_mov.x
            * player->mov->mov_speed), (int)player->pos.y) == 0)
            player->pos.x += crab_mov.x * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->pos.x, (int)(player->pos.y + crab_mov.y
            * player->mov->mov_speed)) == 0)
            player->pos.y += crab_mov.y * player->mov->mov_speed;
    }
}

static void crab_right(player_t *player, sfVector2f crab_mov, map_t map)
{
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        crab_mov.x = player->dir.y;
        crab_mov.y = -player->dir.x;
        if (GET_TIL(map, (int)(player->pos.x + crab_mov.x
            * player->mov->mov_speed), (int)player->pos.y) == 0)
            player->pos.x += crab_mov.x * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->pos.x, (int)(player->pos.y
            + crab_mov.y * player->mov->mov_speed)) == 0)
            player->pos.y += crab_mov.y * player->mov->mov_speed;
    }
}

static void up_down(player_t *player, map_t map)
{
    is_up(player, map);
    is_down(player, map);
}

static void left_right(player_t *player)
{
    double prev_dir_x = 0;
    double prev_plane_x = 0;

    is_left(player, prev_dir_x, prev_plane_x);
    is_right(player, prev_dir_x, prev_plane_x);
}

static void mov_as_crabs(player_t *player, map_t map)
{
    sfVector2f crab_mov = (sfVector2f){0, 0};

    crab_left(player, crab_mov, map);
    crab_right(player, crab_mov, map);
}

void mov_player(player_t *player, map_t map)
{
    up_down(player, map);
    left_right(player);
    mov_as_crabs(player, map);
}
