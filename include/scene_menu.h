/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** scene_menu.h
*/
#ifndef SCENE_MENU_H
    #define SCENE_MENU_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <sys/types.h>
    //       |       |
    #include "buttons.h"
    //       |       |
    #define SONGS_PATH "ressources/Wolf3D_OGG/"
    //           |           |
    #define MUSIC_PATH_MENU SONGS_PATH"game_music/Tropical_music_bg.ogg"
    #define BG_MENU SONGS_PATH "game_background/background_menu.png"
    //           |           |
    #define BACKGROUND_MENU_DEF 0, 0, 1791, 1000
    //           |           |
    #define DEFAULT_SCENE STATE_MENU
    //           |           |
    #define MENU_SCALE 1.25, 1.2
    //           |           |
    #define DEFAULT_SCENE STATE_MENU
    #define MUSIC_MAX 100.0
    #define MUSIC_MIN 0.0
    #define MUSIC_GAP 5.0
    //           |           |
    #define ROOF_RGB 59, 168, 205
    #define FLOOR_RGB 223, 231, 90
    #define END_SIZE 2.5
    //           |           |
    #define RSC_PATH "ressources/"
    #define BTN_PATH "buttons/"
    #define SHEESPRI_PATH "sprite-sheet/"
    #define RESSOURCES_SPRITE RSC_PATH"sprite-sheet/"
    #define PLAY_BUTTON_PATH RESSOURCES_SPRITE BTN_PATH"play_button.png"
    #define SETTING_BUTTON_PATH RESSOURCES_SPRITE BTN_PATH"setting_button.png"
    #define EXIT_BUTTON_PATH RESSOURCES_SPRITE BTN_PATH"exit_button.png"
    #define HUD_PATH RSC_PATH"Wolf3D_OGG/hud/HUD.png"
    //           |           |
    #define SOUND_BUTTON RSC_PATH SHEESPRI_PATH BTN_PATH"sound_button.png"
    #define FOV_BUTTON RSC_PATH SHEESPRI_PATH BTN_PATH"fov_button.png"
    #define DFTY_BUTTON RSC_PATH SHEESPRI_PATH BTN_PATH"difficulty_button.png"
    #define TO_MENU_BUTTON RSC_PATH SHEESPRI_PATH BTN_PATH"to_menu_button.png"
    #define MUSIC_PATH_GAME SONGS_PATH"game_music/Hotline-Miami-Soundtrack.wav"
    #define MUSIC_PATH_FOOTSTEP SONGS_PATH"game_music/footstep-sand-move.wav"
    //           |           |
    #define MORSHU_FRAME_COUNT 32
    #define MORSHU_HEIGHT 281
    #define MORSHU_SPEED 42
    #define MORSHU_TEXTURE "ressources/Wolf3D_IMG/morshu_dance_anim_sprite.png"

typedef struct buttons_s buttons_t;
typedef struct entity_s entity_t;
typedef struct custom_settings_s custom_settings_t;
typedef struct sys_data_s sys_data_t;
typedef struct musics_s musics_t;

typedef struct ground_sky_s {
    sfRectangleShape *background_dsp_rect;
    sfSprite *ground_sprite;
    sfTexture *sky_texure;
    sfSprite *sky_sprite;
} ground_sky_t;

typedef struct hud_s {
    sfSprite *hud_sprite;
    sfTexture *hud_texture;
} hud_t;

typedef struct game_s {
    sfSprite **wall_sprites;
    ground_sky_t *ground_sky;
    sprites_t sprites;
    ssize_t level;
    map_t *current_map;
    player_t player;
    weapon_t weapon;
    hud_t hud;
    float *raycast_data;
} game_t;

typedef struct game_s game_t;
typedef struct time_info_s time_info_t;

typedef struct menu_s {
    buttons_t **buttons;
    entity_t *entity;
    custom_settings_t *custom_set;
    sfSprite *panel_sprite;
    sfTexture *panel_text;
} menu_t;

int init_menu(menu_t *menu);
void destroy_menu(menu_t menu);
void close_menu(sys_data_t *sys);
int update_menu(game_t *game, sys_data_t *sys);
int events_menu(sys_data_t *sys);
void draw_bg_menu(menu_t *menu, sfRenderWindow *win);

typedef struct set_texture_and_sprite_s {
    sfTexture *texture_bg;
    sfSprite *sprite_bg;
} sprite_t;

typedef enum state_s {
    STATE_MENU,
    STATE_GAME,
    STATE_SETTING
} state_t;

typedef struct error_screen_s {
    size_t frame_index;
    size_t frame_count;
    sfTexture *no_tex;
    sfSprite *error_screen_background;
} error_screen_t;

typedef struct setting_screen_s {
    sfTexture *setting_texture;
    sfSprite *setting_sprite;
    sfTexture* slider_texture;
    sfCircleShape* slider_cursor;
    int isDragging;
    buttons_t **buttons;
} setting_screen_t;

typedef struct musics_s {
    sfMusic *menu_music;
    sfMusic *game_music;
} musics_t;

typedef struct scene_s {
    error_screen_t error_scene;
    menu_t menu;
    game_t game;
    state_t state;
    musics_t musics;
    setting_screen_t setting_screen;
} scene_t;

int init_scene(scene_t *scene, const char *_Nullable map_path,
    sfRenderWindow *win);
void destroy_scene(scene_t scene);

int init_musics(musics_t *musics);
void destroy_musics(musics_t musics);

    #define BG_SETTING "ressources/Wolf3D_OGG/game_background/bg_setting.png"
    #define BG_RECT 1791.75
    #define BG_MAX_FRAME 8
    #define BG_SPEED_FRAME 5

void animated_bg(entity_t *entity, time_info_t *time);

int game_events(sys_data_t *sys);
void draw_in_game(sys_data_t *sys_data, game_t *game, map_t map);
void play_game(sys_data_t *sys);
int update_setting(game_t *game, sys_data_t *sys);
int game_scene(game_t *game, sys_data_t *sys);

void destroy_game(game_t game);
int init_game(game_t *game, const char *_Nullable map_path,
    sfRenderWindow *win);

#endif /* SCENE_MENU_H */
