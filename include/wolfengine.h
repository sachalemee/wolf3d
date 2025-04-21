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
    #define TEXTURE_OVERLAY_SPRINT "ressources/sprint-overlay.png"
    #define TEXTURE_WALL "ressources/wall_bamboo.png"

    /* color of the player */
    #define PLAYER_START_POS_X 22.0
    #define PLAYER_START_POS_Y 11.5
    #define PLAYER_MOV_SPEED 2.0
    #define PLAYER_ROTA_SPEED 3.0
    #define PLAYER_FOV 1
    #define PLAYER_BORDER_MAP 5
    #define PLAYER_SPRINT_SPEED 3

    /* wall info */
    #define WALL_HEIGHT_MULTI 0
    #define NUM_RAYS 1000

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

typedef struct hmap_s {
    sfVector2i map_pos;
} hmap_t;

typedef struct info_s {
    float d_time;
} info_t;

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
    double mov_speed;
    double rotate_speed;
    mov_t *mov;
    rays_t *rays;
    hmap_t *map;
} player_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfMusic *music;
    sfColor bg;
} game_t;

/* init */
int init_game(game_t *game);
player_t *init_player(void);
hmap_t *init_map(player_t *player);
info_t *init_info(void);

/* init function relative to a struct */
sfRenderWindow *set_window(void);

/* events */
int events(game_t *game, player_t *player, info_t *info);
sfBool is_keyboard_input(sfEvent event, sfKeyCode key);
void mov_player(player_t *player);

/* game */
int game_loop(game_t *game);
int start(void);

/* in game */
void draw_in_game(game_t *game, player_t *player);
void draw_background(game_t *game);

/* raycast */
void raycasting(game_t *game, player_t *player);

/* destroy */
void destroy_all(game_t *game);

/* error handling */
int error_handling(game_t *game, player_t *player);

/* math */
double degree_to_radian(double angle);

/* map */
int browse_map(game_t *game);

#endif /* WOLFENGINE_H */
