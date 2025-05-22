/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_weapons_icons.c
*/

#include "wolfengine.h"

void set_icemaker_weapon_ammo(weapon_ammo_t *weapon_ammo)
{
    sfSprite_setTexture(weapon_ammo->weapon_ammo_sprite,
        weapon_ammo->ttr_icemaker_ammo, sfTrue);
    sfSprite_setPosition(weapon_ammo->weapon_ammo_sprite,
        (sfVector2f){ICEMAKER_WEAPON_AMMO_POS});
    sfSprite_setScale(weapon_ammo->weapon_ammo_sprite,
        (sfVector2f){ICEMAKER_WEAPON_AMMO_SCALE});
}

void set_leg_weapon_ammo(weapon_ammo_t *weapon_ammo)
{
    sfSprite_setTexture(weapon_ammo->weapon_ammo_sprite,
        weapon_ammo->ttr_leg_ammo, sfTrue);
    sfSprite_setPosition(weapon_ammo->weapon_ammo_sprite,
        (sfVector2f){LEG_WEAPON_AMMO_POS});
    sfSprite_setScale(weapon_ammo->weapon_ammo_sprite,
        (sfVector2f){LEG_WEAPON_AMMO_SCALE});
}

void set_secondary_weapon_ammo(weapon_ammo_t *weapon_ammo)
{
    sfSprite_setTexture(weapon_ammo->weapon_ammo_sprite,
        weapon_ammo->ttr_secondary_ammo, sfTrue);
    sfSprite_setPosition(weapon_ammo->weapon_ammo_sprite,
        (sfVector2f){SECONDARY_WEAPON_AMMO_POS});
    sfSprite_setScale(weapon_ammo->weapon_ammo_sprite,
        (sfVector2f){SECONDARY_WEAPON_AMMO_SCALE});
}

void set_primary_weapon_ammo(weapon_ammo_t *weapon_ammo)
{
    sfSprite_setTexture(weapon_ammo->weapon_ammo_sprite,
        weapon_ammo->ttr_main_ammo, sfTrue);
    sfSprite_setPosition(weapon_ammo->weapon_ammo_sprite,
        (sfVector2f){MAIN_WEAPON_AMMO_POS});
    sfSprite_setScale(weapon_ammo->weapon_ammo_sprite,
        (sfVector2f){MAIN_WEAPON_AMMO_SCALE});
}
