/*
** EPITECH PROJECT, 2025
** parser
** File description:
** parser.c
*/
#include "hmap.h"
#include "my.h"
#include "wolfengine.h"
#include "linked_lists.h"
#include "things.h"
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

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
    bool line_contains_an_invalid_value = false;

    if (map_arr[0] == NULL)
        return false;
    for (size_t x = 0; map_arr[x + 1] != NULL; x++) {
        size_dest->y = 0;
        for (size_t y = 0; map_arr[x][y] != '\0'; y++) {
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
    ++(size_dest->x);
    return (size_dest->x != 0 && size_dest->y != 0);
}

static bool tile_is_thing(int tile_code)
{
    if (tile_code == FAILURE || tile_code == EXIT || tile_code == START
        || tile_code == VOID)
        return false;
    if (game_tiles[tile_code].istangible == false)
        return true;
    return false;
}

static int get_thing(int tile_code, thing_t **dest, sfVector2u *coords)
{
    sfVector3f float_coords = {(float)coords->x, (float)coords->y, 0};

    *dest = NULL;
    if (tile_is_thing(tile_code) == false)
        return SUCCESS;
    if (tile_code == GARCIA_TILE)
        *dest = init_garcia(&float_coords);
    if (tile_code == SIGNAL_TILE)
        *dest = init_signal(&float_coords);
    if (tile_code == BIG_BEN_TILE)
        *dest = init_big_ben(&float_coords);
    if (*dest == NULL)
        return FAILURE;
    return SUCCESS;
}

static int add_thing(int tile_code, sfVector2u *coords, map_t *dest)
{
    thing_t *new_thing = NULL;

    if (get_thing(tile_code, &new_thing, coords) == FAILURE)
        return FAILURE;
    if (new_thing == NULL)
        return SUCCESS;
    stack_item(new_thing, new_thing->destroyer,
        &(dest->map[coords->x][coords->y].things));
    if (dest->map[coords->x][coords->y].things.is_burnt)
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
        if (add_thing(current_tile_code, &map_coords, dest) == FAILURE)
            return FAILURE;
        dest->map[map_coords.x][map_coords.y].type =
            (game_tiles[current_tile_code].istangible) ?
                current_tile_code : AIR;
    }
    return SUCCESS;
}

static map_t *alloc_map(sfVector2u *size)
{
    map_t *new_map = calloc(1, sizeof(map_t));

    if (new_map == NULL)
        return NULL;
    new_map->size = (sfVector2u){size->x, size->y};
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

static int read_file_ctts(char const *const path, char **buffer)
{
    struct stat file_data = {0};
    FILE *file_ptr = NULL;

    if (stat(path, &file_data) == FAILURE)
        return FAILURE;
    file_ptr = fopen(path, "r");
    *buffer = malloc((file_data.st_size + 1) * sizeof(char));
    if (*buffer == NULL || file_ptr == NULL
        || fread(*buffer, sizeof(char), file_data.st_size, file_ptr) == 0
        || fclose(file_ptr) == EOF) {
        free(*buffer);
        if (file_ptr != NULL)
            fclose(file_ptr);
        *buffer = NULL;
        return FAILURE;
    }
    (*buffer)[file_data.st_size] = '\0';
    return SUCCESS;
}

static int get_map_arr(char const *const path, char ***map_arr)
{
    char *file_ctts = NULL;

    if (read_file_ctts(path, &file_ctts) == FAILURE)
        return FAILURE;
    *map_arr = my_str_to_word_array(file_ctts, "\n");
    free(file_ctts);
    if (*map_arr == NULL)
        return FAILURE;
    return SUCCESS;
}

map_t *get_map(const char *path)
{
    char **map_arr = NULL;
    map_t *map = NULL;
    sfVector2u size = {0, 0};

    if (get_map_arr(path, &map_arr) == FAILURE)
        return NULL;
    if (map_arr_is_valid(map_arr, &size) == false) {
        destroy_word_array(map_arr);
        return NULL;
    }
    map = alloc_map(&size);
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
