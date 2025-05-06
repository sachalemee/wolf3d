/*
** EPITECH PROJECT, 2025
** loading_screen.c
** File description:
** loading screen
*/
#include "loading_screen.h"
#include "wolfengine.h"
#include "my.h"

static void destroy_loading_screen(loading_screen_t *loading_screen)
{
    if (loading_screen == NULL)
        return;
    for (size_t i = 0; i < LOADING_SCREEN_SPRITE_COUNT; i++)
        destroy_textured_sprite(loading_screen->sprites[i]);
}

static int load_loading_screen(loading_screen_t *loading_screen)
{
    sfTexture *textures[LOADING_SCREEN_SPRITE_COUNT] = {0};

    memset(loading_screen->sprites, 0,
        LOADING_SCREEN_SPRITE_COUNT * sizeof(sfSprite *));
    for (size_t i = 0; i < LOADING_SCREEN_SPRITE_COUNT; i++) {
        textures[i] = sfTexture_createFromFile(loading_screen_img_paths[i],
            NULL);
        loading_screen->sprites[i] = sfSprite_create();
        if (loading_screen->sprites[i] == NULL && textures[i] != NULL)
            sfTexture_destroy(textures[i]);
        if (loading_screen->sprites[i] != NULL)
            sfSprite_setTexture(loading_screen->sprites[i],
                textures[i], sfTrue);
        if (textures[i] == NULL || loading_screen->sprites[i] == NULL) {
            destroy_loading_screen(loading_screen);
            return FAILURE;
        }
    }
    return SUCCESS;
}

static void set_transforms_loading_screen(loading_screen_t *ldng_scr)
{
    sfVector2f orig = {LDING_SPRITE_WIDTH / 2, LDING_SPRITE_HEIGHT / 2};
    sfFloatRect coco_rect =
        sfSprite_getGlobalBounds(ldng_scr->sprites[COCOPALM_LOADING]);

    sfSprite_setScale(ldng_scr->sprites[LOADING_BAR_BACKGROUND],
        (sfVector2f){3, 3});
    sfSprite_setScale(ldng_scr->sprites[LOADING_BAR_INSIDE],
        (sfVector2f){3, 3});
    sfSprite_setScale(ldng_scr->sprites[LOADING_BAR_FRAME],
        (sfVector2f){3, 3});
    sfSprite_setScale(ldng_scr->sprites[COCOPALM_LOADING],
        (sfVector2f){4, 4});
    sfSprite_setOrigin(ldng_scr->sprites[LOADING_BAR_BACKGROUND], orig);
    sfSprite_setOrigin(ldng_scr->sprites[LOADING_BAR_INSIDE], orig);
    sfSprite_setOrigin(ldng_scr->sprites[LOADING_BAR_FRAME], orig);
    sfSprite_setOrigin(ldng_scr->sprites[COCOPALM_LOADING],
        (sfVector2f){coco_rect.width / 2, coco_rect.height / 2});
}

static void set_positions_loading_screen(loading_screen_t *ldng_scr,
    sfRenderWindow *win)
{
    sfVector2u win_size = sfRenderWindow_getSize(win);

    sfSprite_setPosition(ldng_scr->sprites[LOADING_BAR_BACKGROUND],
        (sfVector2f){win_size.x / 2, win_size.y / 2});
    sfSprite_setPosition(ldng_scr->sprites[LOADING_BAR_INSIDE],
        (sfVector2f){win_size.x / 2, win_size.y / 2});
    sfSprite_setPosition(ldng_scr->sprites[LOADING_BAR_FRAME],
        (sfVector2f){win_size.x / 2, win_size.y / 2});
    sfSprite_setPosition(ldng_scr->sprites[COCOPALM_LOADING],
        (sfVector2f){win_size.x / 4, win_size.y * 4 / 5});
}

static void set_loading_screen(loading_screen_t *ldng_scr,
    sfRenderWindow *win)
{
    set_positions_loading_screen(ldng_scr, win);
    set_transforms_loading_screen(ldng_scr);
}

static void draw_loading_screen(loading_screen_t *loading_screen,
    sfRenderWindow *win)
{
    sfVector2u win_size = sfRenderWindow_getSize(win);
    sfSprite **sprites = loading_screen->sprites;

    sfRenderWindow_clear(win, sfColor_fromRGB(20, 25, 11));
    sfRenderWindow_drawSprite(win, sprites[COCOPALM_LOADING], NULL);
    sfSprite_setPosition(sprites[COCOPALM_LOADING],
        (sfVector2f){win_size.x * 4 / 5, win_size.y * 4 / 5});
    sfRenderWindow_drawSprite(win, sprites[COCOPALM_LOADING], NULL);
    sfSprite_setPosition(sprites[COCOPALM_LOADING],
        (sfVector2f){win_size.x / 5, win_size.y * 4 / 5});
    sfRenderWindow_drawSprite(win, sprites[COCOPALM_LOADING], NULL);
    sfRenderWindow_drawSprite(win, sprites[LOADING_BAR_BACKGROUND], NULL);
    sfRenderWindow_drawSprite(win, sprites[LOADING_BAR_INSIDE], NULL);
    sfRenderWindow_drawSprite(win, sprites[LOADING_BAR_FRAME], NULL);
    sfRenderWindow_display(win);
}

static int init_loading_screen(loading_screen_t *loading_screen,
    sfRenderWindow *win)
{
    if (load_loading_screen(loading_screen) == FAILURE)
        return FAILURE;
    set_loading_screen(loading_screen, win);
    draw_loading_screen(loading_screen, win);
    return SUCCESS;
}

static void set_loading_bar_progress(sfSprite *loading_bar,
    size_t waypoint_count)
{
    float bar_width = (LDING_BAR_WIDTH / LOADING_WAYPOINT_COUNT)
        * waypoint_count;

    sfSprite_setTextureRect(loading_bar,
        (sfIntRect){bar_width + LDING_BAR_FRAME_WIDTH, 0, bar_width,
        LDING_SPRITE_HEIGHT});
}

int loading_screen_waypoint(sfBool destroy, sfRenderWindow *init_win)
{
    static sfRenderWindow *win = NULL;
    static loading_screen_t loading_screen = {0};
    static size_t progrs_cntr = 0;

    if (destroy || progrs_cntr == LOADING_WAYPOINT_COUNT) {
        destroy_loading_screen(&loading_screen);
        return SUCCESS;
    }
    if (win == NULL) {
        win = init_win;
        if (init_loading_screen(&loading_screen, win) == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
    set_loading_bar_progress(loading_screen.sprites[LOADING_BAR_INSIDE],
        progrs_cntr);
    draw_loading_screen(&loading_screen, win);
    progrs_cntr++;
    return SUCCESS;
}
