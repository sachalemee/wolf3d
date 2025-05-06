/*
** EPITECH PROJECT, 2025
** loading_screen.c
** File description:
** loading screen
*/
#include "wolfengine.h"

typedef struct loading_screen_s {
    sfSprite *sprites[LOADING_SCREEN_SPRITE_COUNT];
    size_t count_waypoints;
} loading_screen_t;

void destroy_loading_screen(loading_screen_t *loading_screen)
{
    for (size_t i = 0; i < LOADING_SCREEN_SPRITE_COUNT; i++)
        destroy_textured_sprite(loading_screen->sprites[i]);
}

static int load_loading_screen(loading_screen_t *loading_screen)
{
    sfTexture *textures[LOADING_SCREEN_SPRITE_COUNT] = {0};

    memset(loading_screen->sprites, 0,
        LOADING_SCREEN_SPRITE_COUNT * sizeof(sfSprite *));
    for (size_t i = 0; i < LOADING_SCREEN_SPRITE_COUNT; i++) {
        textures[i] = sfTexture_createFromFile(loading_screen_img_paths[i]);
        loading_screen->sprites[i] = sfSprite_create();
        if (loading_screen->sprites[i] == NULL && textures[i] != NULL)
            sfImage_destroy(textures[i]);
        if (loading_screen->sprites[i] != NULL)
            sfSprite_setTexture(loading_screen->sprites[i],
                textures[i], sfTrue);
        if (textures[i] == NULL || loading_screen->sprites[i] == NULL) {
            destroy_loading_sprites(loading_screen);
            return FAILURE;
        }
    }
    return SUCCESS;
}

void set_positions_loading_screen(loading_screen_t *loading_screen,
    sfRenderWindow *win)
{
    sfVector2u win_size = sfRenderWindow_getSize(win);

    sfSprite_setPosition(loading_screen->sprites[LOADING_BAR_BACKGROUND],
        (sfVector2f){win_size.x / 2, win_size.y / 2});
    sfSprite_setPosition(loading_screen->sprites[LOADING_BAR_INSIDE],
        (sfVector2f){win_size.x / 2, win_size.y / 2});
    sfSprite_setPosition(loading_screen->sprites[LOADING_BAR_FRAME],
        (sfVector2f){win_size.x / 2, win_size.y / 2});
    sfSprite_setPosition(loading_screen->sprites[COCOPALM_LOADING],
        (sfVector2f){win_size.x / 4, win_size.y * 3 / 4});
}

void draw_loading_screen(loading_screen_t *loading_screen,
    sfRenderWindow *win)
{
    sfVector2u win_size = sfRenderWindow_getSize(win);

    sfRenderWindow_clear(win, sfColor_fromRGB(20, 25, 11));
    sfRenderWindow_drawSprite(win,
        loading_screen->sprites[COCOPALM_LOADING], NULL);
    sfSprite_setPosition(loading_screen->sprites[COCOPALM_LOADING],
        (sfVector2f){win_size.x * 3 / 4, win_size.y * 3 / 4});
    sfRenderWindow_drawSprite(win,
        loading_screen->sprites[COCOPALM_LOADING], NULL);
    sfSprite_setPosition(loading_screen->sprites[COCOPALM_LOADING],
        (sfVector2f){win_size.x / 4, win_size.y * 3 / 4});
    sfRenderWindow_drawSprite(win,
        loading_screen->sprites[COCOPALM_LOADING], NULL);
    sfRenderWindow_drawSprite(win,
        loading_screen->sprites[LOADING_BAR_BACKGROUND], NULL);
    sfRenderWindow_drawSprite(win,
        loading_screen->sprites[LOADING_BAR_INSIDE], NULL);
    sfRenderWindow_drawSprite(win,
        loading_screen->sprites[LOADING_BAR_FRAME], NULL);
}

void loading_screen_waypoint(sfBool destroy, sfRenderWindow *init_win)
{
    static sfRenderWindow *win = NULL;
    static loading_screen_t *loading_screen = NULL;

    if (destroy) {
        destr
    }
    if (win == NULL || loading_screen == NULL) {
        win = init_win;
        if (init_loading_screen(&loading_screen, win) == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
}

int init_loading_screen(loading_screen_t *loading_screen, sfRenderWindow *win)
{
    load_loading_screen(loading_screen);
    set_positions_loading_screen(loading_screen);
}
