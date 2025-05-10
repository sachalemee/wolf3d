/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_weapon.c
*/

#include "wolfengine.h"

static void procceed_shooting_anim(time_info_t *time,
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

static void set_weapon_sound(weapon_t *weapon,
    size_t current_weapon)
{
    if (current_weapon == 0) {
        sfMusic_play(weapon->main_weapon_shoot_sound);
        sfMusic_setPitch(weapon->main_weapon_shoot_sound, 1);
    }
    if (current_weapon == 1) {
        sfMusic_play(weapon->main_weapon_shoot_sound);
        sfMusic_setPitch(weapon->main_weapon_shoot_sound, 2);
    }
    if (current_weapon == 2)
    sfMusic_play(weapon->leg_weapon_shoot_sound);
}

static void weapon_shooting(time_info_t *time,
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

static void change_weapon(weapon_t *weapon, size_t *current_weapon)
{
    if (sfKeyboard_isKeyPressed(sfKeyK)) {
        *current_weapon = 0;
        weapon->max_frame = MAIN_WEAPON_MAX_FRAME - 1;
        set_primary_weapon(weapon);
    }
    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        *current_weapon = 1;
        weapon->max_frame = SECONDARY_WEAPON_MAX_FRAME - 1;
        set_secondary_weapon(weapon);
    }
    if (sfKeyboard_isKeyPressed(sfKeyM)) {
        *current_weapon = 2;
        weapon->max_frame = LEG_WEAPON_MAX_FRAME - 1;
        set_leg_weapon(weapon);
    }
}

static void choose_weapon(weapon_t *weapon,
    size_t current_weapon)
{
    if (current_weapon == 0)
        weapon->ttr_main_rect = (sfIntRect){
            TTR_MAIN_RECT_SIZE};
    if (current_weapon == 1)
        weapon->ttr_secondary_rect = (sfIntRect){
            TTR_SECONDARY_RECT_SIZE};
    if (current_weapon == 2)
        weapon->ttr_leg_rect = (sfIntRect){
            TTR_LEG_RECT_SIZE};
}

static void set_weapon_texture_sprite(weapon_t *weapon,
    sfSprite *current_part, size_t current_weapon, size_t current_frame)
{
    if (current_weapon == 0) {
        weapon->ttr_main_rect.left = current_frame * MAIN_WEAPON_RECT;
        sfSprite_setTextureRect(current_part, weapon->ttr_main_rect);
    }
    if (current_weapon == 1) {
        weapon->ttr_secondary_rect.left = current_frame *
            SECONDARY_WEAPON_RECT;
        sfSprite_setTextureRect(current_part, weapon->ttr_secondary_rect);
    }
    if (current_weapon == 2) {
        weapon->ttr_leg_rect.left = current_frame *
            LEG_WEAPON_RECT;
        sfSprite_setTextureRect(current_part, weapon->ttr_leg_rect);
    }
}

void draw_weapon(weapon_t *weapon, sfRenderWindow *win, time_info_t *time)
{
    static size_t current_frame = 0;
    sfSprite *current_part = weapon->weapon_sprite;
    static size_t current_weapon = 0;

    change_weapon(weapon, &current_weapon);
    choose_weapon(weapon, current_weapon);
    weapon_shooting(time, weapon, &current_frame, current_weapon);
    set_weapon_texture_sprite(weapon,
        current_part, current_weapon, current_frame);
    sfRenderWindow_drawSprite(win, current_part, NULL);
}
