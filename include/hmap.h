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
    #define MCTAINS(m, x, y) (x >= 0 && y >= 0 && x < (int)m.w && y < (int)m.h)
    #define GET_TIL(m, x, y) (MCTAINS(m, x, y) ? m.map[x][y] : 0)

// a map being :
//     11111...
//     1S00e...
//     ...
// top left is (x, y) = (0, 0)

/*~~~~~~~~~~~~~~~~~~~~THINGS~~~~~~~~~~~~~~~~~~~~*/
typedef struct thing_s {
    void (*destroyer)(struct thing_s *self);
    int (*updater)(struct thing_s *self, sys_data_t *sys_data);
    sfSprite *sprite;
    sfVector3f coords;
    void *data;
} thing_t;

enum monster_types {
    GARCIA = 0,
    BIG_BEN = 1,
    SIGNAL = 2
};

enum monster_states {
    IDLE = 0,
    WALKING = 1,
    SHOOTING = 2
};

typedef struct monster_data_s {
    int type;
    size_t health;
    size_t damage;
    float speed;
    int state;
} monster_data_t;

enum damage_team {
    NO_TEAM = 0,
    PLAYER_TEAM = 1,
    MONSTER_TEAM = 2
};

typedef struct projectile_s {
    sfVector3f trajectory;
    int team;
} projectile_t;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

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
