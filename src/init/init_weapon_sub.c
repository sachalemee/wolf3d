/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapon_sub.c
*/

#include "wolfengine.h"

static int init_flashlight(weapon_t *weapon)
{
    weapon->ttr_flashlight = sfTexture_createFromFile(RES_FLASHLIGHT, NULL);
    if (weapon->ttr_flashlight == NULL)
        return FAILURE;
    weapon->flashlight_sprite = sfSprite_create();
    set_flashlight_weapon(weapon);
    return SUCCESS;
}

static int init_main_weapon(weapon_t *weapon)
{
    weapon->ttr_main_rect = (sfIntRect){TTR_MAIN_RECT_SIZE};
    weapon->ttr_main = sfTexture_createFromFile(RES_MAIN_WEAPON, NULL);
    if (weapon->ttr_main == NULL)
        return FAILURE;
    weapon->weapon_sprite = sfSprite_create();
    set_primary_weapon(weapon);
    weapon->max_frame = MAIN_WEAPON_MAX_FRAME - 1;
    return SUCCESS;
}

static int init_secondary_weapon(weapon_t *weapon)
{
    weapon->ttr_secondary_rect = (sfIntRect){TTR_SECONDARY_RECT_SIZE};
    weapon->ttr_secondary = sfTexture_createFromFile(RES_SECONDARY_WEAPON,
        NULL);
    if (weapon->ttr_secondary == NULL)
        return FAILURE;
    return SUCCESS;
}

static int init_leg_weapon(weapon_t *weapon)
{
    weapon->ttr_leg_rect = (sfIntRect){TTR_SECONDARY_RECT_SIZE};
    weapon->ttr_leg = sfTexture_createFromFile(RES_LEG_WEAPON,
        NULL);
    if (weapon->ttr_leg == NULL)
        return FAILURE;
    return SUCCESS;
}

static int init_icemaker_weapon(weapon_t *weapon)
{
    weapon->ttr_icemaker_rect = (sfIntRect){TTR_ICEMAKER_RECT_SIZE};
    weapon->ttr_icemaker = sfTexture_createFromFile(RES_ICEMAKER_WEAPON,
        NULL);
    if (weapon->ttr_icemaker == NULL)
        return FAILURE;
    return SUCCESS;
}

int init_each_weapon(weapon_t *weapon)
{
    if (init_main_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_secondary_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_leg_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_icemaker_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_flashlight(weapon) == FAILURE)
        return FAILURE;
    return EXIT_SUCCESS;
}

int init_each_weapon_icon(weapon_icon_t *weapon_icon)
{
    if (init_main_weapon_icon(weapon_icon) == FAILURE)
        return FAILURE;
    if (init_secondary_weapon_icon(weapon_icon) == FAILURE)
        return FAILURE;
    if (init_leg_weapon_icon(weapon_icon) == FAILURE)
        return FAILURE;
    if (init_icemaker_weapon_icon(weapon_icon) == FAILURE)
        return FAILURE;
    return EXIT_SUCCESS;
}

int init_each_weapon_ammo(weapon_ammo_t *weapon_ammo)
{
    if (init_main_weapon_ammo(weapon_ammo) == FAILURE)
        return FAILURE;
    if (init_secondary_weapon_ammo(weapon_ammo) == FAILURE)
        return FAILURE;
    if (init_leg_weapon_ammo(weapon_ammo) == FAILURE)
        return FAILURE;
    if (init_icemaker_weapon_ammo(weapon_ammo) == FAILURE)
        return FAILURE;
    return EXIT_SUCCESS;
}

int init_each_weapon_crosshair(weapon_crosshair_t *weapon_crosshair)
{
    if (init_main_weapon_crosshair(weapon_crosshair) == FAILURE)
        return FAILURE;
    if (init_secondary_weapon_crosshair(weapon_crosshair) == FAILURE)
        return FAILURE;
    if (init_leg_weapon_crosshair(weapon_crosshair) == FAILURE)
        return FAILURE;
    if (init_icemaker_weapon_crosshair(weapon_crosshair) == FAILURE)
        return FAILURE;
    return EXIT_SUCCESS;
}
