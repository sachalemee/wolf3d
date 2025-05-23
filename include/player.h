/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player.h
*/

#ifndef PLAYER_H
    #define PLAYER_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    //       |       |
    #define PLAYER_START_POS_X 22.0
    #define PLAYER_START_POS_Y 11.5
    //           |           |
    #define PLAYER_MOV_SPEED 2.0
    #define PLAYER_ROTA_SPEED 2.0
    //           |           |
    #define PLAYER_FOV 1
    //           |           |
    #define PLAYER_BORDER_MAP 5
    #define PLAYER_SPRINT_SPEED 2.5
    #define MAX_HP 183
    #define MAX_SHIELD 185
    #define SET_LIFE_MEASURE 45
    #define SIZE_HP 183, 45
    #define SIZE_SHIELD 185, 46
    //           |           |
    #define FIRST_FRAME 1
    #define SECOND_FRAME 2
    #define THIRD_FRAME 3
    #define FOURTH_FRAME 4
    //           |           |
    #define FACE_SCALE 1, 1
    #define FACE_POS 1528, 910
    #define RECT_FACE_LEFT 110
    #define CRITIC_HEALTH 4
    #define INTRECT_FACE 0, 0, RECT_FACE_LEFT, 110
    //           |           |
typedef struct player_sound_s {
    sfMusic *sound_footstep;
} player_sound_t;

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

typedef struct ray_hit_data_s {
    int wall_type;
    double walldist;
    double wall_tex_abscissa;
    int side;
} ray_hit_data_t;

typedef struct ray_s {
    sfVector2f dir;
    sfVector2f delta_dist;
    sfVector2f sidedist;
    sfVector2f origin;
    sfVector2i step;
} ray_t;


typedef struct bar_s {
    sfRectangleShape *hp_bar;
    sfRectangleShape *shield_bar;
    sfVector2f size_hp;
    sfVector2f size_shield;
} bar_t;

typedef struct player_s {
    camera_t camera;
    ray_t ray;
    player_settings_t *mov;
    sfVector2i map;
    player_sound_t *sound;
    bar_t *bar;
    size_t health;
    size_t armor;
    sfTexture *face_texure;
    sfSprite *face_sprite;
    sfIntRect rect_face;
} player_t;

typedef struct map_s map_t;
typedef struct game_s game_t;

int init_player(sfVector2f coords, player_t *dest);
void destroy_player(player_t player);

void raycasting(camera_t camera, map_t map,
    sfSprite **wall_sprites, sfRenderWindow *win);

void footstep_sound(player_sound_t *sound, sfKeyCode key);
void mov_player(player_t *player, map_t map);
int error_handling(game_t *game, player_t *player);
    //           |           |
    #define SPRINT_MAX_FRAME 5
    #define SPRINT_SPEED_FRAME 1.5
    #define SPRINT_RECT 4000 / SPRINT_MAX_FRAME
    #define TEXTURE_OVERLAY_SPRINT "ressources/Wolf3D_IMG/sprint-overlay.png"
    #define TEXTURE_SPRINT_RECT_SIZE 0, 0, SPRINT_RECT, 452
    //           |           |
typedef struct sprites_s {
    sfTexture *sprint_overlay_tex;
    sfSprite *sprint_overlay;
    sfIntRect sprint_overlay_rect;
} sprites_t;

typedef struct time_info_s time_info_t;

void draw_sprint_overlay(game_t *game, sfRenderWindow *win,
    time_info_t *time);
void set_bar(bar_t **bar, player_t *player);

#endif /* PLAYER_H */
