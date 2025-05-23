/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** hmap.h
*/

#ifndef HMAP_H
    #define HMAP_H
    // #define MAP_W 24
    // #define MAP_H 24
    // #define MAP_S (MAP_W * MAP_H)
    #define MAPS_DIR "./ressources/Wolf3D_LVLS/"
    #include "my.h"
    #include <SFML/Graphics.h>
    #define MCTAINS(m, x, y) (x >= 0 && y >= 0 && x < (int)m.w && y < (int)m.h)
    #define GET_TIL(m, x, y) (MCTAINS(m, x, y) ? m.map[x][y] : 0)

// a map being :
//     11111...
//     1S00e...
//     ...
// top left is (x, y) = (0, 0)

enum tile_types {
    VOID = 0,
    WALL_TYPE_1 = 1,
    WALL_TYPE_2 = 2,
    WALL_TYPE_3 = 3,
    WALL_TYPE_4 = 4,
    WALL_TYPE_5 = 5,
    WALL_TYPE_6 = 6,
    WALL_TYPE_7 = 7,
    WALL_TYPE_8 = 8,
    START = 9,
    ENEMY = 10,
    EXIT = 11
};

typedef struct game_tile_s {
    int id;
    char config_value;
    bool istangible;
} game_tile_t;

// void
// walls
// start
// enemy
// exit
static const game_tile_t game_tiles[] = {
    {0, '0', false},
    {1, '1', true},
    {1, '2', true},
    {1, '3', true},
    {1, '4', true},
    {1, '5', true},
    {1, '6', true},
    {1, '7', true},
    {1, '8', true},
    {2, 'S', false},
    {3, 'e', false},
    {4, 'E', false},
    {-1, '\0', false}
};

static const char *const levels[] = {
    "stage1",
    "stage2",
    "stage3",
    "stage4",
    "stage5",
    "stage6",
    NULL
};

typedef struct map_s {
    char **map;
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
