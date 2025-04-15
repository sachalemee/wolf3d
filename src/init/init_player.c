/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_player.c
*/

#include "wolfengine.h"
#include <stdlib.h>

static void init_mov(player_t *player)
{
    player->mov = malloc(sizeof(mov_t));
    if (player->mov == NULL)
        return;
    player->mov->delta.x = 0;
    player->mov->delta.y = 0;
    player->mov->angle = 0;
}

player_t *init_player(player_t *player)
{
    player->speed = PLAYER_SPEED;
    player->radius = PLAYER_RADIUS;
    player->color = PLAYER_COLOR;
    player->pos = (sfVector2f){PLAYER_POSX, PLAYER_POSY};
    init_mov(player);
    return player;
}
