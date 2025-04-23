/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** wolfengine.h
*/

#ifndef WOLFENGINE_H
    #define WOLFENGINE_H

    /* sfml include */
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    /* libc include */
    #include <sys/types.h>

    /* wolf include */
    #include "hmap.h"

    /* value specific of the window */
    #define WIN_FRAME 60
    #define WIN_BITS 32
    #define WIN_WIDTH 1920
    #define WIN_HEIGHT 1080

    /* window title */
    #define WIN_TITLE "wolfengine"

    /* music volume */
    #define MUSIC_MAX 100.0
    #define MUSIC_MIN 0.0
    #define MUSIC_GAP 5.0

    /* ressources */
    #define MUSIC_PATH "ressources/Wolf3D_OGG/game_music/URAHERO.ogg"
    #define TEXTURE_OVERLAY_SPRINT "ressources/Wolf3D_IMG/sprint-overlay.png"
    #define TEXTURE_WALL "ressources/Wolf3D_IMG/wall_bamboo.png"

    /* color of the player */
    #define PLAYER_START_POS_X 22.0
    #define PLAYER_START_POS_Y 11.5
    #define PLAYER_MOV_SPEED 2.0
    #define PLAYER_ROTA_SPEED 3.0
    #define PLAYER_FOV 1
    #define PLAYER_BORDER_MAP 5
    #define PLAYER_SPRINT_SPEED 5
    #define DEFAULT_RENDER_DIST 1000

    /* wall info */
    #define WALL_HEIGHT_MULTI 0
    #define NUM_RAYS 1000
    #define ROOF_RGB 90, 231, 223
    #define FLOOR_RGB 223, 231, 90
    #define END_SIZE 2.5

    /* return values */
    #define EXIT_S 0
    #define EXIT_F 84
    #define EXIT_E -1
    #define EXIT_P 1
    #define FAILURE -1
    #define SUCCESS 0

    /* map define */
    #define IS_WALL 1
    #define IS_VOID 0

typedef struct rays_s {
    sfVertexArray *vertex;
    sfRenderStates wall_states;
    sfVector2f raydir;
    double camera_x;
    sfVector2f delta_dist;
    sfVector2f sidedist;
    sfVector2i step;
    double perpwalldist;
    int side;
    double pixel_texture;
} rays_t;

typedef struct mov_s {
    double mov_speed;
    double rotate_speed;
} mov_t;

typedef struct player_s {
    sfVector2f pos;
    sfVector2f dir;
    sfVector2f plane;
    size_t render_dist;
    mov_t *mov;
    rays_t *rays;
    sfVector2i map;
} player_t;

typedef struct time_info_s {
    sfClock *clock;
    float last_update;
    float delta_time;
} time_info_t;

typedef struct horiz_surfaces_s {
    sfRectangleShape *roof;
    sfRectangleShape *floor;
} horiz_surfaces_t;

typedef struct sprites_s {
    sfTexture *sprint_overlay_tex;
    sfSprite *sprint_overlay;
} sprites_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfMusic *music;
    horiz_surfaces_t background;
    sprites_t sprites;
    time_info_t time;
} game_t;

enum scenes {
    GAME = 0,
    PAUSE = 1,
    SETTINGS = 2
};

// int scene; corresponds to the above enum (user location)
typedef struct sys_data_s {
    game_t *game;
    player_t *player;
    map_t *current_map;
    ssize_t level;
    float difficulty;
    int scene;
} sys_data_t;

/* init */
void destroy_game(game_t *game);
game_t *init_game(void);
int init_sys_data(sys_data_t *sys, const char *_Nullable map_path);
void destroy_player(player_t *player);
player_t *init_player(sfVector2f pos);
// void init_map(player_t *player);

/* init function relative to a struct */
sfRenderWindow *set_window(void);

/* time */
void update_time(time_info_t *time);

/* events */
int events(sys_data_t *sys);
sfBool is_keyboard_input(sfEvent event, sfKeyCode key);
void mov_player(player_t *player, map_t map);

/* game */
int game_loop(sys_data_t *sys_data);
int start(const char *_Nullable map_path);

/* in game */
void draw_in_game(game_t *game, player_t *player, map_t map);
void draw_background(sfRenderWindow *win, horiz_surfaces_t background);

/* raycast */
void raycasting(game_t *game, player_t *player, map_t map);

/* destroy */
void destroy_sys(sys_data_t sys);
// void destroy_all(game_t *game);

/* error handling */
int error_handling(game_t *game, player_t *player);

/* math */
double degree_to_radian(double angle);

/* map */
int browse_map(game_t *game, map_t map);

/* hud */
int draw_hud_overlay(game_t *game, player_t *player);

#endif /* WOLFENGINE_H */
