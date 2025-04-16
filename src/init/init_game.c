/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_game.c
*/

#include "wolfengine.h"
#include <stdlib.h>

info_t *init_struct_info(void)
{
    info_t *info = malloc(sizeof(info_t));

    info->d_time = 0.0;
    return info;
}

map_t *init_struct_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->map_pos = (sfVector2i){0, 0};
    return map;
}

int init_game(game_t *game)
{
    game->window = set_window();
    game->clock = sfClock_create();
    game->music = sfMusic_createFromFile(MUSIC_PATH);
    game->bg = sfColor_fromRGB(0, 0, 0);
    game->info = init_struct_info();
    game->map = init_struct_map();
    return EXIT_S;
}
