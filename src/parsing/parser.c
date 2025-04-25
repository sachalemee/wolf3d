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

static int get_map_str(const char *path, char **dest)
{
    int mapfd = 0;
    struct stat map_data = {};

    if (stat(path, &map_data) == FAILURE)
        return FAILURE;
    mapfd = open(path, O_RDONLY);
    *dest = malloc((map_data.st_size + 1) * sizeof(char));
    if (*dest == NULL)
        return FAILURE;
    if (mapfd == FAILURE) {
        free(*dest);
        return FAILURE;
    }
    if (read(mapfd, *dest, map_data.st_size) == FAILURE)
        return FAILURE;
    (*dest)[map_data.st_size] = '\0';
    return SUCCESS;
}

static char get_thing_code(const char tile)
{
    for (size_t i = 0; game_tiles[i].config_value != '\0'; i++) {
        if (game_tiles[i].config_value == tile)
            return (char)i;
    }
    return FAILURE;
}

static size_t count_enemies(const char *mapstr)
{
    size_t enemy_count = 0;

    for (size_t i = 0; mapstr[i] != '\0'; i++)
        enemy_count += (mapstr[i] == game_tiles[ENEMY].config_value);
    return enemy_count;
}

static int parse_map_tile(const char map_tile,
    sfVector2u coords, size_t *enemy_index, map_t *dest)
{
    int tile = get_thing_code(map_tile);

    if (tile == FAILURE)
        return FAILURE;
    if (tile == START)
        dest->start = (sfVector2f){coords.x, coords.y};
    if (tile == EXIT)
        dest->end = (sfVector2f){coords.x, coords.y};
    if (tile == ENEMY) {
        dest->enemy_coords[*enemy_index] = (sfVector2f){coords.x, coords.y};
        (*enemy_index)++;
    }
    return SUCCESS;
}

static char get_tile_code(const char tile)
{
    int index = get_thing_code(tile);

    return game_tiles[index].istangible * index;
}

static int get_str_as_map(const char *mapstr, map_t *map)
{
    if (map->w == 0 || map->h == 0 || map->start.x == -1 || map->end.x == -1)
        return FAILURE;
    map->map = malloc(map->w * sizeof(char *));
    if (map->map == NULL)
        return FAILURE;
    for (size_t x = 0; x < map->w; x++) {
        map->map[x] = malloc(map->h * sizeof(char));
        if (map->map[x] == NULL) {
            map->w = x - 1;
            return FAILURE;
        }
        for (size_t y = 0; y < map->h; y++) {
            map->map[x][y] = get_tile_code(mapstr[y * (map->w + 1) + x]);
        }
    }
    return SUCCESS;
}

static int parse_map(const char *mapstr, map_t *dest)
{
    sfVector2u coords = {0, 0};
    size_t enemy_index = 0;

    for (size_t i = 0; mapstr[i] != '\0'; i++) {
        if ((mapstr[i] == '\n' && dest->h != 0 && dest->w != coords.x) ||
            (mapstr[i] != '\n' && (mapstr[i + 1] == '\0' ||
            parse_map_tile(mapstr[i], coords, &enemy_index, dest) == FAILURE)))
            return FAILURE;
        if (mapstr[i] == '\n') {
            (dest->h)++;
            dest->w = coords.x;
            coords = (sfVector2u){0, coords.y + 1};
        } else
            (coords.x)++;
    }
    dest->enemy_coords[enemy_index] = (sfVector2f){-1, -1};
    if (get_str_as_map(mapstr, dest) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

static map_t *alloc_map(void)
{
    map_t *new_map = calloc(1, sizeof(map_t));

    if (new_map == NULL)
        return NULL;
    new_map->start = (sfVector2f){-1, -1};
    new_map->end = (sfVector2f){-1, -1};
    return new_map;
}

map_t *get_map(const char *path)
{
    char *mapstr = NULL;
    map_t *map = NULL;
    sfVector2f *enemies_positions = NULL;

    if (get_map_str(path, &mapstr) == FAILURE)
        return NULL;
    map = alloc_map();
    enemies_positions = malloc(sizeof(sfVector2f) * (count_enemies(path) + 1));
    if (check_mallocs(3, "", map, enemies_positions, mapstr) == false)
        return NULL;
    map->enemy_coords = enemies_positions;
    if (parse_map(mapstr, map) == FAILURE) {
        destroy_map(map);
        return NULL;
    }
    free(mapstr);
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
