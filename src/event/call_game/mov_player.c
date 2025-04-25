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

static void is_left(player_t *player)
{
    sfVector2f dir_cpy = player->dir;
    sfVector2f plane_cpy = player->plane;

    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        player->dir.x = dir_cpy.x * cos(player->mov->rotate_speed)
            - dir_cpy.y * sin(player->mov->rotate_speed);
        player->dir.y = dir_cpy.x * sin(player->mov->rotate_speed)
            + dir_cpy.y * cos(player->mov->rotate_speed);
        
        player->plane.x = plane_cpy.x * cos(player->mov->rotate_speed)
            - plane_cpy.y * sin(player->mov->rotate_speed);
        player->plane.y = plane_cpy.x * sin(player->mov->rotate_speed)
            + plane_cpy.y * cos(player->mov->rotate_speed);
    }
}

static void is_right(player_t *player)
{
    sfVector2f dir_cpy = player->dir;
    sfVector2f plane_cpy = player->plane;

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        player->dir.x = dir_cpy.x * cos(-player->mov->rotate_speed)
            - dir_cpy.y * sin(-player->mov->rotate_speed);
        player->dir.y = dir_cpy.x * sin(-player->mov->rotate_speed)
            + dir_cpy.y * cos(-player->mov->rotate_speed);
        player->plane.x = plane_cpy.x * cos(-player->mov->rotate_speed)
            - plane_cpy.y * sin(-player->mov->rotate_speed);
        player->plane.y = plane_cpy.x * sin(-player->mov->rotate_speed)
            + plane_cpy.y * cos(-player->mov->rotate_speed);
    }
}

static void crab_left(player_t *player, map_t map)
{
    sfVector2f crab_mov = (sfVector2f){-player->dir.y, player->dir.x};

    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (GET_TIL(map, (int)(player->pos.x + crab_mov.x
            * player->mov->mov_speed), (int)player->pos.y) == 0)
            player->pos.x += crab_mov.x * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->pos.x, (int)(player->pos.y + crab_mov.y
            * player->mov->mov_speed)) == 0)
            player->pos.y += crab_mov.y * player->mov->mov_speed;
    }
}

static void crab_right(player_t *player, map_t map)
{
    sfVector2f crab_mov = (sfVector2f){player->dir.y, -player->dir.x};

    if (sfKeyboard_isKeyPressed(sfKeyD)) {
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
    double prev_plane_x = 0;

    is_left(player);
    is_right(player);
}

static void mov_as_crabs(player_t *player, map_t map)
{
    crab_left(player, map);
    crab_right(player, map);
}

void mov_player(player_t *player, map_t map)
{
    up_down(player, map);
    left_right(player);
    mov_as_crabs(player, map);
}
