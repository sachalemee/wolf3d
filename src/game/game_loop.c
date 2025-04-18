/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** game_loop.c
*/

#include <stdlib.h>
#include <math.h>
#include "wolfengine.h"
#include "buttons.h"
#include "hmap.h"

static void debug_player(player_t *player, game_t *game)
{
    sfCircleShape *dot = sfCircleShape_create();

    sfCircleShape_setRadius(dot, 3);
    sfCircleShape_setFillColor(dot, PLAYER_COLOR);
    sfCircleShape_setPosition(dot, player->pos);
    sfRenderWindow_drawCircleShape(game->window, dot, NULL);
    sfCircleShape_destroy(dot);
}

int game_loop(game_t *game, player_t *player)
{
    while (sfRenderWindow_isOpen(game->window) == sfTrue) {
        sfRenderWindow_clear(game->window, game->bg);
        events(game, player);
        if (error_handling(game, player) == EXIT_F)
            return EXIT_F;
        draw_in_game(game);
        debug_player(player, game);
        sfRenderWindow_display(game->window);
    }
    return EXIT_S;
}
