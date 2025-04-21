/*
** EPITECH PROJECT, 2025
** show_map_debug
** File description:
** show_map_debug.c
*/

#include "hmap.h"
#include "my.h"
#include <stdio.h>
#include <unistd.h>

void show_map_debug(map_t *map)
{
    sfVector2u cds = {0};
    bool isend = false;
    bool isstt = false + 0 * printf("w:%lu h:%lu\n", map->w, map->h);

    if (map == NULL) {
        my_dputstr(2, "{EMPTY-MAP}\n");
        return;
    }
    for (size_t i = 0; i < map->w * map->h; i++) {
        cds = (sfVector2u){i % map->w, i / map->w};
        isend = (cds.x == map->end.x && cds.y == map->end.y);
        isstt = (cds.x == map->start.x && cds.y == map->start.y);
        if (i != 0 && cds.x == 0)
            my_dputstr(2, "\n");
        if (isend || isstt) {
            my_dputstr(2, ((isend) ? "E" : "S"));
        } else
            write(2, &(game_tiles[
                (size_t)(map->map[cds.x][cds.y])].config_value), 1);
    }
}
