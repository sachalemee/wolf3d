/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapon_icon.c
*/

#include "wolfengine.h"

int init_main_weapon_icon(weapon_icon_t *weapon)
{
    weapon->ttr_main_icon = sfTexture_createFromFile(TTR_MAIN_WEAPON_ICON,
        NULL);
    if (weapon->ttr_main_icon == NULL)
        return FAILURE;
    weapon->weapon_icon_sprite = sfSprite_create();
    return SUCCESS;
}

int init_secondary_weapon_icon(weapon_icon_t *weapon)
{
    weapon->ttr_secondary_icon = sfTexture_createFromFile(TTR_SCND_WEAPON_ICON,
        NULL);
    if (weapon->ttr_secondary_icon == NULL)
        return FAILURE;
    return SUCCESS;
}

int init_leg_weapon_icon(weapon_icon_t *weapon)
{
    weapon->ttr_leg_icon = sfTexture_createFromFile(TTR_LEG_WEAPON_ICON,
        NULL);
    if (weapon->ttr_leg_icon == NULL)
        return FAILURE;
    return SUCCESS;
}

int init_icemaker_weapon_icon(weapon_icon_t *weapon)
{
    weapon->ttr_icemaker_icon = sfTexture_createFromFile(TTR_ICEMK_WEAPON_ICON,
        NULL);
    if (weapon->ttr_icemaker_icon == NULL)
        return FAILURE;
    return SUCCESS;
}
