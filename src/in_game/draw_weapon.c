/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_weapon.c
*/

#include "wolfengine.h"

static void procceed_shooting_anim(time_info_t *time,
    int *current_frame, double *shoot_speed, sfBool *is_shooting)
{
    *shoot_speed += (time->delta_time * MAIN_WEAPON_SPEED_FRAME);
    if (*shoot_speed >= 0.1) {
        *shoot_speed = 0.0;
        (*current_frame)++;
        if (*current_frame > 2) {
            *is_shooting = sfFalse;
            *current_frame = 0;
        }
    }
}

static void weapon_shooting(time_info_t *time,
    weapon_t *weapon, int *current_frame)
{
    static sfBool is_shooting = sfFalse;
    static double shoot_speed = 0.0;

    if (sfKeyboard_isKeyPressed(sfKeyE) && is_shooting == sfFalse) {
        is_shooting = sfTrue;
        *current_frame = 1;
        sfMusic_play(weapon->shooting_sound);
    }
    if (is_shooting == sfTrue)
        procceed_shooting_anim(time, current_frame,
            &shoot_speed, &is_shooting);
}

void draw_weapon(game_t *game, sfRenderWindow *win, time_info_t *time)
{
    static int current_frame = 0;
    sfSprite *current_part = game->weapon.spr_main;

    if (current_frame == 0)
        game->weapon.ttr_main_rect = (sfIntRect){0, 0, WEAPON_RECT, 127};
    weapon_shooting(time, &game->weapon, &current_frame);
    game->weapon.ttr_main_rect.left = current_frame * WEAPON_RECT;
    sfSprite_setTextureRect(current_part, game->weapon.ttr_main_rect);
    sfRenderWindow_drawSprite(win, current_part, NULL);
}
