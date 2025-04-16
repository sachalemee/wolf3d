/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** wolfengine.h
*/

#ifndef STUMPER_H
    #define STUMPER_H

    /* sfml include */
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    /* value specific of the window */
    #define WIN_FRAME 60
    #define WIN_BITS 64
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
    #define BACKGROUND_MENU "ressources/Wolf3D_OGG/game_background/background_menu.png"

    /* color of the player */
    #define PLAYER_COLOR sfBlack
    #define PLAYER_RADIUS 2.0
    #define PLAYER_POSX (WIN_WIDTH / 2)
    #define PLAYER_POSY (WIN_HEIGHT / 2)
    #define PLAYER_SPEED 7
    #define PLAYER_QUICKSPIN 0.25
    #define PLAYER_FOV 70
    #define PLAYER_NUMRAYS WIN_WIDTH

    /* math define */
    #define PI 3.14159265358979323
    #define PLAN_VIEW 180

    /* return values */
    #define EXIT_S 0
    #define EXIT_F 84
    #define EXIT_E -1
    #define EXIT_P 1

    /* map define */
    #define IS_WALL 1
    #define IS_VOID 0

    /* buttons */
    #define NB_BUTTON 3
    #define NB_COLOR 5

typedef struct rays_s {
    sfVector2f posxy;
    sfVector2f dirxy;
    sfVector2f planexy;
} rays_t;

typedef struct mov_s {
    sfVector2f delta;
    double angle;
} mov_t;

typedef struct player_s {
    sfCircleShape *player;
    double speed;
    double radius;
    sfColor color;
    sfVector2f pos;
    mov_t *mov;
    rays_t *rays;
} player_t;

typedef struct buttons_s buttons_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfMusic *music;
    sfColor bg;
    buttons_t **buttons;
    player_t *player;
} game_t;


typedef struct set_texture_and_sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
} sprite_t;

typedef struct animated_sprite_s {
    sfIntRect rect;
    sfClock *clock_anim;
    int current_frame;
    int max_frame;
} anim_t;

typedef struct entity_s {
    sprite_t *sprite;
    anim_t *anim;
} entity_t;

/* init */
int init_menu(entity_t *entity);
int init_game(game_t *game);
sfRenderWindow *set_window(void);
player_t *init_player(player_t *player);
void init_sprite(sprite_t *sprite);

/* events */
int events_menu(game_t *game);
int events(game_t *game, player_t *player);
sfBool is_keyboard_input(sfEvent event, sfKeyCode key);
void mov_player(sfEvent event, player_t *player, game_t *game);

/* game */
int game_loop(game_t *game, entity_t *entity);
int start(void);

/* in game */
void draw_in_game(game_t *game);
void draw_background(game_t *game);

/* destroy */
void destroy_all(game_t *game);

/* error handling */
int error_handling(game_t *game, player_t *player);

/* math */
double degree_to_radian(double angle);

/* map */
int browse_map(game_t *game);

/*menu*/
int menu(game_t *game, entity_t *entity);
void animated_bg(entity_t *entity);
void draw_bg_menu(game_t *game, entity_t *entity);
void play_game(game_t *game);

#endif /* STUMPER_H */
