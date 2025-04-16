/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** game_loop.c
*/

#include <math.h>
#include "wolfengine.h"
#include "buttons.h"
#include "hmap.h"

int game_loop(game_t *game, entity_t *entity)
{

    init_buttons(game);
    while (sfRenderWindow_isOpen(game->window) == sfTrue) {
        menu(game, entity);
    }
    return EXIT_S;
}
