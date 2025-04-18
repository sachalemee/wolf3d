/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_map.c
*/
#include <stddef.h>
#include <stdlib.h>
#include "wolfengine.h"

hmap_t *init_map(player_t *player)
{
    player->map = malloc(sizeof(hmap_t));
    if (player->map == NULL)
        return NULL;
    player->map->map_pos = (sfVector2i){0, 0};
    return player->map;
}
