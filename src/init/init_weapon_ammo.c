/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapon_ammo_ammo.c
*/


#include "wolfengine.h"

int init_main_weapon_ammo(weapon_ammo_t *weapon)
{
    weapon->ttr_main_ammo = sfTexture_createFromFile(TTR_MAIN_WEAPON_AMMO,
        NULL);
    if (weapon->ttr_main_ammo == NULL)
        return FAILURE;
    weapon->weapon_ammo_sprite = sfSprite_create();
    return SUCCESS;
}

int init_secondary_weapon_ammo(weapon_ammo_t *weapon)
{
    weapon->ttr_secondary_ammo = sfTexture_createFromFile(TTR_SCND_WEAPON_AMMO,
        NULL);
    if (weapon->ttr_secondary_ammo == NULL)
        return FAILURE;
    return SUCCESS;
}

int init_leg_weapon_ammo(weapon_ammo_t *weapon)
{
    weapon->ttr_leg_ammo = sfTexture_createFromFile(TTR_LEG_WEAPON_AMMO,
        NULL);
    if (weapon->ttr_leg_ammo == NULL)
        return FAILURE;
    return SUCCESS;
}

int init_icemaker_weapon_ammo(weapon_ammo_t *weapon)
{
    weapon->ttr_icemaker_ammo = sfTexture_createFromFile(TTR_ICEMK_WEAPON_AMMO,
        NULL);
    if (weapon->ttr_icemaker_ammo == NULL)
        return FAILURE;
    return SUCCESS;
}
