/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** game_loop.c
*/

#include <math.h>
#include "wolfengine.h"
#include "hmap.h"

int game_scene(game_t *game, player_t *player)
{
    game->info->d_time = sfTime_asSeconds(sfClock_restart(game->clock));
    player->mov_speed = game->info->d_time * PLAYER_MOV_SPEED;
    player->rotate_speed = game->info->d_time * PLAYER_ROTA_SPEED;
    events(game, player);
    if (error_handling(game, player) == EXIT_F)
        return EXIT_F;
    raycasting(game, player);
    draw_in_game(game);
    return EXIT_S;
}

int game_loop(game_t *game, player_t *player)
{
    while (sfRenderWindow_isOpen(game->window) == sfTrue) {
        sfRenderWindow_clear(game->window, game->bg);
        game_scene(game, player);
        sfRenderWindow_display(game->window);
    }
    return EXIT_S;
}
