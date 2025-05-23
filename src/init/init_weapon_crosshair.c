/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapon_crosshair.c
*/

#include "wolfengine.h"

int init_main_weapon_crosshair(weapon_crosshair_t *weapon)
{
    weapon->ttr_main_crosshair = sfTexture_createFromFile(
        TTR_MAIN_WEAPON_CROSSHAIR, NULL);
    if (weapon->ttr_main_crosshair == NULL)
        return FAILURE;
    weapon->weapon_crosshair_sprite = sfSprite_create();
    return SUCCESS;
}

int init_secondary_weapon_crosshair(weapon_crosshair_t *weapon)
{
    weapon->ttr_secondary_crosshair = sfTexture_createFromFile(
        TTR_SCND_WEAPON_CROSSHAIR, NULL);
    if (weapon->ttr_secondary_crosshair == NULL)
        return FAILURE;
    return SUCCESS;
}

int init_leg_weapon_crosshair(weapon_crosshair_t *weapon)
{
    weapon->ttr_leg_crosshair = sfTexture_createFromFile(
        TTR_LEG_WEAPON_CROSSHAIR, NULL);
    if (weapon->ttr_leg_crosshair == NULL)
        return FAILURE;
    return SUCCESS;
}

int init_icemaker_weapon_crosshair(weapon_crosshair_t *weapon)
{
    weapon->ttr_icemaker_crosshair = sfTexture_createFromFile(
        TTR_ICEMK_WEAPON_CROSSHAIR, NULL);
    if (weapon->ttr_icemaker_crosshair == NULL)
        return FAILURE;
    return SUCCESS;
}
