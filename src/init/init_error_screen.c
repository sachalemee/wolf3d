/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** init_entity
*/

#include "wolfengine.h"
#include <stdio.h>

void destroy_error_screen(error_screen_t error_screen)
{
    if (error_screen.error_screen_background != NULL)
        sfSprite_destroy(error_screen.error_screen_background);
    if (error_screen.no_tex != NULL)
        sfTexture_destroy(error_screen.no_tex);
}

int init_error_screen(error_screen_t *error_screen, sfRenderWindow *win)
{
    sfVector2u tex_size = {0};
    sfVector2u win_size = {0};

    error_screen->no_tex = sfTexture_createFromFile(MORSHU_TEXTURE, sfFalse);
    error_screen->error_screen_background = sfSprite_create();
    if (error_screen->no_tex == NULL
        || error_screen->error_screen_background == NULL) {
        destroy_error_screen(*error_screen);
        return FAILURE;
    }
    sfSprite_setTexture(error_screen->error_screen_background,
        error_screen->no_tex, sfTrue);
    tex_size = sfTexture_getSize(error_screen->no_tex);
    sfSprite_setTextureRect(error_screen->error_screen_background,
        (sfIntRect){0, 0, tex_size.x, MORSHU_HEIGHT});
    error_screen->frame_count = MORSHU_FRAME_COUNT;
    win_size = sfRenderWindow_getSize(win);
    sfSprite_setScale(error_screen->error_screen_background, (sfVector2f){
        (float)win_size.x / tex_size.x, (float)win_size.y / MORSHU_HEIGHT});
    return SUCCESS;
}

int update_error_screen(error_screen_t *error_screen, sfRenderWindow *win,
    time_info_t *time)
{
    sfEvent event = {0};
    sfIntRect disp_rect = {0};

    sfRenderWindow_clear(win, sfBlack);
    disp_rect = sfSprite_getTextureRect(error_screen->error_screen_background);
    error_screen->frame_index = (int)(time->last_update * MORSHU_SPEED)
        % error_screen->frame_count;
    disp_rect.top = disp_rect.height * error_screen->frame_index;
    sfSprite_setTextureRect(error_screen->error_screen_background, disp_rect);
    sfRenderWindow_drawSprite(win, error_screen->error_screen_background,
        NULL);
    sfRenderWindow_pollEvent(win, &event);
    sfRenderWindow_display(win);
    return SUCCESS;
}
