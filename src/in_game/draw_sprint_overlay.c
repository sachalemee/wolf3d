/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_sprint_overlay.c
*/

#include "wolfengine.h"

static void set_frame_speed(time_info_t *time, size_t *current_frame)
{
    static double shoot_speed = 0.0;

    shoot_speed += (time->delta_time * SPRINT_SPEED_FRAME);
    if (shoot_speed >= 0.1) {
        shoot_speed = 0.0;
        (*current_frame)++;
    }
}

static void set_frame_to_display(game_t *game,
    sfBool *is_sprinting, sfSprite *current_part, size_t *current_frame)
{
    game->sprites.sprint_overlay_rect.left = (*current_frame * SPRINT_RECT);
    sfSprite_setTextureRect(current_part, game->sprites.sprint_overlay_rect);
    if (*current_frame > SPRINT_MAX_FRAME - 1) {
        *is_sprinting = sfFalse;
        *current_frame = 0;
    }
}

void draw_sprint_overlay(game_t *game, sfRenderWindow *win, time_info_t *time)
{
    static size_t current_frame = 0;
    sfSprite *current_part = game->sprites.sprint_overlay;
    static sfBool is_sprinting = sfFalse;

    game->sprites.sprint_overlay_rect = (sfIntRect){TEXTURE_SPRINT_RECT_SIZE};
    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift)) {
        is_sprinting = sfTrue;
        if (is_sprinting == sfTrue) {
            set_frame_speed(time, &current_frame);
            set_frame_to_display(game, &is_sprinting,
                current_part, &current_frame);
            sfRenderWindow_drawSprite(win, current_part, NULL);
        }
    }
}
