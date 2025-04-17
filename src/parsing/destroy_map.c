/*
** EPITECH PROJECT, 2025
** destroy_map
** File description:
** destroy_map.c
*/

#include "hmap.h"
#include "my.h"

void destroy_map(map_t *map)
{
    if (map == NULL)
        return;
    if (map->map) {
        for (size_t i = 0; i < map->w; i++)
            free(map->map[i]);
    }
    free(map->map);
    free(map->enemy_coords);
    free(map);
}
