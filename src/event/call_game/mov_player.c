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

static void is_left(player_t *player)
{
    sfVector2f dir_cpy = player->camera.dir;
    sfVector2f plane_cpy = player->camera.plane;

    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        player->camera.dir = (sfVector2f){
            player->camera.dir.x * cos(player->mov->rotate_speed)
            - player->camera.dir.y * sin(player->mov->rotate_speed),
            player->camera.dir.y = dir_cpy.x * sin(player->mov->rotate_speed)
            + player->camera.dir.y * cos(player->mov->rotate_speed)
        };
        player->camera.plane = (sfVector2f){
            player->camera.plane.x * cos(player->mov->rotate_speed)
            - player->camera.plane.y * sin(player->mov->rotate_speed),
            plane_cpy.x * sin(player->mov->rotate_speed)
            + player->camera.plane.y * cos(player->mov->rotate_speed)
        };
    }
}

static void is_right(player_t *player)
{
    sfVector2f dir_cpy = player->camera.dir;
    sfVector2f plane_cpy = player->camera.plane;

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        player->camera.dir = (sfVector2f){
            player->camera.dir.x * cos(-player->mov->rotate_speed)
            - player->camera.dir.y * sin(-player->mov->rotate_speed),
            dir_cpy.x * sin(-player->mov->rotate_speed)
            + player->camera.dir.y * cos(-player->mov->rotate_speed)
        };
        player->camera.plane = (sfVector2f){
            player->camera.plane.x * cos(-player->mov->rotate_speed)
            - player->camera.plane.y * sin(-player->mov->rotate_speed),
            plane_cpy.x * sin(-player->mov->rotate_speed)
            + player->camera.plane.y * cos(-player->mov->rotate_speed)
        };
    }
}

static void is_up(player_t *player, map_t map)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        footstep_sound(player->sound, sfKeyZ);
        if (sfMusic_getStatus(player->sound->sound_footstep) != sfPlaying)
            sfMusic_play(player->sound->sound_footstep);
        if (GET_TIL(map, (int)(player->camera.pos.x + player->camera.dir.x
            * player->mov->mov_speed * PLAYER_BORDER_MAP),
            (int)player->camera.pos.y) == 0)
            player->camera.pos.x += player->camera.dir.x
                * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->camera.pos.x,
            (int)(player->camera.pos.y + player->camera.dir.y
                * player->mov->mov_speed * PLAYER_BORDER_MAP)) == 0)
            player->camera.pos.y += player->camera.dir.y
                * player->mov->mov_speed;
    }
    footstep_sound(player->sound, sfKeyZ);
}

static void is_down(player_t *player, map_t map)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        footstep_sound(player->sound, sfKeyS);
        if (GET_TIL(map, (int)(player->camera.pos.x - player->camera.dir.x
            * player->mov->mov_speed * PLAYER_BORDER_MAP),
            (int)player->camera.pos.y) == 0)
            player->camera.pos.x -= player->camera.dir.x
                * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->camera.pos.x,
            (int)(player->camera.pos.y - player->camera.dir.y
                * player->mov->mov_speed * PLAYER_BORDER_MAP)) == 0)
            player->camera.pos.y -= player->camera.dir.y
                * player->mov->mov_speed;
    }
    footstep_sound(player->sound, sfKeyS);
}

static void crab_left(player_t *player, map_t map)
{
    sfVector2f crab_mov = {-1 * player->camera.dir.y, player->camera.dir.x};

    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        footstep_sound(player->sound, sfKeyQ);
        crab_mov.x = -player->camera.dir.y;
        crab_mov.y = player->camera.dir.x;
        if (GET_TIL(map, (int)(player->camera.pos.x + crab_mov.x
            * player->mov->mov_speed), (int)player->camera.pos.y) == 0)
            player->camera.pos.x += crab_mov.x * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->camera.pos.x, (int)(player->camera.pos.y
            + crab_mov.y * player->mov->mov_speed)) == 0)
            player->camera.pos.y += crab_mov.y * player->mov->mov_speed;
        if (GET_TIL(map, (int)(player->camera.pos.x + crab_mov.x
            * player->mov->mov_speed), (int)player->camera.pos.y) == 0)
            player->camera.pos.x += crab_mov.x * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->camera.pos.x, (int)(player->camera.pos.y
            + crab_mov.y * player->mov->mov_speed)) == 0)
            player->camera.pos.y += crab_mov.y * player->mov->mov_speed;
    }
    footstep_sound(player->sound, sfKeyQ);
}

static void crab_right(player_t *player, map_t map)
{
    sfVector2f crab_mov = (sfVector2f){player->camera.dir.y,
        -player->camera.dir.x};

    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        footstep_sound(player->sound, sfKeyD);
        crab_mov.x = player->camera.dir.y;
        crab_mov.y = -player->camera.dir.x;
        if (GET_TIL(map, (int)(player->camera.pos.x + crab_mov.x
            * player->mov->mov_speed), (int)player->camera.pos.y) == 0)
            player->camera.pos.x += crab_mov.x * player->mov->mov_speed;
        if (GET_TIL(map, (int)(player->camera.pos.x + crab_mov.x
            * player->mov->mov_speed), (int)player->camera.pos.y) == 0)
            player->camera.pos.x += crab_mov.x * player->mov->mov_speed;
        if (GET_TIL(map, (int)player->camera.pos.x, (int)(player->camera.pos.y
            + crab_mov.y * player->mov->mov_speed)) == 0)
            player->camera.pos.y += crab_mov.y * player->mov->mov_speed;
    }
    footstep_sound(player->sound, sfKeyD);
}

static void up_down(player_t *player, map_t map)
{
    is_up(player, map);
    is_down(player, map);
}

static void left_right(player_t *player)
{
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
