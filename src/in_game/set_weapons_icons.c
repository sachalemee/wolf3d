/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_weapons_icons.c
*/

#include "wolfengine.h"

void set_icemaker_weapon_icon(weapon_icon_t *weapon_icon)
{
    sfSprite_setTexture(weapon_icon->weapon_icon_sprite,
        weapon_icon->ttr_icemaker_icon, sfTrue);
    sfSprite_setPosition(weapon_icon->weapon_icon_sprite,
        (sfVector2f){ICEMAKER_WEAPON_ICON_POS});
    sfSprite_setScale(weapon_icon->weapon_icon_sprite,
        (sfVector2f){ICEMAKER_WEAPON_ICON_SCALE});
}

void set_leg_weapon_icon(weapon_icon_t *weapon_icon)
{
    sfSprite_setTexture(weapon_icon->weapon_icon_sprite,
        weapon_icon->ttr_leg_icon, sfTrue);
    sfSprite_setPosition(weapon_icon->weapon_icon_sprite,
        (sfVector2f){LEG_WEAPON_ICON_POS});
    sfSprite_setScale(weapon_icon->weapon_icon_sprite,
        (sfVector2f){LEG_WEAPON_ICON_SCALE});
}

void set_secondary_weapon_icon(weapon_icon_t *weapon_icon)
{
    sfSprite_setTexture(weapon_icon->weapon_icon_sprite,
        weapon_icon->ttr_secondary_icon, sfTrue);
    sfSprite_setPosition(weapon_icon->weapon_icon_sprite,
        (sfVector2f){SECONDARY_WEAPON_ICON_POS});
    sfSprite_setScale(weapon_icon->weapon_icon_sprite,
        (sfVector2f){SECONDARY_WEAPON_ICON_SCALE});
}

void set_primary_weapon_icon(weapon_icon_t *weapon_icon)
{
    sfSprite_setTexture(weapon_icon->weapon_icon_sprite,
        weapon_icon->ttr_main_icon, sfTrue);
    sfSprite_setPosition(weapon_icon->weapon_icon_sprite,
        (sfVector2f){MAIN_WEAPON_ICON_POS});
    sfSprite_setScale(weapon_icon->weapon_icon_sprite,
        (sfVector2f){MAIN_WEAPON_ICON_SCALE});
}
