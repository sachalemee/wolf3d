/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** game_scene.c
*/

#include "wolfengine.h"

static void update_player(player_t *player, time_info_t time)
{
    player->mov->mov_speed = time.delta_time * PLAYER_MOV_SPEED;
    player->mov->rotate_speed = time.delta_time * PLAYER_ROTA_SPEED;
}

int game_scene(game_t *game, sys_data_t *sys)
{
    sfRenderWindow_clear(sys->window, sfBlack);
    update_player(&(game->player), sys->time);
    if (game_events(sys) == EXIT_FAIL)
        return EXIT_FAIL;
    draw_in_game(sys, game, *(game->current_map));
    sfRenderWindow_display(sys->window);
    return EXIT_SUCCESS;
}
