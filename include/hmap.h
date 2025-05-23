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
    #include "linked_lists.h"
    #include <SFML/Graphics.h>
    #define X_IN(s, e, x) ((float)s <= (float)x && (float)x <= (float)(e))
    #define MCTAINS(m, X, Y) (X_IN(0, m->size.x, X) && X_IN(0, m->size.y, Y))
    #define GET_TIL(m, x, y) (MCTAINS(m, x, y) ? m->map[x][y].type : 0)

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
    GARCIA_TILE = 10,
    BIG_BEN_TILE = 11,
    SIGNAL_TILE = 12,
    EXIT = 13
};

typedef struct game_tile_s {
    char config_value;
    bool istangible;
} game_tile_t;

// void
// walls
// start
// enemy
// exit
static const game_tile_t game_tiles[] = {
    {'0', false},
    {'1', true},
    {'2', true},
    {'3', true},
    {'4', true},
    {'5', true},
    {'6', true},
    {'7', true},
    {'8', true},
    {'S', false},
    {'G', false},
    {'B', false},
    {'S', false},
    {'E', false},
    {'\0', false}
};

static const char *const levels[] = {
    "stage1",
    "stage2",
    "stage3",
    "stage4",
    NULL
};

typedef struct map_tile_s {
    linked_list_t things;
    char type;
} map_tile_t;

typedef struct map_s {
    map_tile_t **map;
    sfVector2u size;
    sfVector2f start;
    sfVector2f end;
} map_t;

void destroy_map(map_t *map);
map_t *get_map(const char *path);
map_t *get_level(size_t level_nb);
void show_map_debug(map_t *to_show);

#endif /* MAP_H */
