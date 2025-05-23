/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_weapons_crosshair.c
*/

#include "wolfengine.h"

void set_icemaker_weapon_crosshair(weapon_crosshair_t *weapon_crosshair,
    sfVector2u position)
{
    sfVector2u ttr_icemaker_size = {0};

    sfSprite_setTexture(weapon_crosshair->weapon_crosshair_sprite,
        weapon_crosshair->ttr_icemaker_crosshair, sfTrue);
    ttr_icemaker_size = sfTexture_getSize(
        weapon_crosshair->ttr_icemaker_crosshair);
    sfSprite_setOrigin(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){ttr_icemaker_size.x / 3, ttr_icemaker_size.y});
    sfSprite_setPosition(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){(float)position.x / 2, ((float)position.y / 2) + 75});
    sfSprite_setScale(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){ICEMAKER_WEAPON_CROSSHAIR_SCALE});
}

void set_leg_weapon_crosshair(weapon_crosshair_t *weapon_crosshair,
    sfVector2u position)
{
    sfVector2u ttr_leg_size = {0};

    sfSprite_setTexture(weapon_crosshair->weapon_crosshair_sprite,
        weapon_crosshair->ttr_leg_crosshair, sfTrue);
    ttr_leg_size = sfTexture_getSize(
        weapon_crosshair->ttr_icemaker_crosshair);
    sfSprite_setOrigin(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){ttr_leg_size.x / 3, ttr_leg_size.y});
    sfSprite_setPosition(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){(float)position.x / 2, ((float)position.y / 2) + 75});
    sfSprite_setScale(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){LEG_WEAPON_CROSSHAIR_SCALE});
}

void set_secondary_weapon_crosshair(weapon_crosshair_t *weapon_crosshair,
    sfVector2u position)
{
    sfVector2u ttr_secondary_size = {0};

    sfSprite_setTexture(weapon_crosshair->weapon_crosshair_sprite,
        weapon_crosshair->ttr_secondary_crosshair, sfTrue);
    ttr_secondary_size = sfTexture_getSize(
        weapon_crosshair->ttr_icemaker_crosshair);
    sfSprite_setOrigin(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){ttr_secondary_size.x / 3, ttr_secondary_size.y});
    sfSprite_setPosition(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){(float)position.x / 2, ((float)position.y / 2) + 75});
    sfSprite_setScale(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){SECONDARY_WEAPON_CROSSHAIR_SCALE});
}

void set_primary_weapon_crosshair(weapon_crosshair_t *weapon_crosshair,
    sfVector2u position)
{
    sfVector2u ttr_primary_size = {0};

    sfSprite_setTexture(weapon_crosshair->weapon_crosshair_sprite,
        weapon_crosshair->ttr_main_crosshair, sfTrue);
    ttr_primary_size = sfTexture_getSize(
        weapon_crosshair->ttr_icemaker_crosshair);
    sfSprite_setOrigin(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){ttr_primary_size.x / 3, ttr_primary_size.y});
    sfSprite_setPosition(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){(float)position.x / 2, ((float)position.y / 2) + 75});
    sfSprite_setScale(weapon_crosshair->weapon_crosshair_sprite,
        (sfVector2f){MAIN_WEAPON_CROSSHAIR_SCALE});
}
