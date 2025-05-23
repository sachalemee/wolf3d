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

void destroy_map(map_t *map)
{
    if (map == NULL)
        return;
    if (map->map == NULL) {
        free(map);
        return;
    }
    for (size_t i = 0; map->map[i] != NULL && i < map->size.x; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
    memset((void *)&map, 0, sizeof(typeof(map)));
}
