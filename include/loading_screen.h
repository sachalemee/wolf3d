/*
** EPITECH PROJECT, 2025
** loading_screen.h
** File description:
** loading screen assets
*/

#ifndef LOADING_SCREEN_H_
    #define LOADING_SCREEN_H_
    #include <SFML/Graphics.h>
    #define LOADING_IMG_PATH "ressources/Wolf3D_IMG/loading_screen/"
    #define LOADING_SCREEN_SPRITE_COUNT 4

enum loading_screen_imgs {
    LOADING_BAR_FRAME = 0,
    LOADING_BAR_BACKGROUND = 1,
    LOADING_BAR_INSIDE = 2,
    COCOPALM_LOADING = 3
};

static const char *const loading_screen_img_paths[LOADING_SCREEN_SPRITE_COUNT]
    = {
    LOADING_IMG_PATH"loading_bar_frame.png",
    LOADING_IMG_PATH"loading_bar_background.png",
    LOADING_IMG_PATH"loading_bar_inside.png",
    LOADING_IMG_PATH"cocopalm_loading.png"
};

    #define LOADING_WAYPOINT_COUNT 3
    #define LDING_BAR_FRAME_WIDTH 17
    #define LDING_SPRITE_WIDTH 363
    #define LDING_BAR_WIDTH (LDING_SPRITE_WIDTH - 2 * LDING_BAR_FRAME_WIDTH)
    #define LDING_SPRITE_HEIGHT 48

typedef struct loading_screen_s {
    sfSprite *sprites[LOADING_SCREEN_SPRITE_COUNT];
} loading_screen_t;
int loading_screen_waypoint(sfBool destroy, sfRenderWindow *init_win);

#endif /* LOADING_SCREEN_H_ */
