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
    #define BACKGROUND_PATH "ressources/Wolf3D_OGG/game_background/"
    #define MUSIC_PATH_GAME SONGS_PATH"game_music/Hotline-Miami-Soundtrack.wav"
    #define MUSIC_PATH_FOOTSTEP SONGS_PATH"game_music/footstep-sand-move.wav"
    #define MUSIC_PATH_MENU SONGS_PATH"game_music/Tropical_music_bg.ogg"
    //           |           |
    #define SPRINT_MAX_FRAME 5
    #define SPRINT_SPEED_FRAME 1.5
    #define SPRINT_RECT 4000 / SPRINT_MAX_FRAME
    #define TEXTURE_SPRINT_RECT_SIZE 0, 0, SPRINT_RECT, 452
    //           |           |
    #define PATH_WOLF_RES "ressources/Wolf3D_IMG/"
    #define BG_MENU SONGS_PATH "game_background/background_menu.png"
    #define BG_SETTING "ressources/Wolf3D_OGG/game_background/bg_setting.png"
    #define FACE_PATH "ressources/sprite-sheet/faces/faces.png"
    #define CURSOR_SETTING "ressources/Wolf3D_OGG/texture/cursor_text.png"
    #define PANEL_BUTTON_TEXTURE BACKGROUND_PATH "panel_button.png"
    #define BACKGROUND_MENU_DEF 0, 0, 1791, 1000
    #define PANEL_SCALE 0.3, 0.35
    #define POS_PANEL 1260, -250
    #define BG_RECT 1791.75
    #define BG_MAX_FRAME 8
    #define BG_SPEED_FRAME 5
    //           |           |
    #define PLAYER_START_POS_X 22.0
    #define PLAYER_START_POS_Y 11.5
    #define PLAYER_MOV_SPEED 2.0
    #define PLAYER_ROTA_SPEED 2.0
    #define PLAYER_FOV 1
    #define PLAYER_BORDER_MAP 5
    #define PLAYER_SPRINT_SPEED 2.5
    #define DEFAULT_RENDER_DIST 1000
    #define DEFAULT_DIFFICULTY 0.5
    //          |           |
    #define MENU_VOL 50
    #define GAME_VOL 50
    #define FOOTSTEP_VOL 50
    #define MAIN_SEC_VOL 50
    #define LEG_VOL 50
    #define ICEMAKER_VOL 50
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

typedef struct settings_s {
    float difficulty;
    player_settings_t *player_settings;
} settings_t;

typedef struct sys_data_s {
    sfRenderWindow *window;
    sfVector2u win_dimension;
    bool is_running;
    scene_t scene;
    settings_t settings;
    time_info_t time;
} sys_data_t;

int init_setting_screen(setting_screen_t *setting);
void destroy_settings(setting_screen_t settings);
int init_settings(settings_t *settings, player_settings_t *player_settings);
int init_sys_data(sys_data_t *sys, const char *_Nullable map_path);
int init_entity(entity_t **entity);
void destroy_entity(entity_t *entity);
int init_hud(hud_t *hud);

/* init function relative to a struct */
int init_window(sfRenderWindow **window, sfVector2u win_dimension);

/* time */
void update_time(time_info_t *time);
int main_loop(sys_data_t *sys_data);
int init_time(time_info_t *time);
void destroy_time(time_info_t time);

void close_window(sys_data_t *sys, sfEvent event);
int set_fullscreen(sys_data_t *sys, sfEvent event);

int start(const char *_Nullable map_path);
void draw_background(sfRenderWindow *win,
    sfRectangleShape *background_dsp_rect, sfVector2u win_dimension);
void draw_hud(hud_t *hud, sfRenderWindow *win);

void destroy_sys(sys_data_t sys);

sfBool is_keyboard_input(sfEvent event, sfKeyCode key);
void unused_button(sys_data_t *sys);
void update_slider(setting_screen_t *setting, sys_data_t *sys);
int events_setting(sys_data_t *sys);
void return_to_menu(sys_data_t *sys);
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
