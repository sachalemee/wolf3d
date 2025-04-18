/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** game_scene.c
*/

#include "wolfengine.h"

int game_scene(game_t *game, player_t *player, info_t *info)
{
    info->d_time = sfTime_asSeconds(sfClock_restart(game->clock));
    player->mov->mov_speed = info->d_time * PLAYER_MOV_SPEED;
    player->mov->rotate_speed = info->d_time * PLAYER_ROTA_SPEED;
    sfRenderWindow_clear(game->window, game->bg);
    events_game(game, player, info);
    draw_in_game(game, player);
    sfRenderWindow_display(game->window);
    return EXIT_S;
}
