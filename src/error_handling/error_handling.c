/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** error_handling.c
*/

#include "wolfengine.h"

static int checkout_struct(game_t *game, player_t *player)
{
    if (game == NULL)
        return EXIT_F;
    if (player == NULL)
        return EXIT_F;
    return EXIT_S;
}

int error_handling(game_t *game, player_t *player)
{
    if (checkout_struct(game, player) == EXIT_F)
        return EXIT_F;
    return EXIT_S;
}
