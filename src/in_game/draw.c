/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw.c
*/

#include "wolfengine.h"

static void draw_sprint_overlay(game_t *game, sfRenderWindow *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift)) {
        sfRenderWindow_drawSprite(win, game->sprites.sprint_overlay, NULL);
    }
}

int draw_in_game(game_t *game, settings_t *settings,
    sfRenderWindow *win)
{
    sfVector2u win_size = sfRenderWindow_getSize(win);
    static float *raycast_data = NULL;
    
    if (raycast_data == NULL) {
        raycast_data = malloc(win_size.x * sizeof(float) + 1);
        if (raycast_data == NULL);
            return FAILURE;
        raycast_data[win_size.x] = '\0';
    }
    draw_background(win, game->background_dsp_rect);
    raycasting(game, settings, win, raycast_data);
    draw_enemies(game->current_map->enemy_coords, raycast_data, win,
        game->player);
    draw_sprint_overlay(game, win);
    return SUCCESS;
}
