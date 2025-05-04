/*
** EPITECH PROJECT, 2025
** parser
** File description:
** parser.c
*/

#include "hmap.h"
#include "my.h"
#include "wolfengine.h"
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

static char get_tile_code(const char tile)
{
    for (size_t i = 0; game_tiles[i].config_value != '\0'; i++) {
        if (game_tiles[i].config_value == tile)
            return (char)i;
    }
    return FAILURE;
}

static bool map_arr_is_valid(char **map_arr, sfVector2u *size_dest)
{
    ssize_t reference_y_size = -1;
    bool line_contains_an_invalid_value = -1;

    if (map_arr[0] == NULL)
        return false;
    for (size_t x = 0; map_arr[x + 1] != NULL; x++) {
        for (size_t y = 0; map_arr[x][y] != NULL; y++) {
            line_contains_an_invalid_value = line_contains_an_invalid_value ||
                (get_tile_code(map_arr[x][y]) == FAILURE);
            (size_dest->y)++;
        }
        if (line_contains_an_invalid_value)
            return false;
        if (reference_y_size != -1 && reference_y_size != size_dest->y)
            return false;
        (size_dest->x)++;
        if (reference_y_size == -1)
            reference_y_size = size_dest->y;
    }
}

static bool tile_is_thing(int tile_code)
{
    if (tile_code == FAILURE || tile_code == EXIT || tile_code == START)
        return false;
    if (game_tiles[tile_code].istangible == false)
        return true;
    return false;
}

static int get_thing(int tile_code, thing_t **dest)
{
    *dest = NULL;
    if (tile_is_thing(tile_code) == false)
        return SUCCESS;
    if (tile_code == GARCIA_TILE)
        *dest = garcia_init();
    if (tile_code == SIGNAL_TILE)
        *dest = signal_init();
    if (tile_code == BIG_BEN_TILE)
        *dest = big_ben_init();
    if (*dest == NULL)
        return FAILURE;
    return SUCCESS;
}

int add_thing(int tile_code, sfVector2u coords, map_t *dest)
{
    thing_t *new_thing = NULL;

    if (get_thing(tile_code, &new_thing) == FAILURE)
        return FAILURE;
    if (new_thing == NULL)
        return SUCCESS;
    stack_item(new_thing, &(dest->map[coords.x][coords.y].things),
        new_thing->destroyer);
    if (dest->map[coords.x][coords.y].things.is_burnt)
        return FAILURE;
    return SUCCESS;
}

static int parse_map(char *const *mapstr, map_t *dest)
{
    int current_tile_code = 0;
    sfVector2u map_coords = {0};

    for (size_t i = 0; i < dest->size.x * dest->size.y; i++) {
        map_coords.x = i % dest->size.x;
        map_coords.y = i / dest->size.x;
        current_tile_code = get_tile_code(mapstr[map_coords.x][map_coords.y]);
        if (current_tile_code == FAILURE)
            return FAILURE;
        if (current_tile_code == START)
            dest->start = (sfVector2f){map_coords.x, map_coords.y};
        if (current_tile_code == EXIT)
            dest->end = (sfVector2f){map_coords.x, map_coords.y};
        if (add_thing(current_tile_code, map_coords, dest) == FAILURE)
            return FAILURE;
        dest->map[map_coords.x][map_coords.y].type =
            (game_tiles[current_tile_code].istangible) ?
                current_tile_code : AIR;
    }
    return SUCCESS;
}

static map_t *alloc_map(char *const *map_arr, sfVector2u size)
{
    map_t *new_map = calloc(1, sizeof(map_t));

    if (new_map == NULL)
        return NULL;
    new_map->size = size;
    new_map->map = calloc(new_map->size.x, sizeof(map_tile_t *));
    if (new_map->map == NULL) {
        destroy_map(new_map);
        return NULL;
    }
    for (size_t i = 0; i < new_map->size.x; i++) {
        new_map->map[i] = calloc(new_map->size.y, sizeof(map_tile_t));
        if (new_map->map[i] == NULL) {
            destroy_map(new_map);
            return NULL;
        }
    }
    new_map->start = (sfVector2f){-1, -1};
    new_map->end = (sfVector2f){-1, -1};
    return new_map;
}

map_t *get_map(const char *path)
{
    char **map_arr = NULL;
    map_t *map = NULL;
    sfVector2u size = {0, 0};

    if (get_map_arr(path, &map_arr) == FAILURE)
        return NULL;
    if (map_arr_is_valid(map_arr, &size) == false) {
        free_fstrsplit(map_arr);
        return NULL;
    }
    map = alloc_map(map_arr, size);
    if (map == NULL || parse_map(map_arr, map) == FAILURE) {
        destroy_map(map);
        free_fstrsplit(map_arr);
        return NULL;
    }
    free_fstrsplit(map_arr);
    return map;
}

map_t *get_level(size_t level_nb)
{
    char *map_path = NULL;
    map_t *new_map = NULL;

    for (size_t i = 0; i < level_nb; i++)
        if (levels[i] == NULL)
            return NULL;
    map_path = CONCAT(MAPS_DIR, levels[level_nb]);
    if (map_path == NULL)
        return NULL;
    new_map = get_map(map_path);
    free(map_path);
    return new_map;
}
