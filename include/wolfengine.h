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
    #define RESSOURCES_SPRITE "ressources/sprite-sheet/"
    #define PLAY_BUTTON_PATH RESSOURCES_SPRITE"buttons/play_button.png"
    #define SETTING_BUTTON_PATH RESSOURCES_SPRITE"buttons/setting_button.png"
    #define EXIT_BUTTON_PATH RESSOURCES_SPRITE"buttons/exit_button.png"
    #define WEAPON_RESSOURCES RESSOURCES_SPRITE"weapon/"
    #define SONGS_PATH "ressources/Wolf3D_OGG/"
    #define MUSIC_PATH_GAME SONGS_PATH"game_music/Hotline-Miami-Soundtrack.wav"
    #define MUSIC_PATH_FOOTSTEP SONGS_PATH"game_music/footstep-sand-move.wav"
    #define MUSIC_PATH_MENU SONGS_PATH"game_music/Tropical_music_bg.ogg"
    //           |           |
    #define SPRINT_MAX_FRAME 5
    #define SPRINT_SPEED_FRAME 1.5
    #define SPRINT_RECT 4000 / SPRINT_MAX_FRAME
    #define TEXTURE_OVERLAY_SPRINT "ressources/Wolf3D_IMG/sprint-overlay.png"
    #define TEXTURE_SPRINT_RECT_SIZE 0, 0, SPRINT_RECT, 452
    //           |           |
    #define TEXTURE_WALL "ressources/Wolf3D_IMG/wall_bamboo.png"
    #define BG_MENU SONGS_PATH "game_background/background_menu.png"
    #define BG_SETTING "ressources/Wolf3D_OGG/game_background/bg_setting.png"
    #define BACKGROUND_MENU_DEF 0, 0, 1791, 1000
    #define BG_RECT 1791.75
    #define BG_MAX_FRAME 8
    #define BG_SPEED_FRAME 5

    /* weapon sprite sheet */
    #define TTR_MAIN_WEAPON "main-weapon-sprite.png"
    #define TTR_SECONDARY_WEAPON "secondary-weapon-sprite.png"
    #define TTR_LEG_WEAPON "legs-sprite.png"
    //           |           |
    #define WATER_SONG_SHOOT WEAPON_RESSOURCES"water-shot-trimmer.wav"
    #define FART_SONG_SHOOT WEAPON_RESSOURCES"fart-sound.ogg"
    //           |           |
    #define RES_MAIN_WEAPON WEAPON_RESSOURCES TTR_MAIN_WEAPON
    #define RES_SECONDARY_WEAPON WEAPON_RESSOURCES TTR_SECONDARY_WEAPON
    #define RES_LEG_WEAPON WEAPON_RESSOURCES TTR_LEG_WEAPON
    //           |           |
    #define MAIN_WEAPON_MAX_FRAME 3
    #define SECONDARY_WEAPON_MAX_FRAME 2
    #define LEG_WEAPON_MAX_FRAME 2
    //           |           |
    #define MAIN_WEAPON_RECT 275 / MAIN_WEAPON_MAX_FRAME
    #define SECONDARY_WEAPON_RECT 318 / SECONDARY_WEAPON_MAX_FRAME
    #define LEG_WEAPON_RECT 315 / LEG_WEAPON_MAX_FRAME
    //           |           |
    #define TTR_MAIN_RECT_SIZE 0, 0, MAIN_WEAPON_RECT, 127
    #define TTR_SECONDARY_RECT_SIZE 0, 0, SECONDARY_WEAPON_RECT, 148
    #define TTR_LEG_RECT_SIZE 0, 0, LEG_WEAPON_RECT, 146
    //           |           |
    #define WEAPON_SPEED_FRAME 1.0
    //           |           |
    #define WIN_WEAPON_POS 325
    #define WIN_LEG_POS 200
    #define WEAPON_POS_PADDING 8
    /* ------------------- */

    /* color of the player */
    #define PLAYER_START_POS_X 22.0
    #define PLAYER_START_POS_Y 11.5
    #define PLAYER_MOV_SPEED 2.0
    #define PLAYER_ROTA_SPEED 2.0
    #define PLAYER_FOV 1
    #define PLAYER_BORDER_MAP 5
    #define PLAYER_SPRINT_SPEED 2.5
    #define DEFAULT_RENDER_DIST 1000
    #define DEFAULT_DIFFICULTY 0.5

    /* wall info */
    // #define WALL_HEIGHT_MULTI 0
    #define ROOF_RGB 90, 231, 223
    #define FLOOR_RGB 223, 231, 90
    #define END_SIZE 2.5

    /* return values */
    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84
    #define EXIT_E -1
    #define EXIT_P 1
    #define FAILURE -1
    #define SUCCESS 0

    /* vector calculations */
enum vector_step {
    POSITIVE_STEP = 1,
    NEGATIVE_STEP = -1
};
enum ray_hit_type {
    VERTICAL_WALL = 0,
    HORIZONTAL_WALL = 1
};

typedef struct ray_s {
    sfVector2f dir;
    sfVector2f delta_dist;
    sfVector2f sidedist;
    sfVector2f origin;
    sfVector2i step;
} ray_t;

typedef struct ray_hit_data_s {
    int wall_type;
    double walldist;
    double wall_tex_abscissa;
    int side;
} ray_hit_data_t;


typedef struct player_settings_s {
    double mov_speed;
    double rotate_speed;
    size_t *render_dist;
} player_settings_t;

typedef struct camera_s {
    sfVector2f dir;
    sfVector2f plane;
    sfVector2f pos;
    size_t *render_dist;
} camera_t;

typedef struct player_sound_s {
    sfMusic *sound_footstep;
} player_sound_t;

typedef struct player_s {
    camera_t camera;
    ray_t ray;
    player_settings_t *mov;
    sfVector2i map;
    player_sound_t *sound;
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
    STATE_GAME,
    STATE_SETTING
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
    sfIntRect sprint_overlay_rect;
} sprites_t;

typedef struct musics_s {
    sfMusic *menu_music;
    sfMusic *game_music;
} musics_t;

typedef struct crosshair_s {
    sfTexture *ttr;
    sfSprite *spr;
    sfVector2f pos;
    sfVector2f scale;
} crosshair_t;

typedef struct custom_settings_s {
    crosshair_t *crosshair;
} custom_settings_t;

typedef struct menu_s {
    buttons_t **buttons;
    entity_t *entity;
    custom_settings_t *custom_set;
} menu_t;

typedef struct setting_screen_s {
    sfTexture *setting_texture;
    sfSprite *setting_sprite;
    buttons_t **buttons;
} setting_screen_t;

typedef struct weapon_s {
    sfTexture *ttr_main;
    sfTexture *ttr_secondary;
    sfTexture *ttr_leg;
    sfIntRect ttr_main_rect;
    sfIntRect ttr_secondary_rect;
    sfIntRect ttr_leg_rect;
    sfSprite *weapon_sprite;
    sfMusic *main_weapon_shoot_sound;
    sfMusic *leg_weapon_shoot_sound;
    size_t max_frame;
} weapon_t;

typedef struct game_s {
    sfSprite **wall_sprites;
    sfRectangleShape *background_dsp_rect;
    sprites_t sprites;
    ssize_t level;
    map_t *current_map;
    player_t player;
    weapon_t weapon;
    float *raycast_data;
} game_t;

typedef struct settings_s {
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
    setting_screen_t setting_screen;
} scene_t;

// int scene; corresponds to the above enum (user location)
typedef struct sys_data_s {
    sfRenderWindow *window;
    bool is_running;
    scene_t scene;
    settings_t settings;
    time_info_t time;
} sys_data_t;

/* wall textures */
    #define WALL_TEXTURES_PATH "ressources/Wolf3D_IMG/wall_textures/"

// wall types are in the same order as wall textures (with an offset of 1
// because air has no texture)
enum wall_types {
    AIR = 0,
    SIMPLE_WALL = 1,
    SPECIAL_WALL = 2,
    WALL_1 = 3,
    WALL_2 = 4,
    WALL_3 = 5,
    WALL_4 = 6,
    WALL_5 = 7,
    WALL_6 = 8,
    WALL_7 = 9
};
static char const *const wall_textures[] = {
    "wall_bamboo.png",
    "joff.png",
    "wall_bamboo.png",
    "wall_bamboo.png",
    "wall_bamboo.png",
    "wall_bamboo.png",
    "wall_bamboo.png",
    "wall_bamboo.png",
    "wall_bamboo.png",
    NULL
};

/* init */
void destroy_menu(menu_t menu);
int init_setting_screen(setting_screen_t *setting);
int init_menu(menu_t *menu);
void destroy_settings(settings_t settings);
int init_settings(settings_t *settings, player_settings_t *player_settings);
void close_menu(sys_data_t *sys);
void destroy_game(game_t game);
int init_game(game_t *game, const char *_Nullable map_path,
    sfRenderWindow *win);
int init_sys_data(sys_data_t *sys, const char *_Nullable map_path);
void destroy_player(player_t player);
void destroy_weapon(weapon_t weapon);
int init_player(sfVector2f coords, player_t *dest);
int init_scene(scene_t *scene, const char *_Nullable map_path,
    sfRenderWindow *win);
void destroy_scene(scene_t scene);
int init_musics(musics_t *musics);
void destroy_musics(musics_t musics);
int init_entity(entity_t **entity);
void destroy_entity(entity_t *entity);
int init_weapon(weapon_t *weapon);
// void init_map(player_t *player);

/* init function relative to a struct */
int init_window(sfRenderWindow **window);
int init_wall_sprites(sfSprite ***wall_sprites);
void destroy_wall_sprites(sfSprite **wall_sprites);

/* time */
void update_time(time_info_t *time);
int main_loop(sys_data_t *sys_data);
int init_time(time_info_t *time);
void destroy_time(time_info_t time);

/* events */
int game_events(sys_data_t *sys);
void close_window(sys_data_t *sys, sfEvent event);
int set_fullscreen(sys_data_t *sys, sfEvent event);
void footstep_sound(player_sound_t *sound, sfKeyCode key);
void mov_player(player_t *player, map_t map);

/* game */
int start(const char *_Nullable map_path);

/* in game */
void draw_in_game(sys_data_t *sys_data, game_t *game, map_t map);
void draw_background(sfRenderWindow *win,
    sfRectangleShape *background_dsp_rect);
void draw_weapon(weapon_t *weapon, sfRenderWindow *win, time_info_t *time);
void draw_sprint_overlay(game_t *game, sfRenderWindow *win,
    time_info_t *time);
void set_secondary_weapon(weapon_t *weapon);
void set_primary_weapon(weapon_t *weapon);
void set_leg_weapon(weapon_t *weapon);

/* raycast */
void raycasting(camera_t camera, map_t map,
    sfSprite **wall_sprites, sfRenderWindow *win);

/* destroy */
void destroy_sys(sys_data_t sys);
// void destroy_all(game_t *game);

/* error handling */
int error_handling(game_t *game, player_t *player);

/* hud */
int draw_hud_overlay(game_t *game, player_t *player);

/* EVENTS */
sfBool is_keyboard_input(sfEvent event, sfKeyCode key);

/* call menu */
    #define MENU_SCALE 1.25, 1.2
int update_menu(game_t *game, sys_data_t *sys);
int events_menu(sys_data_t *sys);
void animated_bg(entity_t *entity, time_info_t *time);
void draw_bg_menu(menu_t *menu, sfRenderWindow *win);
void play_game(sys_data_t *sys);

/* call setting */
int update_setting(game_t *game, sys_data_t *sys);
int events_setting(sys_data_t *sys);
void into_setting(sys_data_t *sys);

/* call game */
int game_scene(game_t *game, sys_data_t *sys);

/* error_win */
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
