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
    #include <stdbool.h>

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
    #define SONGS_PATH "ressources/Wolf3D_OGG/"
    #define MUSIC_PATH_GAME SONGS_PATH"game_music/URAHERO.ogg"
    #define MUSIC_PATH_MENU SONGS_PATH"game_music/Tropical_music_bg.ogg"
    #define TEXTURE_OVERLAY_SPRINT "ressources/Wolf3D_IMG/sprint-overlay.png"
    #define TEXTURE_WALL "ressources/Wolf3D_IMG/wall_bamboo.png"
    #define BG_MENU SONGS_PATH"game_background/background_menu.png"
    #define BACKGROUND_MENU_DEF 0, 0, 1791, 1000
    #define BG_RECT 1791.75
    #define BG_MAX_FRAME 8
    #define BG_SPEED_FRAME 5

    /* color of the player */
    #define PLAYER_START_POS_X 22.0
    #define PLAYER_START_POS_Y 11.5
    #define PLAYER_MOV_SPEED 2.0
    #define PLAYER_ROTA_SPEED 3.0
    #define PLAYER_FOV 1
    #define PLAYER_BORDER_MAP 5
    #define PLAYER_SPRINT_SPEED 5
    #define DEFAULT_RENDER_DIST 1000
    #define DEFAULT_DIFFICULTY 0.5

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

typedef struct player_settings_s {
    double mov_speed;
    double rotate_speed;
} player_settings_t;

typedef struct player_s {
    sfVector2f dir;
    sfVector2f plane;
    rays_t rays;
    player_settings_t *mov;
    sfVector2i map;
    sfVector2f pos;
} player_t;

typedef struct set_texture_and_sprite_s {
    sfTexture *texture_bg;
    sfSprite *sprite_bg;
} sprite_t;

typedef struct animated_sprite_s {
    sfIntRect rect;
    int current_frame;
    int max_frame;
} anim_t;

typedef struct entity_s {
    sprite_t sprite;
    anim_t anim;
} entity_t;

typedef enum state_s {
    STATE_MENU,
    STATE_GAME
} state_t;
    #define DEFAULT_SCENE STATE_MENU

typedef struct buttons_s buttons_t;
typedef struct time_info_s {
    sfClock *clock;
    float last_update;
    float delta_time;
} time_info_t;

typedef struct sprites_s {
    sfTexture *sprint_overlay_tex;
    sfSprite *sprint_overlay;
} sprites_t;

typedef struct musics_s {
    sfMusic *menu_music;
    sfMusic *game_music;
} musics_t;

typedef struct menu_s {
    buttons_t **buttons;
    entity_t *entity;
} menu_t;

typedef struct game_s {
    sfRectangleShape *background_dsp_rect;
    sprites_t sprites;
    ssize_t level;
    map_t *current_map;
    player_t player;
} game_t;

typedef struct settings_s {
    size_t render_dist;
    float difficulty;
    player_settings_t *player_settings;
} settings_t;

    #define MORSHU_FRAME_COUNT 32
    #define MORSHU_HEIGHT 281
    #define MORSHU_SPEED 42
    #define MORSHU_TEXTURE "ressources/Wolf3D_IMG/morshu_dance_anim_sprite.png"
typedef struct error_screen_s {
    size_t frame_index;
    size_t frame_count;
    sfTexture *no_tex;
    sfSprite *error_screen_background;
} error_screen_t;

typedef struct scene_s {
    error_screen_t error_scene;
    menu_t menu;
    game_t game;
    state_t state;
    musics_t musics;
} scene_t;

// int scene; corresponds to the above enum (user location)
typedef struct sys_data_s {
    sfRenderWindow *window;
    bool is_running;
    scene_t scene;
    settings_t settings;
    time_info_t time;
} sys_data_t;

/* init */
void destroy_menu(menu_t menu);
int init_menu(menu_t *menu);
void destroy_settings(settings_t settings);
int init_settings(settings_t *settings, player_settings_t *player_settings);
void close_menu(sys_data_t *sys);
void destroy_game(game_t game);
int init_game(game_t *game, const char *_Nullable map_path);
int init_sys_data(sys_data_t *sys, const char *_Nullable map_path);
int init_rays(rays_t *rays);
void destroy_rays(rays_t rays);
void destroy_player(player_t player);
int init_player(sfVector2f coords, player_t *dest);
int init_scene(scene_t *scene, const char *_Nullable map_path,
    sfRenderWindow *win);
void destroy_scene(scene_t scene);
int init_musics(musics_t *musics);
void destroy_musics(musics_t musics);
int init_entity(entity_t **entity);
void destroy_entity(entity_t *entity);
// void init_map(player_t *player);

/* init function relative to a struct */
int init_window(sfRenderWindow **window);

/* time */
void update_time(time_info_t *time);
int init_time(time_info_t *time);
void destroy_time(time_info_t time);

/* events */
int game_events(sys_data_t *sys);
void close_window(sys_data_t *sys, sfEvent event);
int set_fullscreen(sys_data_t *sys, sfEvent event);

void mov_player(player_t *player, map_t map);

/* game */
int game_loop(sys_data_t *sys_data);
int start(const char *_Nullable map_path);

/* in game */
void draw_in_game(game_t *game, map_t map, settings_t *settings,
    sfRenderWindow *win);
void draw_background(sfRenderWindow *win,
    sfRectangleShape *background_dsp_rect);

/* raycast */
void raycasting(game_t *game, map_t map, settings_t *settings,
    sfRenderWindow *win);

/* destroy */
void destroy_sys(sys_data_t sys);
// void destroy_all(game_t *game);

/* error handling */
int error_handling(game_t *game, player_t *player);

/* map */
int browse_map(game_t *game, map_t map);

/* hud */
int draw_hud_overlay(game_t *game, player_t *player);

/* EVENTS */
sfBool is_keyboard_input(sfEvent event, sfKeyCode key);

/* call menu */
    #define MENU_SCALE 1.25, 1.2
int update_menu(sys_data_t *sys);
int events_menu(sys_data_t *sys);
void animated_bg(entity_t *entity, time_info_t *time);
void draw_bg_menu(menu_t *menu, sfRenderWindow *win);
void play_game(sys_data_t *sys);

/* call game */
int game_scene(game_t *game, sys_data_t *sys);

/* error_win */
void destroy_error_screen(error_screen_t error_screen);
int init_error_screen(error_screen_t *error_screen, sfRenderWindow *win);
int update_error_screen(error_screen_t *error_screen, sfRenderWindow *win,
    time_info_t *time);

#endif /* WOLFENGINE_H */
