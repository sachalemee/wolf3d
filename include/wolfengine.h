/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** wolfengine.h
*/

#ifndef WOLFENGINE_H
    #define WOLFENGINE_H
    //      |       |
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <sys/types.h>
    //       |        |
    #include "hmap.h"
    #include "player.h"
    #include "weapon.h"
    #include "raycasting.h"
    #include "scene_menu.h"
    //       |        |
    #define WIN_FRAME 60
    #define WIN_BITS 32
    #define WIN_WIDTH 1920
    #define WIN_HEIGHT 1080
    //        |         |
    #define WIN_TITLE "wolfengine"
    //          |           |
    #define SONGS_PATH "ressources/Wolf3D_OGG/"
    //          |           |
    #define DEFAULT_RENDER_DIST 1000
    #define DEFAULT_DIFFICULTY 0.5
    //          |           |
    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84
    #define FAILURE -1
    #define SUCCESS 0

typedef struct set_texture_and_sprite_s sprite_t;

typedef struct animated_sprite_s {
    sfIntRect rect;
    int current_frame;
    int max_frame;
} anim_t;

typedef struct entity_s {
    sprite_t sprite;
    anim_t anim;
} entity_t;

typedef struct buttons_s buttons_t;
typedef struct time_info_s {
    sfClock *clock;
    float last_update;
    float delta_time;
} time_info_t;

typedef struct crosshair_s {
    sfTexture *ttr;
    sfSprite *spr;
    sfVector2f pos;
    sfVector2f scale;
} crosshair_t;

typedef struct custom_settings_s {
    crosshair_t *crosshair;
} custom_settings_t;

typedef struct player_s player_t;
typedef struct player_settings_s player_settings_t;
typedef struct player_sound_s player_sound_t;
typedef struct weapon_s weapon_t;
typedef struct menu_s menu_t;
typedef struct scene_s scene_t;

typedef struct settings_s {
    float difficulty;
    player_settings_t *player_settings;
} settings_t;

typedef struct sys_data_s {
    sfRenderWindow *window;
    bool is_running;
    scene_t scene;
    settings_t settings;
    time_info_t time;
} sys_data_t;

/* init */
int init_setting_screen(setting_screen_t *setting);
void destroy_settings(settings_t settings);
int init_settings(settings_t *settings, player_settings_t *player_settings);
int init_sys_data(sys_data_t *sys, const char *_Nullable map_path);
int init_entity(entity_t **entity);
void destroy_entity(entity_t *entity);

/* init function relative to a struct */
int init_window(sfRenderWindow **window);

/* time */
void update_time(time_info_t *time);
int main_loop(sys_data_t *sys_data);
int init_time(time_info_t *time);
void destroy_time(time_info_t time);

void close_window(sys_data_t *sys, sfEvent event);
int set_fullscreen(sys_data_t *sys, sfEvent event);

int start(const char *_Nullable map_path);
void draw_background(sfRenderWindow *win,
    sfRectangleShape *background_dsp_rect);

void destroy_sys(sys_data_t sys);

sfBool is_keyboard_input(sfEvent event, sfKeyCode key);
int events_setting(sys_data_t *sys);
void into_setting(sys_data_t *sys);

void destroy_error_screen(error_screen_t error_screen);
int init_error_screen(error_screen_t *error_screen, sfRenderWindow *win);
int update_error_screen(error_screen_t *error_screen, sfRenderWindow *win,
    time_info_t *time);

typedef int (*function_t)(game_t *game, sys_data_t *sys);

typedef struct {
    state_t state;
    function_t func;
} operator_t;

static const operator_t STATEMENT[] = {
    {STATE_GAME, &game_scene},
    {STATE_MENU, &update_menu},
    {STATE_SETTING, &update_setting},
    {0, NULL}
};

#endif /* WOLFENGINE_H */
