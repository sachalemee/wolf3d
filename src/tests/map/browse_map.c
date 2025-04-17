/*
** EPITECH PROJECT, 2025
** wolfengine-v2-1
** File description:
** browse_map.c
*/

#include <stdio.h>
#include "wolfengine.h"
#include "hmap.h"

static int is_wall(int x, int y)
{
    if (map[y][x] == 1) {
        return IS_WALL;
    } else {
        return IS_VOID;
    }
    return EXIT_E;
}

int browse_map(game_t *game)
{
    if (game == NULL)
        return EXIT_S;
    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            is_wall(x, y);
        }
    }
    return EXIT_S;
}
