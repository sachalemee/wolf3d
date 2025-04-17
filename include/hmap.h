/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** hmap.h
*/

#ifndef HMAP_H
    #define HMAP_H
    #define MAP_W 24
    #define MAP_H 24
    #define MAP_S (MAP_W * MAP_H)
    #define MAPS_DIR "./ressources/Wolf3D_LVLS/"
    #include "my.h"
    #include "wolfengine.h"
// a map being :
//     11111...
//     1S00e...
//     ...
// top left is (x, y) = (0, 0)

enum tile_types {
    VOID = 0,
    WALL = 1,
    START = 2,
    ENEMY = 3,
    EXIT = 4
};

typedef struct game_tile_s {
    int id;
    char config_value;
    bool istangible;
} game_tile_t;

// void
// wall
// start
// enemy
// exit
static const game_tile_t game_tiles[] = {
    {0, '0', false},
    {1, '1', true},
    {2, 'S', false},
    {3, 'e', false},
    {4, 'E', false},
    {-1, '\0', false}
};

typedef struct game_s game_t;

extern int map[MAP_W][MAP_H];

static const char *const levels[] = {
    "stage1",
    NULL
};

typedef struct map_s {
    int **map;
    size_t w;
    size_t h;
    sfVector2f start;
    sfVector2f end;
    sfVector2f *enemy_coords;
} map_t;

void destroy_map(map_t *map);
map_t *get_map(const char *path);
map_t *get_level(size_t level_nb);
void show_map_debug(map_t *to_show);

#endif /* MAP_H */
