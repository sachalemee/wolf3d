/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** game_loop.c
*/

#include <math.h>
#include "wolfengine.h"
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

static int checkout_struct(game_t *game, player_t *player)
{
    if (game == NULL)
        return EXIT_F;
    if (player == NULL)
        return EXIT_F;
    return EXIT_S;
}

int game_loop(game_t *game, player_t *player)
{
    if (checkout_struct(game, player) == EXIT_F)
        return EXIT_F;
    while (sfRenderWindow_isOpen(game->window) == sfTrue) {
        events(game, player);
        sfRenderWindow_clear(game->window, game->bg);
        debug_player(player, game);
        if (sfMusic_getStatus(game->music) == sfStopped)
            sfMusic_play(game->music);
        browse_map(game);
        sfRenderWindow_display(game->window);
    }
    return EXIT_S;
}
