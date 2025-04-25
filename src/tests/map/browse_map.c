/*
** EPITECH PROJECT, 2025
** wolfengine-v2-1
** File description:
** browse_map.c
*/

#include "wolfengine.h"
#include "hmap.h"

static int is_wall(int x, int y, map_t map)
{
    if (map.map[y][x] == 1) {
        return IS_WALL;
    } else {
        return IS_VOID;
    }
    return EXIT_E;
}

int browse_map(game_t *game, map_t map)
{
    if (game == NULL)
        return EXIT_S;
    for (size_t y = 0; y < map.h; y++) {
        for (size_t x = 0; x < map.w; x++) {
            is_wall(x, y, map);
        }
    }
    return EXIT_S;
}
