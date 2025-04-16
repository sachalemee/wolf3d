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

int game_scene(game_t *game, player_t *player, info_t *info)
{
    info->d_time = sfTime_asSeconds(sfClock_restart(game->clock));
    player->mov_speed = info->d_time * PLAYER_MOV_SPEED;
    player->rotate_speed = info->d_time * PLAYER_ROTA_SPEED;
    events(game, player);
    sfRenderWindow_clear(game->window, game->bg);
    draw_in_game(game);
    raycasting(game, player);
    sfRenderWindow_display(game->window);
    return EXIT_S;
}

int game_loop(game_t *game)
{
    player_t *player = init_player();
    info_t *info = init_info();

    while (sfRenderWindow_isOpen(game->window) == sfTrue) {
        game_scene(game, player, info);
    }
    return EXIT_S;
}
