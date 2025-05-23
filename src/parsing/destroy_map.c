/*
** EPITECH PROJECT, 2025
** destroy_map
** File description:
** destroy_map.c
*/
#include "hmap.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>

static void destroy_map_line(map_tile_t *map_line, size_t len)
{
    if (map_line == NULL)
        return;
    for (size_t i = 0; i < len; i++)
        burn_list(&(map_line[i].things));
    free(map_line);
}

void destroy_map(map_t *map)
{
    // sfVector2i free_coords = {0, 0};

    if (map == NULL)
        return;
    if (map->map == NULL) {
        free(map);
        return;
    }
    for (size_t i = 0; map->map[i] != NULL && i < map->size.x; i++)
        destroy_map_line(map->map[i], map->size.y);
    free(map->map);
    free(map);
    memset((void *)&map, 0, sizeof(typeof(map)));
}
