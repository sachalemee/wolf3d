/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** wolfengine.h
*/

#ifndef THINGS_H
    #define THINGS_H
    #include <SFML/Graphics.h>
    #include <sys/types.h>
    #define NORM(vec3) sqrt(SQUARE(vec3.x) + SQUARE(vec3.y) + SQUARE(vec3.z))

    #define THING_TEXTURES_PATH "ressources/Wolf3D_IMG/thing_textures/"
    #define TH_TXT thing_textures
    #define LEN_OF_THING_TEXTURES (5)
    #define TRYIDLE(mov_w, state) (mov_w <= 0) ? IDLE : state
static char const *const thing_textures[] = {
    THING_TEXTURES_PATH"garcia.png",
    THING_TEXTURES_PATH"big_ben.png",
    THING_TEXTURES_PATH"signal.png",
    THING_TEXTURES_PATH"banana.png",
    THING_TEXTURES_PATH"skull_on_a_stick.png"
};

typedef struct sys_data_s sys_data_t;
typedef struct camera_s camera_t;

typedef struct thing_s {
    void (*destroyer)(void *self); // self should be a thing_t * but needed
        // conventional destroyer header for cross compatibility
    void (*updater)(struct thing_s *self, sys_data_t *sys_data);
    __int128_t id;
    __id_t type_id;
    sfSprite *sprite;
    sfVector3f coords;
    sfGlslVec4 movement; // 4th dimension is time
    void *data;
    bool onscreen;
    bool is_burned;
    double player_dist;
} thing_t;

enum thing_type_ids {
    GARCIA = 0,
    BIG_BEN = 1,
    SIGNAL = 2,
    BANANA = 3,
    STICK = 4
};

enum monster_states {
    IDLE = 0,
    WALKING = 1,
    ATTACKING = 2
};

typedef struct monster_data_s {
    size_t health;
    size_t damage;
    float speed;
    float range;
    float radius;
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
enum {
    GARCIA_IMG = 0,
    BIG_BEN_IMG = 1,
    SIGNAL_IMG = 2,
    BANANA_IMG = 3,
    STICK_IMG = 4
};

/* DEFAULT STATS ENEMIES */
    /* GARCIA */
    #define GARCIA_DFLT_HP 100
    #define GARCIA_DFLT_DMG 10
    #define GARCIA_DFLT_SPEED 1.0
    #define GARCIA_RADIUS 0.5
    #define GARCIA_RANGE 0.5
    /* SIGNAL */
    #define SIGNAL_DFLT_HP 80
    #define SIGNAL_DFLT_DMG 15
    #define SIGNAL_DFLT_SPEED 1.2
    #define SIGNAL_RADIUS 0.4
    #define SIGNAL_RANGE 5
    /* BIG_BEN */
    #define BIG_BEN_DFLT_HP 200
    #define BIG_BEN_DFLT_DMG 17
    #define BIG_BEN_DFLT_SPEED 0.85
    #define BIG_BEN_RADIUS 0.7
    #define BIG_BEN_RANGE 0.5
    /* BANANA */
    #define BANANA_DFLT_HP 1
    #define BANANA_DFLT_DMG 7
    #define BANANA_DFLT_SPEED 2
    #define BANANA_RADIUS 0.2
    #define BANANA_RANGE 0.2
/* ~~~~~~~~~~~~~~~~~~~~~ */

    #define STATE_CHANGE_EQUATION_HALF_LIFE 0.6931472
    #define AVERAGE_STATE_CHANGE_COOLDOWN 4 // in seconds
    #define AVERAGE_WALK_DIST 4

void update_banana(thing_t *banana, sys_data_t *sys_data);
thing_t *throw_banana(sfVector3f *player_pos, sfVector3f *origin_coords);
thing_t *init_banana(sfVector3f *coords);
void big_ben_update(thing_t *big_ben, sys_data_t *sys_data);
thing_t *init_big_ben(sfVector3f *coords);
void garcia_update(thing_t *garcia, sys_data_t *sys_data);
thing_t *init_garcia(sfVector3f *coords);
int load_thing_textures(sfTexture *textures[5]);
double get_rand_coef(void);
bool monster_idle_state_change(float time_since_last_action);
void monster_vector_set_speed(sfGlslVec4 *to_set, float speed);
void monster_random_walk_vector(sfGlslVec4 *to_set, float speed);
void move_monster(sfVector3f *monster_coords,
    sfGlslVec4 *monster_movement, float delta_time);
void destroy_monster(void *monster);
bool monster_try_walking(thing_t *monster);
bool monster_go_to_point(thing_t *monster, sfVector3f *point);
thing_t *init_monster(sfVector3f *coords);
int signal_shoot(thing_t *signal, sfVector3f *player_pos,
    linked_list_t *things);
void signal_update(thing_t *signal, sys_data_t *sys_data);
thing_t *init_signal(sfVector3f *coords);
bool monster_dist_less_than(thing_t *monster, sfVector3f *pos, float dist);

// display
typedef struct monster_comparison_data_s {
    int axis;
    int direction;
} monster_comparison_data_t;

void show_things(double *raymap, camera_t *camera,
    linked_list_t *things, sfRenderWindow *win);

#endif /* THINGS_H */
