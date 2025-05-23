/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_weapon.c
*/

#include "wolfengine.h"

static void activate_flashlight(sfRenderWindow *win,
    sfRectangleShape *flash)
{
    if (sfKeyboard_isKeyPressed(sfKeyLControl)) {
        flash = sfRectangleShape_create();
        sfRectangleShape_setSize(flash, (sfVector2f){WIN_WIDTH, WIN_HEIGHT});
        sfRectangleShape_setPosition(flash, (sfVector2f){0, 0});
        sfRectangleShape_setFillColor(flash,
            sfColor_fromRGBA(255, 255, 255, 75));
    }
    if (flash != NULL)
        sfRenderWindow_drawRectangleShape(win, flash, NULL);
}

void procceed_shooting_anim(time_info_t *time,
    weapon_t *weapon, size_t *current_frame, sfBool *is_shooting)
{
    static double shoot_speed = 0.0;

    shoot_speed += (time->delta_time * WEAPON_SPEED_FRAME);
    if (shoot_speed >= 0.1) {
        shoot_speed = 0.0;
        (*current_frame)++;
        if (*current_frame > weapon->max_frame) {
            *is_shooting = sfFalse;
            *current_frame = 0;
        }
    }
}

void weapon_shooting(time_info_t *time,
    weapon_t *weapon, size_t *current_frame, size_t current_weapon)
{
    static sfBool is_shooting = sfFalse;

    if (sfKeyboard_isKeyPressed(sfKeyE) && is_shooting == sfFalse) {
        is_shooting = sfTrue;
        *current_frame = weapon->max_frame - 1;
        set_weapon_sound(weapon, current_weapon);
    }
    if (is_shooting == sfTrue)
        procceed_shooting_anim(time, weapon, current_frame, &is_shooting);
}

static void set_weapon_texture_sprite(weapon_t *weapon,
    sfSprite *current_part, size_t current_weapon, size_t current_frame)
{
    set_main_to_secondary(weapon,
        current_part, current_weapon, current_frame);
    set_special_leg_icemaker(weapon,
        current_part, current_weapon, current_frame);
}

void draw_weapon(weapon_t *weapon, sfRenderWindow *win, time_info_t *time)
{
    static size_t current_frame = 0;
    sfSprite *current_part = weapon->weapon_sprite;
    static size_t current_weapon = 0;
    sfRectangleShape *flash = NULL;

    change_weapon(weapon, &current_weapon);
    choose_weapon(weapon, current_weapon);
    weapon_shooting(time, weapon, &current_frame, current_weapon);
    set_weapon_texture_sprite(weapon,
        current_part, current_weapon, current_frame);
    sfRenderWindow_drawSprite(win,
        weapon->weapon_icon->weapon_icon_sprite, NULL);
    sfRenderWindow_drawSprite(win,
        weapon->weapon_ammo->weapon_ammo_sprite, NULL);
    sfRenderWindow_drawSprite(win,
        weapon->weapon_crosshair->weapon_crosshair_sprite, NULL);
    sfRenderWindow_drawSprite(win, weapon->flashlight_sprite, NULL);
    sfRenderWindow_drawSprite(win, current_part, NULL);
    activate_flashlight(win, flash);
}
