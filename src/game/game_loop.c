/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** game_loop.c
*/

#include <stdlib.h>
#include <math.h>
#include "wolfengine.h"
#include "hmap.h"

static void update_player(player_t *player, time_info_t time)
{
    player->mov->mov_speed = time.delta_time * PLAYER_MOV_SPEED;
    player->mov->rotate_speed = time.delta_time * PLAYER_ROTA_SPEED;
}

int game_scene(game_t *game, player_t *player, map_t map, sys_data_t *sys)
{
    sfRenderWindow_clear(game->window, sfBlack);
    update_player(player, game->time);
    events(sys);
    draw_in_game(game, player, map);
    draw_hud_overlay(game, player);
    sfRenderWindow_display(game->window);
    return EXIT_S;
}

int game_loop(sys_data_t *sys_data)
{
    while (sfRenderWindow_isOpen(sys_data->game->window) == sfTrue) {
        update_time(&(sys_data->game->time));
        game_scene(sys_data->game, sys_data->player,
            *(sys_data->current_map), sys_data);
    }
    return EXIT_S;
}
