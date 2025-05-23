/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** change_weapon_actions.c
*/

#include "wolfengine.h"

void set_weapon_sound(weapon_t *weapon,
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
    if (current_weapon == 3)
        sfMusic_play(weapon->icemaker_weapon_shoot_sound);
}

static void main_to_secondary(weapon_t *weapon,
    size_t *current_weapon)
{
    if (sfKeyboard_isKeyPressed(sfKeyK)) {
        *current_weapon = 0;
        weapon->max_frame = MAIN_WEAPON_MAX_FRAME - 1;
        set_primary_weapon(weapon);
        set_primary_weapon_icon(weapon->weapon_icon);
        set_primary_weapon_ammo(weapon->weapon_ammo);
        set_primary_weapon_crosshair(weapon->weapon_crosshair,
            weapon->win_dimension);
    }
    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        *current_weapon = 1;
        weapon->max_frame = SECONDARY_WEAPON_MAX_FRAME - 1;
        set_secondary_weapon(weapon);
        set_secondary_weapon_icon(weapon->weapon_icon);
        set_secondary_weapon_ammo(weapon->weapon_ammo);
        set_secondary_weapon_crosshair(weapon->weapon_crosshair,
            weapon->win_dimension);
    }
}

static void special_leg_to_icemaker(weapon_t *weapon,
    size_t *current_weapon)
{
    if (sfKeyboard_isKeyPressed(sfKeyM)) {
        *current_weapon = 2;
        weapon->max_frame = LEG_WEAPON_MAX_FRAME - 1;
        set_leg_weapon(weapon);
        set_leg_weapon_icon(weapon->weapon_icon);
        set_leg_weapon_ammo(weapon->weapon_ammo);
        set_leg_weapon_crosshair(weapon->weapon_crosshair,
            weapon->win_dimension);
    }
    if (sfKeyboard_isKeyPressed(sfKeyO)) {
        *current_weapon = 3;
        weapon->max_frame = ICEMAKER_WEAPON_MAX_FRAME - 1;
        set_icemaker_weapon(weapon);
        set_icemaker_weapon_icon(weapon->weapon_icon);
        set_icemaker_weapon_ammo(weapon->weapon_ammo);
        set_icemaker_weapon_crosshair(weapon->weapon_crosshair,
            weapon->win_dimension);
    }
}

void change_weapon(weapon_t *weapon, size_t *current_weapon)
{
    main_to_secondary(weapon, current_weapon);
    special_leg_to_icemaker(weapon, current_weapon);
}

void choose_weapon(weapon_t *weapon,
    size_t current_weapon)
{
    if (current_weapon == 0) {
        weapon->ttr_main_rect = (sfIntRect){
            TTR_MAIN_RECT_SIZE};
        set_primary_weapon_icon(weapon->weapon_icon);
        set_primary_weapon_ammo(weapon->weapon_ammo);
        set_primary_weapon_crosshair(weapon->weapon_crosshair,
            weapon->win_dimension);
        }
    if (current_weapon == 1)
        weapon->ttr_secondary_rect = (sfIntRect){
            TTR_SECONDARY_RECT_SIZE};
    if (current_weapon == 2)
        weapon->ttr_leg_rect = (sfIntRect){
            TTR_LEG_RECT_SIZE};
    if (current_weapon == 3)
        weapon->ttr_icemaker_rect = (sfIntRect){
            TTR_ICEMAKER_RECT_SIZE};
}

void set_main_to_secondary(weapon_t *weapon,
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
}

void set_special_leg_icemaker(weapon_t *weapon,
    sfSprite *current_part, size_t current_weapon, size_t current_frame)
{
    if (current_weapon == 2) {
        weapon->ttr_leg_rect.left = current_frame *
            LEG_WEAPON_RECT;
        sfSprite_setTextureRect(current_part, weapon->ttr_leg_rect);
    }
    if (current_weapon == 3) {
        weapon->ttr_icemaker_rect.left = current_frame *
            ICEMAKER_WEAPON_RECT;
        sfSprite_setTextureRect(current_part, weapon->ttr_icemaker_rect);
    }
}
