/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** start.c
*/

#include <stddef.h>
#include "wolfengine.h"
#include "buttons.h"

int start(void)
{
    game_t game = {NULL};

    init_buttons(&game);
    init_game(&game);
    if (game_loop(&game) == EXIT_F)
        return EXIT_F;
    destroy_all(&game);
    return EXIT_S;
}
