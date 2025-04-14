/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** mov_player.c
*/

#include <math.h>
/* have to remove, just need for debug */
#include <stdio.h>

#include <math.h>
#include "wolfengine.h"
#include "hmap.h"

static void update_delta(player_t *player)
{
    player->mov->delta.x = cos(player->mov->angle) * player->speed;
    player->mov->delta.y = sin(player->mov->angle) * player->speed;
}

static void left_right(sfEvent event, player_t *player)
{
    if (is_keyboard_input(event, sfKeyQ)) {
        printf("player->mov->angle: %.2f°\n", player->mov->angle * 180 / PI);
        player->mov->angle -= PLAYER_QUICKSPIN;
        if (player->mov->angle < 0) {
            player->mov->angle += 2 * PI;
        }
        update_delta(player);
    }
    if (is_keyboard_input(event, sfKeyD)) {
        printf("player->mov->angle: %.2f°\n", player->mov->angle * 180 / PI);
        player->mov->angle += PLAYER_QUICKSPIN;
        if (player->mov->angle > 2 * PI) {
            player->mov->angle -= 2 * PI;
        }
        update_delta(player);
    }
}

static void up_down(sfEvent event, player_t *player)
{
    if (is_keyboard_input(event, sfKeyZ)) {
        printf("player->mov->angle: %.2f°\n", player->mov->angle * 180 / PI);
        player->pos.x += player->mov->delta.x;
        player->pos.y += player->mov->delta.y;
    }
    if (is_keyboard_input(event, sfKeyS)) {
        printf("player->mov->angle: %.2f°\n", player->mov->angle * 180 / PI);
        player->pos.x -= player->mov->delta.x;
        player->pos.y -= player->mov->delta.y;
    }
}

void mov_player(sfEvent event, player_t *player, game_t *game)
{
    if (game == NULL)
        return;
    up_down(event, player);
    left_right(event, player);
}
